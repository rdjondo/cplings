# Hint

Concurrent unprotected writes to the same variable is a data race:

- CWE-362: Concurrent Execution using Shared Resource with Improper Synchronization

The struct already has a `std::mutex`. Hold it for the duration of the
increment. Look up `std::lock_guard` for a scoped way to lock and unlock.
