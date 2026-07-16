# Hint

The `?` placeholders are the template parameter. Replace `typename ?` with a
real type parameter name (e.g. `typename T`) on both `Animal` and `Cat`, and use
that name where the `?` and `int` members appear.

`Cat` derives from `Animal`, so it must forward its type argument to the base:
`Cat : public Animal<T>` and `Animal<T>(years)` in the constructor. Class
template argument deduction then lets `Cat blue(4)` deduce the type from the
constructor argument.
