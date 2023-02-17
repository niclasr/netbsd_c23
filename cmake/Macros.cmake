
macro(c23_test name)
add_executable(test_${name} tests/test_${name}.c)
target_link_libraries(test_${name} c23 m m23)
endmacro()
