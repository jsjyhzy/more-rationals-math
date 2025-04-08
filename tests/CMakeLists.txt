add_executable(test_sqrt test_sqrt.cpp)
target_link_libraries(test_sqrt more_rationals_math)
target_include_directories(test_sqrt PUBLIC ${PROJECT_SOURCE_DIR}/more_rationals_math)
target_include_directories(test_sqrt PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_test(
    NAME
        test_sqrt_1
    COMMAND
        $<TARGET_FILE:test_sqrt> 1
)
add_test(
    NAME
        test_sqrt_2
    COMMAND
        $<TARGET_FILE:test_sqrt> 2
)
add_test(
    NAME
        test_sqrt_100
    COMMAND
        $<TARGET_FILE:test_sqrt> 100
)