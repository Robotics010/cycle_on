add_executable(
    config_test
    config_test.cc
)

target_link_libraries(
    config_test PRIVATE
    config
    config_json
    GTest::gtest_main
    Boost::filesystem
)

gtest_discover_tests(
    config_test
    )

file(
    COPY ${CMAKE_CURRENT_SOURCE_DIR}/../data/config_test.json
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
