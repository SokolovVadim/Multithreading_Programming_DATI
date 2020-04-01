#include "spin_tas.hpp"
#include <iostream>
void Spin_lock_tas::lock(){
	uint32_t expected(0);
	while(!spin_.compare_exchange_weak(expected, 1))
	{
		expected = 0;
		std::this_thread::yield();
	}
}

void Spin_lock_tas::unlock(){
	uint32_t desired(0);
	spin_.store(desired, std::memory_order_seq_cst);
}

// 141,42s user 0,06s system 385% cpu 36,694 total
// 57,82s user 95,69s system 388% cpu 39,482 total -- yield
