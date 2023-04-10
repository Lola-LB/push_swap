# Push Swap

## General info
Push_swap is a project written in C that involves sorting data on a stack using a limited set of instructions and with the smallest number of moves.

## Setup
To compile run
```
$ make
```
Push_swap executable takes a list of integers as arguments and then prints out the series of operations required to sort them in ascending order.
```
$ ./push_swap 5 1 3 2 4
```
Checker executable takes a list of integers as arguments and then waits for the user to input a series of operations that are applied to the given list. Once the operations are completed, the program checks if the list is sorted in ascending order.
```
$ ./checker 5 1 3 2 4
```
## Testing:
You can test the push_swap program using the following command:
```
$ ./test/mult_test.sh stack_len nb_of_tests
```
## NB
This project is part of the School 42 curriculum. It has to be written entirely in C and comply with several "norme" rules, including for the code writing.
