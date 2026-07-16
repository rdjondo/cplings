# Hint

`fill_vec` uses `vec->push_back(...)`, so it expects a pointer, not a value.
Change its parameter type to a raw pointer `std::vector<int>*` so it borrows
the vector without owning it (it must not delete it).

`vec` is a `std::unique_ptr`. Look up the member that hands out the raw
underlying pointer without giving up ownership, and pass that to `fill_vec`.
