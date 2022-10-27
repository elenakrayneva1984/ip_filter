#include <gtest/gtest.h>
#include "../ip_filter.h"

TEST(IpFilterTestMask, IpFilterTest){
    vv_string ip_input;
    ip_input.push_back(split("1.25.46.1",'.'));
    ip_input.push_back(split("2.1.46.1",'.'));
    ip_input.push_back(split("1.125.146.11",'.'));
    ip_input.push_back(split("1.1.46.1",'.'));
    ip_input.push_back(split("11.205.2.1",'.'));
    ip_input.push_back(split("1.6.5.1",'.'));
    ip_input.push_back(split("1.1.1.1",'.'));
    ip_input.push_back(split("21.225.246.21",'.'));
    ip_input.push_back(split("31.31.46.1",'.'));
    ip_input.push_back(split("1.222.3.21",'.'));

    vv_string ip_test_ok;
    ip_test_ok.push_back(split("1.25.46.1",'.'));
    ip_test_ok.push_back(split("1.125.146.11",'.'));
    ip_test_ok.push_back(split("1.1.46.1",'.'));
    ip_test_ok.push_back(split("1.6.5.1",'.'));
    ip_test_ok.push_back(split("1.1.1.1",'.'));
    ip_test_ok.push_back(split("1.222.3.21",'.'));

    auto ip_output = ip_manager::filter(ip_input,"1.*.*.*", false);
    EXPECT_EQ(ip_test_ok,ip_output);
}

TEST(IpFilterTestAny, IpFilterTest){
    vv_string ip_input;
    ip_input.push_back(split("1.25.46.1",'.'));
    ip_input.push_back(split("2.1.46.1",'.'));
    ip_input.push_back(split("1.125.146.11",'.'));
    ip_input.push_back(split("1.1.46.1",'.'));
    ip_input.push_back(split("11.205.2.1",'.'));
    ip_input.push_back(split("46.6.5.1",'.'));
    ip_input.push_back(split("1.1.1.1",'.'));
    ip_input.push_back(split("21.225.246.21",'.'));
    ip_input.push_back(split("31.31.46.1",'.'));
    ip_input.push_back(split("1.222.3.21",'.'));

    vv_string ip_test_ok;
    ip_test_ok.push_back(split("1.25.46.1",'.'));
    ip_test_ok.push_back(split("2.1.46.1",'.'));
    ip_test_ok.push_back(split("1.1.46.1",'.'));
    ip_test_ok.push_back(split("46.6.5.1",'.'));
    ip_test_ok.push_back(split("31.31.46.1",'.'));

    auto ip_output = ip_manager::filter(ip_input,"46.*.*.*", true);
    EXPECT_EQ(ip_test_ok,ip_output);
}