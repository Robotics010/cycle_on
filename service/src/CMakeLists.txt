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
