foreach(operator_to_test test_sqrt test_sin test_cos test_tan test_arccos test_arctan)
    add_executable(${operator_to_test} ${operator_to_test}.cpp)
    target_link_libraries(${operator_to_test} more_rationals_math)
    target_include_directories(${operator_to_test} PUBLIC ${PROJECT_SOURCE_DIR}/more_rationals_math)
    target_include_directories(${operator_to_test} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    
    add_test(
        NAME
            ${operator_to_test}_1
        COMMAND
            $<TARGET_FILE:${operator_to_test}> 1
    )
endforeach()
