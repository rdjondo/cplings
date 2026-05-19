# Hint

`decltype(val)` gives the type of `val` including `const` and `&`.
`std::decay_t` strips those qualifiers to get the plain stored type:

```cpp
using T = std::decay_t<decltype(val)>;
```

Then compare with `std::is_same_v`:

```cpp
if constexpr (std::is_same_v<T, int>)              // branch for int
else if constexpr (std::is_same_v<T, std::string>) // branch for string
```

`if constexpr` ensures each branch is only compiled when the condition is true,
so you can safely write type-specific code without it failing for other alternatives.
