#include <cassert>
#include "ip_filter.h"
using namespace ip_manager;

int main(int, char **)
{
    try
    {
        vv_string ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            auto v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }

        // TODO reverse lexicographically sort
        {
            lexicograph_sort(ip_pool);
            print_vector_vs(ip_pool, '.');
        }

        {
           auto ip = filter(ip_pool, "1.*.*.*", false);
           print_vector_vs(ip, '.');
        }

        {
           auto ip = filter(ip_pool, "46.70.*.*", false);
           print_vector_vs(ip, '.');
        }

        {
            auto ip = filter(ip_pool, "46.*.*.*", true);
            print_vector_vs(ip, '.');
        }

    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
