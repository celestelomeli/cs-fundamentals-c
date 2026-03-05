# Memory Experiments

Understanding how C manages memory, addresses, pointers, arrays, and structs.


## Files

### Pointers

**`pointers_basics.c`**
- `&` operator (address-of)
- `*` operator (dereference)
- Pointer declaration and modification

**`pointers_swap.c`**
- Functions need pointers to modify caller's variables
- Pass-by-pointer pattern

**`pointers_experiment.c`**
- Pass-by-value vs pass-by-pointer comparison
- Copies don't work (different addresses)


### Arrays

**`arrays.c`**
- Array name is a pointer to first element
- Elements stored consecutively 
- Passing arrays to functions

**`arrays_simple.c`**
- Simplified array-to-function example
- Focus on practical usage


### Structs

**`structs.c`**
- Group related data together
- `.` for direct access
- `->` for pointer access
- Passing structs to functions

**`structs_simple.c`**
- How pointers to structs work
- Type + address = access to all members


## Compilation

```bash
gcc filename.c -o output_name
./output_name
```


## Key Takeaways

1. **Pointers store addresses** - Use `&` to get address, `*` to dereference
2. **Functions need pointers** - To modify caller's variables
3. **Arrays are pointers** - Array name points to first element
4. **Structs group data** - Use `.` or `->` to access members
5. **Pass by pointer is efficient** - Avoids copying large data
