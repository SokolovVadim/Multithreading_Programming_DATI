#include <iostream>
#include <thread>
#include "rw_lock.hpp"

int main()
{

	printf("Hello\n");
	reader();
	writer();

	std::thread thread_1(reader);



	thread_1.join();


	return 0;
}