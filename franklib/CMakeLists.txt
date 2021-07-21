find_package (Python3 COMPONENTS Development)

add_library(franklib STATIC franklib.cpp Base.cpp)
# since we use python type variables in out code we need to add additional includes
target_include_directories(franklib PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${Python3_INCLUDE_DIRS} ${PYBIND11_INCLUDE_DIR})
target_link_libraries(franklib PRIVATE ${Python3_LIBRARIES})