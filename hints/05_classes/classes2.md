# Hint

Several holes to fill in this one:

- `operator==` compares two points. Mirror the `x` comparison for `y`: take the
  absolute difference and check it is below the tolerance `1e-6`.
- `point_zero` is a `Point`, so it needs a brace-initialised value for its two
  coordinates.

Look at how the `x` half of the comparison is written and follow the same shape.
