# Hint

Reading `data_ready` in a loop without sleeping wastes CPU, and reading it
without the lock is a data race (CWE-362). A `std::condition_variable` lets the
consumer release the lock and sleep until the producer notifies it.

Look up the `wait` overload that takes a predicate: it re-checks the condition
under the lock and so is safe against spurious wake-ups.
