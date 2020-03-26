#include "spin_tas.hpp"
void Spin_lock_tas::lock(){
	uint32_t expected(0);
	do{
		expected = 0;
	} while(!spin_.compare_exchange_weak(expected, 1));
}

void Spin_lock_tas::unlock(){
	uint32_t desired(0);
	spin_.store(desired, std::memory_order_seq_cst);
}