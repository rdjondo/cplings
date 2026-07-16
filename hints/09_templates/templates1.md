# Hint

`max` currently only accepts `int`. To let the same function work for both
`int` and `double`, turn it into a function template.

Put `template<typename T>` in front of the function and replace the concrete
`int` types (parameters and return) with `T`. The compiler then stamps out one
version per type you call it with.
