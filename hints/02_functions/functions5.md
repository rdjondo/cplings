# Hint

Two things are broken:

- `is_even` is declared `constexpr void` but returns a `bool`. Give it the
  return type that matches the value it computes.
- The lambda takes no parameters (`[]()`) yet its body uses `price`. A lambda
  needs its inputs declared in the parameter list, just like a normal function.
