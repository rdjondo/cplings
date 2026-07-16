# Hint

`max` only takes a `std::vector<int>`. Make it a template so it also accepts a
`std::vector<double>`.

Template the element type: `template<typename T>` and take a
`const std::vector<T>&`. The local maximum and the return type should be `T`
too, so nothing is truncated back to `int`.
