# Hint

Here the resource count is tracked by an `std::unordered_set` keyed on the
resource name. The constructor should register the resource and the
destructor should remove it.

Look at the two `resources. ...;` lines: the constructor needs `insert`
(add the name) and the destructor needs `erase` (remove it). Because a set
holds each key only once, opening the same name twice does not grow the count.
