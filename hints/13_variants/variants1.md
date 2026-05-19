# Hint

Use the type name directly as the template argument:

- `std::get<int>(v)` — extracts the `int`
- `std::get<std::string>(v)` — extracts the `std::string`
- `std::holds_alternative<double>(v)` — checks whether `v` currently holds a `double`
