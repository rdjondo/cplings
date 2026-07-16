
# Threads
Here, you'll learn the basics of running code concurrently and sharing data safely between threads.

## Reference

+ Back to Basics: Concurrency - Arthur O'Dwyer - CppCon 2020
https://www.youtube.com/watch?v=F6Ipn7gCOsY

+ cppreference thread support library
https://en.cppreference.com/w/cpp/thread


## Some conventions

### std::thread
- Runs a callable on its own thread of execution.
- Must be `join()`ed or `detach()`ed before it is destroyed, otherwise the program calls `std::terminate`.

### Sharing data
- Two threads touching the same non-const data, where at least one writes, is a data race (CWE-362).
- Protect shared data with a `std::mutex` (via `std::lock_guard` / `std::unique_lock`), or use a `std::atomic` for a single value.

### Passing results back
- `std::promise` / `std::future` carry a value (or exception) from a worker thread to the caller.
- `std::condition_variable` lets a thread sleep until another thread signals that some condition became true. Always re-check the condition under the lock to guard against spurious wake-ups.
