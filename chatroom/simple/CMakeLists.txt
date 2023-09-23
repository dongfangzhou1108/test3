include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/3rdparty/evpp)

add_executable(example_chatroom_simple_server server.cc codec.h)
target_link_libraries(example_chatroom_simple_server evpp_static)

add_executable(example_chatroom_simple_client client.cc codec.h)
target_link_libraries(example_chatroom_simple_client evpp_static)
