#include <iostream>
#include <thread>
#include <vector>
#include <semaphore.h>

#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

enum { THREAD_NUM = 5 };

sem_t resource;
sem_t rentry;
sem_t queue;

int shared_data(0);
int rcount(0);

void reader(int i);
void writer(int i);

int main()
{
	if(sem_init(&rentry,   0, 1) == -1)
		handle_error("sem_init");
	if(sem_init(&resource,   0, 1) == -1)
		handle_error("sem_init");
	if(sem_init(&queue,   0, 1) == -1)
		handle_error("sem_init");

	std::vector<std::thread> threads(2 * THREAD_NUM);

	for(int i(0); i < THREAD_NUM; ++i)
		threads[i] = std::thread(reader, i);

	for(int i(THREAD_NUM); i < 2 * THREAD_NUM; ++i)
		threads[i] = std::thread(writer, i);

 	for (auto& th : threads) {
        th.join();
    }

     if(sem_destroy(&rentry) == -1)
    	handle_error("sem_destroy");
	if(sem_destroy(&resource) == -1)
    	handle_error("sem_destroy");
    if(sem_destroy(&queue) == -1)
    	handle_error("sem_destroy");

	return 0;
}


void reader(int i)
{
	sem_wait(&queue);
	sem_wait(&rentry);
	if(++rcount == 1)
		sem_wait(&resource);

	sem_post(&rentry);
	sem_post(&queue);

	printf("reader %d is reading data = %d\n", i, shared_data);

	sem_wait(&rentry);

	if(--rcount == 0)
		sem_post(&resource);

	sem_post(&rentry);
	
}

void writer(int i)
{
	sem_wait(&queue);
	sem_wait(&resource);
	sem_post(&queue);

    shared_data += i * 10;
    printf("writer %d is writing data = %d\n", i, shared_data);

	sem_post(&resource);
}
