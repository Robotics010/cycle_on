add_executable(
    tcp_client_test
    tcp_client_test.cc
)

target_link_libraries(
    tcp_client_test PRIVATE
    tcp_common
    tcp_client
    GTest::gtest_main
)

# add_executable(
#     tcp_test
#     tcp_test.cc
# )

# target_link_libraries(
#     tcp_test PRIVATE
#     tcp_common
#     tcp_server
#     tcp_client
#     GTest::gtest_main
# )

gtest_discover_tests(
    tcp_client_test
    # tcp_test
    )
