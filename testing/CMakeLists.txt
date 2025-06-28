file(GLOB TEST_SOURCES test_*.cpp)

add_executable(testing ${TEST_SOURCES})
target_link_libraries(testing PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(testing)
