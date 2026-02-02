# Push Swap

A sorting algorithm project that sorts data on a stack using a limited set of instructions and the smallest number of actions possible.

## Project Overview

**push_swap** is a challenging algorithm project from the 42 Network curriculum that requires students to sort a stack of integers using only two stacks and a specific set of operations. The goal is to sort the numbers in ascending order using the minimum number of moves possible.


## Objective

Sort a stack of random integers in ascending order using two stacks (A and B) and a limited set of operations, while minimizing the total number of operations used.

## Rules

- You start with stack A containing random integers (positive and/or negative, no duplicates)
- Stack B is empty at the start
- The goal is to sort stack A in ascending order (smallest number on top)
- You can only use the allowed operations listed below

## Operations

### Swap Operations
- `sa` - Swap the first two elements at the top of stack A
- `sb` - Swap the first two elements at the top of stack B  
- `ss` - Execute `sa` and `sb` simultaneously

### Push Operations
- `pa` - Take the first element from stack B and put it on top of stack A
- `pb` - Take the first element from stack A and put it on top of stack B

### Rotate Operations
- `ra` - Shift all elements of stack A up by one (first element becomes last)
- `rb` - Shift all elements of stack B up by one (first element becomes last)
- `rr` - Execute `ra` and `rb` simultaneously

### Reverse Rotate Operations
- `rra` - Shift all elements of stack A down by one (last element becomes first)
- `rrb` - Shift all elements of stack B down by one (last element becomes first)
- `rrr` - Execute `rra` and `rrb` simultaneously

## Algorithm

This implementation uses a **hybrid sorting approach**:

### Small Stack Sorting (2-5 elements)
For stacks with 5 or fewer elements, optimized algorithms are used:

- **2 elements**: Single swap if needed
- **3 elements**: Hardcoded optimal solution (max 2 operations)
- **4-5 elements**: Move minimum to B, sort remaining, push back

### Butterfly Sort (6+ elements)
For larger stacks, a chunk-based sorting algorithm is implemented:

1. **Indexing Phase**: Assign each number a rank/index (0 to n-1)
2. **Push to B Phase**: 
   - Divide numbers into chunks based on their index
   - Push elements to stack B in chunks
   - Elements in lower chunks go to bottom of B (using `rb`)
   - Chunk size: 15 for ≤100 elements, 30 for >100 elements
3. **Push Back to A Phase**:
   - Find the maximum index in stack B
   - Rotate B to bring max to top (using shortest path)
   - Push to A, repeat until B is empty
   - Result: Stack A is sorted in ascending order

### Why This Approach?

- **Efficient for medium datasets**: The butterfly algorithm balances simplicity and performance
- **Chunk optimization**: Dynamic chunk sizing adapts to input size
- **Optimal rotations**: Always uses the shortest rotation path (rotate vs reverse rotate)

## Compilation

```bash
make
```

This will compile the project and create the `push_swap` executable.

### Makefile Rules
```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile from scratch
```

## Usage

### Basic Usage
```bash
./push_swap [numbers...]
```

### Examples
```bash
# Sort 5 random numbers
./push_swap 3 2 5 1 4

# Sort with negative numbers
./push_swap -1 5 -3 0 2

# Sort with quoted string
./push_swap "3 2 1"

# Sort with multiple arguments
./push_swap 9 8 7 "6 5" 4 3 "2 1"
```

### Output
The program outputs the list of operations needed to sort the stack:
```bash
$ ./push_swap 3 2 1
sa
rra
```

### Testing with Checker (if available)
```bash
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker $ARG
```

## Project Structure

