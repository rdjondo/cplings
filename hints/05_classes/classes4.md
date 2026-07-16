# Hint

Virtual dispatch (the vtable) only happens through a reference or a pointer to
the base class, never through a by-value copy. Slicing a `Circle` into a
`Shape` value loses the derived behaviour.

`shape_collection` holds `Shape*`, so every element must be an address, and
each element is accessed as a pointer. Fix the type or the way the elements are
stored and dereferenced so the calls go through the vtable.
