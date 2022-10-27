#ifndef ip_filter_H
#define ip_filter_H

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

#include <cstdlib>
typedef std::vector<std::vector<std::string>> vv_string;
// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d);


void print_vector_vs(vv_string &_v, const char &delit);

namespace ip_manager{
    void lexicograph_sort(vv_string &_ip_pool);
    vv_string filter(const vv_string &pool, const std::string &_mask, const bool &any);
}
#endif // ip_filter_H