# Hint

The float overload body follows the same pattern as the others:

```cpp
void operator()(float v) { result = "flt:" + std::to_string(v); }
```

For `std::visit`, pass the Formatter instance directly as an lvalue.
Because `std::visit` takes the visitor by forwarding reference, mutations to `f.result` are visible after the call:

```cpp
std::visit(f, n);
```
