# push_swap

Project Title: Push_swap

Description:
Push_swap is a project written in C that involves sorting data on a stack using a limited set of instructions and with the smallest number of moves. To accomplish this, you will need to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

Instructions:
To use the push_swap program, you first need to compile it. This can be done by running the makefile using the following command:

go
Copy code
make
This will generate two executables, "push_swap" and "checker".

Push_swap executable takes a list of integers as arguments and then prints out the series of operations required to sort them in ascending order.

bash
Copy code
./push_swap 5 1 3 2 4
Checker executable takes a list of integers as arguments and then waits for the user to input a series of operations that are applied to the given list. Once the operations are completed, the program checks if the list is sorted in ascending order.

bash
Copy code
./checker 5 1 3 2 4
Project Structure:
The push_swap project contains the following files:

push_swap.c - Main file of the push_swap program.
checker.c - Main file of the checker program.
operations.c - File containing the various stack manipulation operations (swap, push, rotate, reverse rotate).
stack.c - File containing the stack initialization and manipulation functions.
utils.c - File containing various utility functions used by the push_swap program.
Testing:
You can test the push_swap program using the following command:

bash
Copy code
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
This will generate a random list of 100 integers, sort them using the push_swap program and then check if the list is sorted using the checker program.

Conclusion:
The push_swap project is a challenging project that requires you to apply various sorting algorithms and choose the most optimized solution for sorting data on a stack using a limited set of instructions. I hope this README file helps you get started with the project. Good luck!
