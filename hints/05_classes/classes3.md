# Hint

`Circle` derives from `Shape`, but `Shape` has no default constructor that runs
on its own here: the base part must be initialised explicitly. A derived
constructor forwards to its base in the member-initialiser list, before the
body runs.

Look up "constructor initializer list" and how a derived class calls its base
constructor, then pass the incoming centre through to `Shape`.
