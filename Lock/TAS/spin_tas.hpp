#include <atomic>
#include <cassert>

enum THREAD_COMP{
	THREAD_NUMBER = 64,
	ITER_NUMBER   = 1000000
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