##############################################
# Create target and set properties
##############################################

set(VARIABLES_EXERCISES_PATH ".")
set(UNIT_TESTING_LIBRARY Catch2 ${BOOST_LIBS})
set(EXERCISES
  variables1
  variables2
  variables3
  variables4
  variables5
  variables6
  variables7
  variables8
)

foreach(_exercise ${EXERCISES})
  add_executable(${_exercise} ${VARIABLES_EXERCISES_PATH}/${_exercise}.cpp)
  target_include_directories(${_exercise} PRIVATE include)
  # Each exercise is its own executable : link dependencies
  target_link_libraries(${_exercise} ${MYPROJECT_LIBRARIES} ${UNIT_TESTING_LIBRARY} cplings)
  
  # Run test after building executable
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
