
# Security
Here, you'll learn some examples ofsecurity related bugs.

## TODO

+ Variable lifetime (bad examples and compiler)
https://github.com/isocpp/CppCoreGuidelines/blob/master/docs/Lifetime.pdf
Ownership - Find fixes using std::move, std::unique_ptr


## Interesting Security reading
- Why modern C++ won't save us
https://alexgaynor.net/2019/apr/21/modern-c++-wont-save-us/

- An Empirical Study of C++ Vulnerabilities in Crowd-Sourced Code Examples
https://arxiv.org/ftp/arxiv/papers/1910/1910.01321.pdf

- List of common vulnerabilities
https://owasp.org/www-community/vulnerabilities/

- SEI CERT C++ Coding Standard 
https://wiki.sei.cmu.edu/confluence/pages/viewpage.action?pageId=88046682


### Some Broad categories of Security issues

* Include security issues introduced by string_view and span


https://cwe.mitre.org/data/definitions/659.html


Data Processing:
* CWE-119 Improper Restriction of Operations within the Bounds of a Memory Buffer and its subcategories (buffer overflow)
* CWE-125 Out-of-bounds Read
* CWE-787 Out-of-bounds Write
* CWE-129: Improper Validation of Array Index
* CWE-128: Wrap-around Error
* CWE-789: Memory Allocation with Excessive Size Value
* CWE-131: Incorrect Calculation of Buffer Size


Resource management:
* CWE-416:  Use After Free
* CWE-772:  Missing Release of Resource after Effective Lifetime
* CWE-362	Concurrent Execution using Shared Resource with Improper Synchronization ('Race Condition')

Insecure inputs, data or deserialization:
* CWE-20 Improper Input Validation
* CWE-170: Improper Null Termination
* CWE-502:  Deserialization of Untrusted Data
* CWE-704	Incorrect Type Conversion or Cast

Numeric-related:
* CWE-190 Integer Overflow or Wraparound
* CWE-194: Unexpected Sign Extension
* CWE-192: Integer Coercion Error

Pointer:
* CWE-476: NULL Pointer Dereference
