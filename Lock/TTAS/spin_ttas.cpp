#include "spin_ttas.hpp"
#include <iostream>
void Spin_lock_tas::lock(){
	uint32_t expected(0);
	do
	{
		/* First test the lock without invalidating
            any cache lines */
		while(spin_.load());
			std::this_thread::yield();
		expected = 0;
	}while(!spin_.compare_exchange_weak(expected, 1));
}

void Spin_lock_tas::unlock(){
	uint32_t desired(0);
	spin_.store(desired, std::memory_order_seq_cst);
}


//  144,57s user 0,14s system 365% cpu 39,629 total
//  48,76s user 95,64s system 345% cpu 41,801 total -- yield