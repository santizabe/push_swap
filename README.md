# Push_swap

![Language](https://img.shields.io/badge/Language-C-blue)
![School](https://img.shields.io/badge/School-42-black)
![Score](https://img.shields.io/badge/Score-125%2F100-brightgreen)

**Push_swap** is a 42 School algorithm project. The goal is to sort a stack of integers using two stacks (`a` and `b`) and a specific set of instructions, while minimizing the total number of operations.

## Table of Contents
- [About](#about)
- [The Rules](#the-rules)
- [Instruction Set](#instruction-set)
- [Installation](#installation)
- [Usage](#usage)
- [The Algorithm](#the-algorithm)
- [Bonus](#bonus)

## About

The project requires you to input a list of integers as arguments. The program calculates and displays the smallest list of instructions to sort the integers in ascending order in stack `a`.

Key constraints:
1. You have two stacks named `a` and `b`.
2. Stack `a` contains a random amount of non-duplicated negative and/or positive numbers.
3. Stack `b` is initially empty.
4. The goal is to sort the numbers in ascending order in stack `a`.

## The Rules

The program is allowed to use the following operations to manipulate the stacks:

### Instruction Set

| Code  | Instruction | Action |
| :--- | :--- | :--- |
| **sa** | swap a | Swap the first 2 elements at the top of stack `a`. |
| **sb** | swap b | Swap the first 2 elements at the top of stack `b`. |
| **ss** | swap a + b | `sa` and `sb` at the same time. |
| **pa** | push a | Take the first element at the top of `b` and put it at the top of `a`. |
| **pb** | push b | Take the first element at the top of `a` and put it at the top of `b`. |
| **ra** | rotate a | Shift all elements of stack `a` up by 1. The first element becomes the last one. |
| **rb** | rotate b | Shift all elements of stack `b` up by 1. The first element becomes the last one. |
| **rr** | rotate a + b | `ra` and `rb` at the same time. |
| **rra** | reverse rotate a | Shift all elements of stack `a` down by 1. The last element becomes the first one. |
| **rrb** | reverse rotate b | Shift all elements of stack `b` down by 1. The last element becomes the first one. |
| **rrr** | reverse rotate a + b | `rra` and `rrb` at the same time. |

## Installation

1. Clone the repository:
```bash
git clone git@github.com:username/push_swap.git
cd push_swap
```

2. Compile the project:

```bash
make
```

## Usage

Run the program with a list of integers:

```bash
./push_swap 2 1 3 6 5 8
```

Output:

```bash
sa
pb
pb
pb
sa
pa
pa
pa
```

Verifying the result

To verify if the output actually sorts the list, you can pipe it into the checker.

Note: You must compile the bonus first to generate the checker executable.

Compile the bonus:

```bash
make bonus
```

Run the check:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

Should display OK

## The Algorithm

[Option 1: For small sets / Simple Sort]

For 3 arguments, the program uses hard-coded logic to sort instantly with minimal moves.

[Option 2: Turk Algorithm / Cost Analysis]

For larger sets, I implemented a cost-analysis algorithm:

Push almost everything from a to b (leaving 3 elements), pre-sorting them crudely.

Sort the remaining 3 elements in a.

Calculate the "cost" (number of operations) to push every element from b back into its correct position in a.

Execute the move that costs the least amount of operations.

Repeat until b is empty.

Final rotation to ensure the list starts with the smallest number.

## Bonus

The bonus part is the custom checker program itself.

Usage logic:
The checker takes the numbers as arguments, waits for instructions on stdin, and verifies if the stack is sorted.

```bash
make bonus
./checker 3 2 1 0
rra
pb
sa
rra
pa

(Press Ctrl + D to stop input)
```

Result:

OK if the stack is sorted and b is empty.

KO if the stack is not sorted.

Error if inputs are invalid.

Made by Santiago Zapata Bedoya for 42 School.