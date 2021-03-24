# Template
Here, you'll learn how to write templates and debugging templates.

## Reference

+ Introduction to templates:
https://github.com/CppCon/CppCon2020/blob/main/Presentations/back_to_basics_templates_part_1/back_to_basics_templates_part_1__andreas_fertig__cppcon_2020.pdf



## Some debugging template ideas

It is often difficult to know which type is breaking a template.
These give a way of finding out more with type version of the template causes problems.

To debug templates, use the keyword __func__ (C++11), or __PRETTY_FUNCTION__ under G++ or VS  __FUNCSIG__
Annotate functions or classes with [[deprecated]] with methods (functions) made constexpr

Use the website 
-	CPPinsights.io. The website generates simpler C++ with templates.
-	build-bench.com
-	metabench

Compilation flags: for timing compilation duration -ftime-report

