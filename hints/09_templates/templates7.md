# Hint

`is_pointer<T>` from the previous exercise gives a compile-time `::value` that
is true when `T` is a pointer. `if constexpr` picks a branch at compile time
based on that value, so the discarded branch does not even need to be valid for
the other type.

Put the trait check inside the `if constexpr ( ... )` condition. Remember the
type of the argument is the template parameter `C`.
