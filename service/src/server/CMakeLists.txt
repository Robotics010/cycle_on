add_library(server OBJECT
            server.cc server.hpp)

target_link_libraries(
    server PRIVATE
    module
    )

target_include_directories(
    server PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
