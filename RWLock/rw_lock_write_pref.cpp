#include <iostream>
#include <thread>
#include <semaphore.h>

sem_t resource;
sem_t rentry;
sem_t rtry;
sem_t wentry;

int shared_data(0);
int rcount(0);
int wcount(0);

void reader(int i);
void writer(int i);

int main()
{
	sem_init(&rentry, 0, 1);
	sem_init(&resource, 0, 1);
	sem_init(&rtry, 0, 1);
	sem_init(&wentry, 0, 1);

	std::thread reader1(reader, 1);
	std::thread reader2(reader, 2);
	std::thread reader3(reader, 3);	
	std::thread reader4(reader, 4);
	std::thread reader5(reader, 5);
	std::thread reader6(reader, 6);

	std::thread writer1(writer, 1);
	std::thread writer2(writer, 2);
	std::thread writer3(writer, 3);
	std::thread writer4(writer, 4);
	std::thread writer5(writer, 5);
	std::thread writer6(writer, 6);


	reader1.join();
	reader2.join();
	reader3.join();
	reader4.join();
	reader5.join();
	reader6.join();

	writer1.join();
	writer2.join();
	writer3.join();
	writer4.join();
	writer5.join();
	writer6.join();

	sem_destroy(&rentry);
	sem_destroy(&resource);
	sem_destroy(&rtry);
	sem_destroy(&wentry);

	return 0;
}


void reader(int i)
{
	sem_wait(&rtry);
	sem_wait(&rentry);
	if(++rcount == 1)
		sem_wait(&resource);

	sem_post(&rentry);
	sem_post(&rtry);

	printf("reader %d is reading data = %d\n", i, shared_data);

	sem_wait(&rentry);

	if(--rcount == 0)
		sem_post(&resource);

	sem_post(&rentry);
	
}

void writer(int i)
{
	sem_wait(&wentry);
	if(++wcount == 1)
		sem_wait(&rtry);
	sem_post(&wentry);

	sem_wait(&resource);

    shared_data += i * 10;
    printf("writer %d is writing data = %d\n", i, shared_data);

	sem_post(&resource);

	sem_wait(&wentry);

	if(--wcount == 0)
		sem_post(&rtry);

	sem_post(&wentry);
	
}
