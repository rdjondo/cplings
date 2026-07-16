# Hint

`HolderBox` is a raw `Holder*`, and `&h` takes the address of a local that is
destroyed at the end of each loop iteration, so the vector ends up full of
dangling pointers (CWE-416: Use After Free).

Redefine `HolderBox` as a `std::unique_ptr<Holder>` so the vector owns each
`Holder`, and create it with `std::make_unique<Holder>(s)` instead of `&h`.
The owning pointer keeps the resource alive and releases it exactly once.
