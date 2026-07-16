# Hint

`fill_vec` takes its vector **by value**, so it modifies a copy and the caller's
`vec` never sees the three `push_back`s. The test expects the original to grow
to 5 elements.

Following the ownership conventions in the chapter README, borrowing a variable
to modify it in place is done with a reference: change the parameter type so
`fill_vec` operates on the caller's vector directly.
