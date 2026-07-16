# Hint

The code assigns at sparse, non-contiguous indices (0, 50, 100, 150, 200) and
then iterates only over the elements that were actually set. A plain array or
`std::vector` would need every slot up to 200.

A key-to-value associative container fits: look at `std::map<int, int>` (or
`std::unordered_map`). Its header is what belongs in the `#include <?>` line.
