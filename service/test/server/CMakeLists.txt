add_executable(
    server_test
    server_test.cc
)

target_link_libraries(
    server_test PRIVATE
    server
    fake
    GTest::gtest_main
)

gtest_discover_tests(server_test)
