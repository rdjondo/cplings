# Hint

RAII means a resource acquired in the constructor is released in the
destructor. `Holder` allocates an `ExpensiveResource` with `new`, so its
destructor must `delete` it, otherwise the count never returns to zero
(a leak, CWE-401).

The destructor is declared but has no name or body. Give it the class name
(`~Holder`) and release the resource inside it.
