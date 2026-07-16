# Hint

Now the container itself varies: a `std::vector<int>` and a
`std::deque<double>`. One template type parameter for the element is not
enough.

Template on the whole container type instead, e.g. `template<typename Container>`
taking `const Container&`. Return `auto` so the element type is deduced from
whatever the container holds.
