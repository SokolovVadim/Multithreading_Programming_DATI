#include <atomic>
#include <cassert>
#include <thread>

enum THREAD_COMP{
	THREAD_NUMBER = 109,
	ITER_NUMBER   = 200000
};

class Spin_lock_tas{
public:
	Spin_lock_tas():
		spin_(0){};
	~Spin_lock_tas()
	{
		assert(spin_.load() == 0);
	};
	void lock();
	void unlock();
private:
	std::atomic<unsigned int> spin_;
};
