#include "spin_tas.hpp"
#include <vector>
#include <thread>
#include <iostream>

Spin_lock_tas m_lock;

void Count_to_1000(int id){
	// Spin_lock_tas m_lock;
	m_lock.lock();
	std::cout << "Thread " << id << " came to job" << std::endl;
	for (volatile int i(0); i < 100000000; ++i) {}  
	std::cout << "Thread " << id << " finished job" << std::endl;
	m_lock.unlock();
}

int main()
{
	std::vector<std::thread> threads;
	std::cout << "spawning 10 threads that count to 1 million...\n";
	for (int i(0); i <= 10; ++i)
		threads.push_back(std::thread(Count_to_1000, i));
  	for (auto& th : threads)
  		th.join();


	return 0;
}