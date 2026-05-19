# Hint

`std::get_if` takes a pointer to the variant, not a reference:

```cpp
std::get_if<int>(&v)   // ✅ correct
std::get_if<int>(v)    // ❌ won't compile
```

The return value is a pointer. To call `.empty()` on the string pointer `s`, use:

```cpp
s->empty()   // equivalent to (*s).empty()
```
