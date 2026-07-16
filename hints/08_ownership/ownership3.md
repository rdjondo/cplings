# Hint

`holder_list` holds `std::unique_ptr<Holder>` (a `HolderBox`), and a
`unique_ptr` cannot be copied, only moved. `push_data` receives `hold_ptr` by
value, so it already owns a `unique_ptr` it must hand into the vector.

Look up `std::move`: `push_back` needs the argument moved in, not copied.
Changing only that one line makes it compile.
