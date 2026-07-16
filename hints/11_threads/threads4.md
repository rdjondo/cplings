# Hint

A `std::promise` is the writing end, its `std::future` is the reading end.
The worker already computed the value; look up how to publish it through the
promise so that `result_future.get()`, which blocks until the value arrives,
can read it.
