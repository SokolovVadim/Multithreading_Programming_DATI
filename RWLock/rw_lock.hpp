#ifndef RW_LOCK_HPP
#define RW_LOCK_HPP

#include <semaphore.h>

sem_t resource;
sem_t rentry;

void reader(int i);
void writer(int i);

#endif // RW_LOCK_HPP 