
# Ownership
Here, you'll learn how to some ways of handling data lifetime and ownership.


## Some lifetime and ownership conventions
How Ownership Works - from std::move to std::unique_ptr
(Back to Basics: Smart Pointers - Rainer Grimm - CppCon 2020)[https://www.youtube.com/watch?v=sQCSX7vmmKY]

### func(value)
value is:
- Independent owner of the resource
- Delete the resource automatically at the end of func

### func(pointer *)
pointer is:
- Borrowing resource
- Resource is not expected to be empty
- Must not delete the resource 

### func(reference &)
pointer is:
- Borrowing resource
- Resource is not empty
- Must not delete the resource 

### func(std::unique_ptr)
pointer is:
- An independent owner of the resource
- Delete the resource automatically at the end of func

### func(std::shared_ptr)
pointer is:
- A shared owner of the resource
- May delete the resource 


