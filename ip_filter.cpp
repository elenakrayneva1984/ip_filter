#include "ip_filter.h"

using namespace ip_manager;

ip split(const std::string &str, char d)
{
    ip r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    std::string::size_type del_ip = str.find_first_of('.');
    const std::string str_ip = str.substr(start, stop - start);

    auto i = 0;
    while(del_ip != std::string::npos and (i<r.size()-1))
    {
        r[i] = std::stoi(str_ip.substr(start, del_ip - start));
        i++;
        start = del_ip + 1;
        del_ip = str.find_first_of('.', start);
    }

    r[size_ip-1] = std::stoi(str_ip.substr(start));

    return r;
}

void print_vector_vs(vector_ip &_v, const char &delit){
    auto print_elem = [&](auto const i) {
        std::cout << i << delit;
    };
    auto print_str = [&](auto const e) {
        std::for_each(e.begin(), std::prev(e.end()), print_elem );
        std::cout << e.back()<<std::endl; 
    };
    std::for_each(std::cbegin(_v), std::cend(_v), print_str);
}

#define cond_any (std::find(e.begin(),e.end(),mask[i])==e.end())
#define cond_hard (mask[i]!=e[i])

vector_ip ip_manager::filter(const vector_ip &pool, const ip mask, const bool &any){
    vector_ip filter_vector;
    auto compare_mask ([&] (const ip &e) {
                for(auto i = 0; i < mask.size(); i++){
                    if((mask[i] != -1) and (any? cond_any:cond_hard))
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

void ip_manager::lexicograph_sort(vector_ip &_ip_pool){
    std::sort(_ip_pool.begin(), _ip_pool.end(), [](const ip& lhs, const ip& rhs)
    {
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), [](int a, int b)
            {
                return a > b;
            });
    });
}