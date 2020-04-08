#include <iostream>
#include <thread>
#include <semaphore.h>

sem_t resource;
sem_t rentry;

void reader(int i);
void writer(int i);



int main()
{
	printf("Hello\n");

	sem_init(&rentry, 0, 1);

	std::thread thread_reader(reader, 1);
	std::thread thread_writer(writer, 1);



	thread_reader.join();
	thread_writer.join();

	sem_destroy(&rentry);

	return 0;
}


void reader(int i)
{
	sem_wait(&rentry);

	std::cout << "reader entered\n";
	std::this_thread::sleep_for (std::chrono::seconds(2));

	sem_post(&rentry);
	
}

void writer(int i)
{
	sem_wait(&rentry);

	std::cout << "writer entered\n";

	std::this_thread::sleep_for (std::chrono::seconds(2));

	sem_post(&rentry);
	
}
