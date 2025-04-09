set(CMAKE_CXX_STANDARD 11)

find_library(gmp gmp)

file(GLOB functors ${CMAKE_CURRENT_SOURCE_DIR}/*_function.cpp)

add_library(more_rationals_math)
target_sources(more_rationals_math
    PRIVATE
        ${functors}
        ${CMAKE_CURRENT_SOURCE_DIR}/auxiliary.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/auxiliary.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/debugger.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/mathematical_constant.cpp
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/more_rationals_math.h
)
set_target_properties(more_rationals_math PROPERTIES PUBLIC_HEADER "more_rationals_math.h")

target_link_libraries(more_rationals_math gmp)

install(TARGETS more_rationals_math
    PUBLIC_HEADER   DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    LIBRARY         DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE         DESTINATION ${CMAKE_INSTALL_LIBDIR}
)