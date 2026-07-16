# Hint

The test inserts the same value `42` several times but expects the final size
to be `1`: duplicates must collapse into a single element.

That is the job of a set. Look at `std::unordered_set<int>` (or `std::set<int>`)
and use its `insert` member instead of index assignment.
