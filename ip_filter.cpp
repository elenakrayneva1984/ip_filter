#include "ip_filter.h"

using namespace ip_manager;
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

void print_vector_vs(vv_string &_v, const char &delit){
    auto print_elem = [&](auto const s) {
        std::cout << s << delit;
    };
    auto print_str = [&](auto const e) {
        std::for_each(e.begin(), std::prev(e.end()), print_elem );
        std::cout << e.back()<<std::endl; 
    };
    std::for_each(std::cbegin(_v), std::cend(_v), print_str);
}

#define cond_any (std::find(e.begin(),e.end(),mask_vs[i])==e.end())
#define cond_hard (mask_vs[i]!=e[i])

vv_string ip_manager::filter(const vv_string &pool, const std::string &_mask, const bool &any){
    const auto mask_vs = split(_mask,'.');
    vv_string filter_vector;
    auto compare_mask ([&] (const std::vector<std::string> &e) {
                for(uint16_t i = 0; i < mask_vs.size(); i++){
                    if((mask_vs[i] != "*") and (any? cond_any:cond_hard))
                        return false;
                }
                return true;
            });

    auto it = pool.begin();
    while ((it = std::find_if(it, pool.end(), compare_mask))!= pool.end())
    {
        filter_vector.emplace_back(*it);
        it++;
    }
    return std::move(filter_vector);
}

void ip_manager::lexicograph_sort(vv_string &_ip_pool){
    std::sort(_ip_pool.begin(), _ip_pool.end(), [](const std::vector<std::string>& lhs, const std::vector<std::string>& rhs)
    {
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), [](std::string a, std::string b)
            {
                return std::stoi(a) > std::stoi(b);
            });
    });
}