```
push_swap/
├── main.c                          # Entry point and main algorithm
├── push_swap.h                     # Header file with structures and prototypes
├── Makefile                        # Compilation rules
│
├── parsing_part/                   # Input validation and parsing
│   ├── input_handle.c             # Parse and validate input arguments
│   ├── help_function.c            # ft_atol with overflow protection
│   ├── ft_split.c                 # Split strings by delimiter
│   ├── ft_split_ft.c              # Helper functions for split
│   └── free_clean.c               # Memory management and cleanup
│
├── operations_part/                # Stack operations implementation
│   ├── linked_list.c              # Doubly linked list utilities
│   ├── ops_swap.c                 # sa, sb, ss operations
│   ├── ops_push.c                 # pa, pb operations
│   ├── ops_rotate.c               # ra, rb, rr operations
│   └── ops_rev_rotate.c           # rra, rrb, rrr operations
│
└── algo_part/                      # Sorting algorithms
    ├── smart_sort.c               # Small stack sorting (2-5 elements)
    ├── sort.c                     # Butterfly sort algorithm
    └── utils.c                    # Helper functions (find min, indexing, etc.)
```

## Performance Benchmarks

The algorithm meets the following performance criteria:

| Stack Size | Max Operations | Grade |
|------------|---------------|-------|
| 3 numbers  | ≤ 3           | ✓     |
| 5 numbers  | ≤ 12          | ✓     |
| 100 numbers| ≤ 700         | 5/5   |
| 100 numbers| ≤ 900         | 4/5   |
| 100 numbers| ≤ 1100        | 3/5   |
| 100 numbers| ≤ 1300        | 2/5   |
| 100 numbers| ≤ 1500        | 1/5   |
| 500 numbers| ≤ 5500        | 5/5   |
| 500 numbers| ≤ 7000        | 4/5   |
| 500 numbers| ≤ 8500        | 3/5   |
| 500 numbers| ≤ 10000       | 2/5   |
| 500 numbers| ≤ 11500       | 1/5   |

### Average Performance (with butterfly algorithm)
- **100 numbers**: ~550-650 operations
- **500 numbers**: ~4500-5500 operations

## Features

✅ **Robust Input Validation**
- Handles multiple argument formats
- Validates integer range (INT_MIN to INT_MAX)
- Detects duplicate numbers
- Proper error handling with "Error\n" output

✅ **Efficient Memory Management**
- Doubly linked list implementation
- Proper cleanup on errors
- No memory leaks

✅ **Optimized Algorithms**
- Hardcoded solutions for small stacks
- Butterfly algorithm for larger datasets
- Smart chunk sizing based on input size

✅ **Clean Code Structure**
- Modular organization by functionality
- Clear separation of concerns
- Norminette compliant (v3)

## Error Handling

The program outputs "Error\n" to stderr and exits in these cases:
- Non-numeric arguments
- Numbers outside INT range (overflow/underflow)
- Duplicate numbers
- Empty arguments
- Memory allocation failures

## Input Formats

The program accepts various input formats:

```bash
# Separate arguments
./push_swap 1 2 3 4 5

# Quoted string
./push_swap "1 2 3 4 5"

# Mixed format
./push_swap 1 "2 3" 4 5

# Multiple quoted strings
./push_swap "1 2" "3 4" "5"
```

## Testing

### Manual Testing
```bash
# Test with 3 numbers
./push_swap 2 1 3

# Test with 5 numbers
./push_swap 5 4 3 2 1

# Count operations for 100 numbers
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l

# Count operations for 500 numbers
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
```

### Automated Testing
```bash
# Generate random test
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test 10 times and get average
for i in {1..10}; do ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l; done
```

### Recommended Testers
- [push_swap_tester](https://github.com/lmalki-h/push_swap_tester)
- [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
- [42_cursus_tester](https://github.com/xicodomingues/francinette)



## Implementation Details

### Data Structure
```c
typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;
```

### Key Functions
- `stack_indices()` - Assigns rank to each number
- `butterfly_sort()` - Main sorting algorithm for large stacks
- `sort_small()` - Optimized sorting for ≤5 elements
- `is_sorted()` - Checks if stack is already sorted

## Learning Outcomes

This project teaches:
- Algorithm optimization and complexity analysis
- Stack data structure manipulation
- Problem-solving with constraints
- Performance benchmarking
- Memory management in C
- Modular code organization

## Resources

- [Visualizer Tool](https://github.com/o-reo/push_swap_visualizer) - Visualize your sorting algorithm
- [Medium Article on Push Swap](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Algorithm Explanation](https://github.com/oceam42/push_swap/wiki)

## License

This project is part of the 42 Network curriculum.

---

Made by **levayy** 