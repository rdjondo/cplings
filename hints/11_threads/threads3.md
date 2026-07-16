# Hint

For a single counter you do not need a mutex. Look up `std::atomic`: it makes
each `++` indivisible, so no update is lost when many threads increment at
once. Only the type of `counter` needs to change.
