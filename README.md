# Multithreading_Programming_DATI
Multythreading programming course at MIPT by @Acronis
## CAS LIST
Program creates single connected list with ability to add elements to the forward position(like `push()` in stack) and to any positions in a list. There is iterator `for_each()` to pass through list elements too. This program is designed to be used in multithread programming. It adds elements to a list *atomically* with the help of primitive `atomic_compare_exchange_weak()` in C11 language. 