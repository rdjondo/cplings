# Hint

A raw C array `int my_sequence[num_elements]` has no `.size()` member and no
`.begin()/.end()`, which is why the test does not compile.

Replace it with the STL container that is a fixed-size array but knows its own
size: `std::array<int, num_elements>`. The rest of the code (indexing and the
range-based for loop) then works unchanged.
