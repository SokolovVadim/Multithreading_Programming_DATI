# /bin/bash
all: lock

lock:
	g++ -std=c++11 -Wall rw_lock.cpp test.cpp -o a.out -lpthread
clean:
	/bin/rm -rf *.o *.out
 