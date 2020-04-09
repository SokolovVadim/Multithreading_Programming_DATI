#include <iostream>
#include <thread>
#include <vector>
#include <semaphore.h>

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
	sem_init(&rentry, 0, 1);
	sem_init(&resource, 0, 1);
	sem_init(&queue, 0, 1);

	std::vector<std::thread> threads(2 * THREAD_NUM);

	for(int i(0); i < THREAD_NUM; ++i)
		threads[i] = std::thread(reader, i);

	for(int i(THREAD_NUM); i < 2 * THREAD_NUM; ++i)
		threads[i] = std::thread(writer, i);

 	for (auto& th : threads) {
        th.join();
    }

	sem_destroy(&rentry);
	sem_destroy(&resource);
	sem_destroy(&queue);

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
