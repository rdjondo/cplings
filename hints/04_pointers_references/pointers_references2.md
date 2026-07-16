# Hint

The test expects the caller's value to change after `my_reference_content`
returns, but the parameter is passed by value, so the function only edits a
local copy. Line 14 must stay as-is.

Change the parameter that should be modified so it is a reference (`int&`)
instead of a copy. A reference is an alias for the caller's variable.
