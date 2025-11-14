# compiler-tac-generator
A simple C program that generates Three Address Code (TAC) from arithmetic expressions using stack and operator precedence 

# Three address Code Generator in C
This project implements a Three Address Code (TAC) generator using the C programming language.
It uses stack-based evaluation and operator precedence (Shunting Yard algorithm) to convert arithmetic expressions into TAC form.

# Features
★Generates TAC for arithmetic expressions
Handles operator precedence:
* , / → higher priority
+, - → lower priority

★Uses stacks for operands and operators
Supports expressions like:
a+b*c
a*b+c*d
x+y/z-w

★Automatically creates temporary variables: t1, t2, t3, ...
★Clean and beginner-friendly implementation
★Ideal for Compiler Design Lab 

# Example Input
a+b*c
✔ Output TAC
t1 = b * c
t2 = a + t1
Final result stored in: t2

# How It Works
1. The program reads an arithmetic expression.
2. Operands are pushed to an operand stack.
3. Operators are pushed into an operator stack.
4. Based on precedence, operators are popped and TAC is generated.
5. TAC is constructed using temporary variables (t1, t2, ...).
6. Final temporary holds the full evaluated expression.
