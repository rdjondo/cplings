# Hint

Two problems. First, the function can reach its end without returning a value:
every path through the `if` chain must `return` a `std::string`.

Look at the test cases at the bottom for the expected mapping:

- `"fizz"` returns `"foo"`
- `"fuzz"` returns `"bar"`
- anything else returns `"baz"`

Add an `else if` for the `"fuzz"` case and a final `else` (or a trailing
`return`) for the default.
