pybind11_add_module(franklib_bindings franklib_bindings.cpp)
target_link_libraries(franklib_bindings PRIVATE franklib)
#install(TARGETS franklib_bindings DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})
