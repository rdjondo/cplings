# Hint

The function body is empty, so nothing is returned. The constraints rule out
extra variables and helper calls, which points at the conditional (ternary)
operator:

```
condition ? value_if_true : value_if_false
```

Return that single expression, comparing `a` and `b`.
