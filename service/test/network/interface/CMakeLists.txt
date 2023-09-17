add_executable(
    tcp_test
    tcp_test.cc
)

target_link_libraries(
    tcp_test PRIVATE
    # echo
    tcp_common
    tcp_server
    tcp_client
    GTest::gtest_main
)

gtest_discover_tests(
    tcp_test
    )
