# Hint

`my_pointer_value_swap` receives an `int*` but stores it in an `int`. The local
`new_data` must have the same type as what it holds and what the function
returns: a pointer. Fix its type so it can carry the address through.

`my_pointer_content` takes `int * const value`: the pointer itself is const, so
you cannot move where it points. To change the pointed-to number, work through
the dereferenced value (`*value`) rather than the pointer.
