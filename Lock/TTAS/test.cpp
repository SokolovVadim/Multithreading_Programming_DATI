#include "spin_ttas.hpp"
#include <vector>
#include <iostream>

Spin_lock_tas m_lock;

void Count_to_mln(int id){
	// Spin_lock_tas m_lock;
	m_lock.lock();
	std::cout << "Thread " << id << " came to job" << std::endl;
	fflush(stdout);

	for (volatile int i(0); i < ITER_NUMBER; ++i) {}  

	std::cout << "Thread " << id << " finished job" << std::endl;
	fflush(stdout);
	m_lock.unlock();
}

int main()
{
	std::vector<std::thread> threads;
	std::cout << "spawning " << THREAD_NUMBER << " threads that count to 1 million...\n";
	for (int i(0); i <= THREAD_NUMBER; ++i)
		threads.push_back(std::thread(Count_to_mln, i));
  	for (auto& th : threads)
  		th.join();


	return 0;
}