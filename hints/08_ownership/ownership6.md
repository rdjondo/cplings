# Hint

`std::shared_ptr` lets several owners share the same data; `use_count()`
reports how many owners currently exist. The exercise wants an extra
"artificial" owner so the count rises.

The line marked TODO already constructs a second `shared_ptr` from the
argument. Let the compiler deduce the type instead of spelling it out: replace
the explicit datatype so the copy still shares ownership of the same block.
Copying a `shared_ptr` (not moving it) is what bumps `use_count()`.
