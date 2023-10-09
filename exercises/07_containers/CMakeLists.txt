##############################################
# Create target and set properties
##############################################

set(FUNCTIONS_EXERCISES_PATH ".")
set(UNIT_TESTING_LIBRARY Catch2)
set(EXERCISES
  containers1
  containers2
  containers3
)

foreach(_exercise ${EXERCISES})
  add_executable(${_exercise} ${FUNCTIONS_EXERCISES_PATH}/${_exercise}.cpp)
  target_include_directories(${_exercise} PRIVATE include)

  # link dependencies
  target_link_libraries(${_exercise} ${MYPROJECT_LIBRARIES} ${UNIT_TESTING_LIBRARY} cplings)
  add_custom_command(
    TARGET ${_exercise}
    COMMENT "Run Tests"
    DEPENDS ${_exercise}
    COMMAND ${_exercise}
  )
endforeach()

##################################################################################################
# ---- Enable testing ----
# Adding tests is done outside the above loop,
# as each test will need different arguments.
##################################################################################################
# Don't forget its:  add_test(<test name (globally unique) > <exe name> <argument1> <argument2>
##################################################################################################
enable_testing()
