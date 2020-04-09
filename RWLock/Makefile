# /bin/bash
all: reader

reader:
	g++ -std=c++11 -Wall rw_lock_read_pref.cpp -o a.out -lpthread
fair:
	g++ -std=c++11 -Wall rw_lock_fair.cpp -o a.out -lpthread
clean:
	/bin/rm -rf *.o *.out
