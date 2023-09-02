set(BOOST_INCLUDE_LIBRARIES filesystem process asio)
set(BOOST_ENABLE_CMAKE ON)

include(FetchContent)
FetchContent_Declare(
    Boost
    GIT_REPOSITORY https://github.com/boostorg/boost.git
    GIT_TAG boost-1.80.0
)
FetchContent_MakeAvailable(Boost)

add_executable(
  hello_world
  hello_world.cpp
)
target_link_libraries(
  hello_world PRIVATE
  )

  add_subdirectory(config)
  add_subdirectory(server)
add_subdirectory(network/interface/tcp)
  add_subdirectory(runner)
