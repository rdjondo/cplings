# Hint

`Bird` and `Cat` inherit `number_legs` and `has_fur` from `Animal`, so they
should set those inherited members, not declare new ones that shadow them.

- In the `Bird` constructor, `number_legs = ;` is missing its value. A bird has
  two legs.
- `Cat` re-declares `has_fur` (line 41). Delete that duplicate so the
  constructor writes the inherited member instead of a new shadowing one.
