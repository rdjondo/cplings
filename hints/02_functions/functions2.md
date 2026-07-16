# Hint

A function parameter needs both a type and a name. `callme(x)` declares `x`
with no type, which is not valid C++. `x` is later compared against `int i` and
used as a loop bound, so give it the matching type.
