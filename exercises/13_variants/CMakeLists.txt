##############################################
# Create target and set properties
##############################################

set(FUNCTIONS_EXERCISES_PATH ".")
set(UNIT_TESTING_LIBRARY Catch2)
set(EXERCISES
  variants1
  variants2
  variants3
  variants4
)

foreach(_exercise ${EXERCISES})
  add_executable(${_exercise} ${FUNCTIONS_EXERCISES_PATH}/${_exercise}.cpp)
  target_include_directories(${_exercise} PRIVATE include)

  # link dependencies
  target_link_libraries(${_exercise} ${MYPROJECT_LIBRARIES} ${UNIT_TESTING_LIBRARY} cplings)
  add_custom_command(
    POST_BUILD
    TARGET ${_exercise}
    COMMENT "Run Tests"
    COMMAND ${_exercise}
  )
endforeach()

##################################################################################################
# ---- Enable testing ----
##################################################################################################
enable_testing()
