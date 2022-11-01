#include <gtest/gtest.h>
#include "../ip_filter.h"

TEST(IpFilterTestMask, IpFilterTest){
    vector_ip ip_input;
    ip_input.push_back(split("1.25.46.1\t4\t56",'\t'));
    ip_input.push_back(split("2.1.46.1",'\t'));
    ip_input.push_back(split("1.125.146.11",'\t'));
    ip_input.push_back(split("1.1.46.1",'\t'));
    ip_input.push_back(split("11.205.2.1",'\t'));
    ip_input.push_back(split("1.6.5.1",'\t'));
    ip_input.push_back(split("1.1.1.1",'\t'));
    ip_input.push_back(split("21.225.246.21",'\t'));
    ip_input.push_back(split("31.31.46.1",'\t'));
    ip_input.push_back(split("1.222.3.21",'\t'));

    vector_ip ip_test_ok;
    ip_test_ok.push_back(split("1.25.46.1",'\t'));
    ip_test_ok.push_back(split("1.125.146.11",'\t'));
    ip_test_ok.push_back(split("1.1.46.1",'\t'));
    ip_test_ok.push_back(split("1.6.5.1",'\t'));
    ip_test_ok.push_back(split("1.1.1.1",'\t'));
    ip_test_ok.push_back(split("1.222.3.21",'\t'));

    auto ip_output = ip_manager::filter(ip_input,{1,-1,-1,-1}, false);
    EXPECT_EQ(ip_test_ok,ip_output);
}

TEST(IpFilterTestAny, IpFilterTest){
    vector_ip ip_input;
    ip_input.push_back(split("1.25.46.1",'\t'));
    ip_input.push_back(split("2.1.46.1",'\t'));
    ip_input.push_back(split("1.125.146.11\t5\t55",'\t'));
    ip_input.push_back(split("1.1.46.1",'\t'));
    ip_input.push_back(split("11.205.2.1",'\t'));
    ip_input.push_back(split("46.6.5.1\t714\t815",'\t'));
    ip_input.push_back(split("1.1.1.1",'\t'));
    ip_input.push_back(split("21.225.246.21\t99\t99",'\t'));
    ip_input.push_back(split("31.31.46.1",'\t'));
    ip_input.push_back(split("1.222.3.21",'\t'));

    vector_ip ip_test_ok;
    ip_test_ok.push_back(split("1.25.46.1",'\t'));
    ip_test_ok.push_back(split("2.1.46.1",'\t'));
    ip_test_ok.push_back(split("1.1.46.1",'\t'));
    ip_test_ok.push_back(split("46.6.5.1",'\t'));
    ip_test_ok.push_back(split("31.31.46.1",'\t'));

    auto ip_output = ip_manager::filter(ip_input,{46,-1,-1,-1}, true);
    EXPECT_EQ(ip_test_ok,ip_output);
}

TEST(IpFilterTestDoubleMaskHard, IpFilterTest){
    vector_ip ip_input;
    ip_input.push_back(split("1.2.46.1",'\t'));
    ip_input.push_back(split("2.1.46.1",'\t'));
    ip_input.push_back(split("1.125.146.11\t5\t55",'\t'));
    ip_input.push_back(split("1.2.46.1\t55\t22",'\t'));
    ip_input.push_back(split("11.205.2.1",'\t'));
    ip_input.push_back(split("46.2.5.1\t714\t815",'\t'));
    ip_input.push_back(split("1.1.1.1",'\t'));
    ip_input.push_back(split("21.2.246.1\t99\t99",'\t'));
    ip_input.push_back(split("31.2.46.11",'\t'));
    ip_input.push_back(split("1.222.3.21",'\t'));

    vector_ip ip_test_ok;
    ip_test_ok.push_back(split("1.2.46.1",'\t'));
    ip_test_ok.push_back(split("1.2.46.1\t55\t22",'\t'));
    ip_test_ok.push_back(split("46.2.5.1\t714\t815",'\t'));
    ip_test_ok.push_back(split("21.2.246.1\t99\t99",'\t'));

    auto ip_output = ip_manager::filter(ip_input,{-1,2,-1,1}, false);
    EXPECT_EQ(ip_test_ok,ip_output);
}

TEST(IpFilterTestDoubleMaskAny, IpFilterTest){
    vector_ip ip_input;
    ip_input.push_back(split("1.2.46.1",'\t'));
    ip_input.push_back(split("2.1.46.1",'\t'));
    ip_input.push_back(split("1.125.146.11\t5 \t55",'\t'));
    ip_input.push_back(split("1.2.46.1\t55\t22",'\t'));
    ip_input.push_back(split("11.205.2.1",'\t'));
    ip_input.push_back(split("46.2.5.1\t714\t815",'\t'));
    ip_input.push_back(split("1.1.1.1",'\t'));
    ip_input.push_back(split("21.2.246.1\t99\t99",'\t'));
    ip_input.push_back(split("31.2.46.11",'\t'));
    ip_input.push_back(split("1.222.3.21",'\t'));

    vector_ip ip_test_ok;
    ip_test_ok.push_back(split("1.2.46.1",'\t'));
    ip_test_ok.push_back(split("2.1.46.1",'\t'));
    ip_test_ok.push_back(split("1.2.46.1\t55\t22",'\t'));
    ip_test_ok.push_back(split("46.2.5.1\t714\t815",'\t'));
    ip_test_ok.push_back(split("31.2.46.11",'\t'));

    auto ip_output = ip_manager::filter(ip_input,{46,2,-1,-1}, true);
    EXPECT_EQ(ip_test_ok,ip_output);
}