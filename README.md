# ft_split (42 / 1337 Helper)

A clean and well-documented implementation of the `ft_split` function written in C for the **42 Network** and **1337** students.  
This project was created to help new students understand how to implement their own version of `split` (from `libft`) — including memory handling, edge cases, and coding style.

---

## 🧠 Overview

`ft_split` takes a string and splits it into an array of words using a given delimiter character.  
It returns a **NULL-terminated array of strings**, dynamically allocated.

Example:
```c
Input:  "hello world 42", ' '
Output: ["hello", "world", "42", NULL]
