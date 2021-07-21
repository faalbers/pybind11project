#find_package (Python3 COMPONENTS Development)

add_executable(testfranklib testfranklib.cpp)
#target_link_libraries(testfranklib PRIVATE ${Python3_LIBRARIES} franklib)
target_link_libraries(testfranklib PRIVATE franklib)

add_test(TestFrankLib testfranklib)
add_test(NAME TestFrankPy
    COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/testfrank.py $<TARGET_FILE_DIR:franklib_bindings>)
