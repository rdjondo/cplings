# Hint

The return line must add three separate values, but the placeholders are empty.
Look at each scope in play:

- the global `value` (reachable with `::value`)
- the value returned by `called(10)`, stored in the local `value`
- the one inside `my_namespace_0` (reachable with `my_namespace_0::value`)

The expected total is `13`. Work out which value lives in which scope and add
the three named references together.
