# Hint

The goal is to *transfer* ownership of the data out of `vec0` into `vec1`,
leaving `vec0` empty (the test requires `vec0.size() == 0`).

`fill_vec` takes an rvalue reference (`std::vector<int>&&`), so it wants
something it is allowed to steal from. Look up `std::move`: it casts an lvalue
to an rvalue so its contents can be moved rather than copied. The two `...?`
holes each need the value to be moved.
