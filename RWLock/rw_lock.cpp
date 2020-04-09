#include <iostream>
#include <thread>
#include <semaphore.h>

sem_t resource;
sem_t rentry;

int shared_data(0);
int rcount(0);

void reader(int i);
void writer(int i);



int main()
{
	printf("Hello\n");

	sem_init(&rentry, 0, 1);
	sem_init(&resource, 0, 1);

	std::thread reader1(reader, 1);
	std::thread reader2(reader, 2);
	std::thread writer1(writer, 1);
	std::thread writer2(writer, 2);



	reader1.join();
	reader2.join();
	writer1.join();
	writer2.join();

	sem_destroy(&rentry);
	sem_destroy(&resource);

	return 0;
}


void reader(int i)
{
	sem_wait(&rentry);
	if(++rcount == 1)
		sem_wait(&resource);

	sem_post(&rentry);

	printf("reader %d is reading data = %d\n", i, shared_data);

	sem_wait(&rentry);

	if(--rcount == 0)
		sem_post(&resource);

	sem_post(&rentry);
	
}

void writer(int i)
{
	sem_wait(&resource);

	printf("writer %d is writing\n", i);
    shared_data += i * 10;

	//std::this_thread::sleep_for (std::chrono::seconds(2));

	sem_post(&resource);
	
}
