# Hint

The constructor call is missing its last argument: the object `worker` should
write into. `worker` takes an `int&`, and a thread copies its arguments by
default, so a plain `result` would not be modified. Look up `std::ref` to pass
a reference through.

A thread that is destroyed while still joinable terminates the program, so the
thread must be joined before `result` is read.
