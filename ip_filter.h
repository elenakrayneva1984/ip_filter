#ifndef ip_filter_H
#define ip_filter_H

#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <iostream>

#include <cstdlib>

#define size_ip 4
typedef std::array<int, size_ip> ip;
typedef std::vector<ip> vector_ip;

void print_vector_vs(vector_ip &_v, const char &delit);

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]

ip split(const std::string &str, char d);

namespace ip_manager{
    void lexicograph_sort(vector_ip &_ip_pool);
    vector_ip filter(const vector_ip &pool, const ip mask, const bool &any);
}
#endif // ip_filter_H