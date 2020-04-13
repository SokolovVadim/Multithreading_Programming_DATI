# Multithreading_Programming_DATI
Multithreading programming course at MIPT by @Acronis
## CAS LIST
Program creates single connected list with ability to add elements to the forward position(like `push_back()` ) and to any positions in a list. There is iterator `for_each()` to pass through list elements. This program is designed to be used in multithread programming. It adds elements to a list *atomically* with the help of primitive `atomic_compare_exchange_weak()` in C11 language. 
## Lock

Simple realization of different locks:
 - Test and set lock
 - Test and test and set lock
 - TTAS lock with exponential backoff
 - TTAS lock with pause
`std::atomic` is used as lock variable

## RW Lock

Posix Semaphore realization of RW lock:
 - Reader preferred lock
 - Writer preferred lock
 - Fair lock

#### Build
```
make read
make write
make fair
```

## Template List

Linked list with Iterator
