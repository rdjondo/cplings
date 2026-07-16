# Hint

`is_string` is already written for you: a primary template inheriting from
`false_type`, plus a full specialization for `std::string` inheriting from
`true_type`. Follow the exact same pattern to define `is_vector`.

The difference is that a vector is itself a template, so the "true" case is a
partial specialization that keeps the element type generic:

```cpp
template<typename T> struct is_vector : false_type {};
```

Add the partial specialization that matches `std::vector<T>` for any `T`.
`is_pointer` in the next exercise follows the same idea for `T*`.
