#include <iostream>
#include <string>
#include <thread>
#include <functional>
#include <vector>
#include <List.hpp>

//==========================================================

void test();
void pusher(int id, List<std::string> & list);
void poper(int id);

enum { THREAD_NUM = 4 };

//==========================================================

int main()
{
	// test();


	List<std::string> list;
	std::vector<std::thread> v_thread(THREAD_NUM);
	for(int i(0); i < THREAD_NUM; ++i)
		v_thread[i] = std::thread(pusher, i, std::ref(list));

	
	for(int i(0); i < THREAD_NUM; ++i)
		v_thread[i].join();


	std::cout << std::endl;
	for(Node<std::string> i:list)
		std::cout << i.data << " ";
	


	return 0;
}

//==========================================================

void test()
{

/*	List<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);

	for(Node<int> i:list)
		std::cout << i.data << " ";*/
	
	List<std::string> list;


	list.push_front("Hey!");
	list.push_back("It's");
	list.push_front("Wow!");
	list.push_front("Look!");
	list.push_back("corona");
	list.push_back("time!");
	list.display();

	for(Node<std::string> i:list)
		std::cout << i.data << " ";
	std::cout << std::endl;

	/*list.pop_front();
	list.pop_back();
	list.pop_front();
	list.pop_back();
	list.display();
	list.pop_front();*/

	


/*

	list.push_back("It's");
	list.push_back("corona");
	list.push_back("time!");
	list.display();
	list.push_back("It's");
	list.push_back("corona");
	list.push_back("time");
	list.push_back("right");
	list.push_back("now");
	list.display();
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.display();
	list.push_back("It's");
	list.push_back("corona");
	list.push_back("time");
	list.push_back("right");
	list.push_back("now");
	list.display();
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.display();
	list.pop_back();
	list.pop_back();
	list.display();
	list.pop_back();

*/

}

/*
Switchblades, cocaine
GothBoiClique, make a hoe shake
Black fur, black coat
GothBoiClique in the back, hoe
*/

void pusher(int id, List<std::string> & list)
{
	list.push_back("Switchblades");
	list.push_back("cocaine");
	list.push_back("GothBoiClique");
	list.push_back("make");
	list.push_back("a");
	list.push_back("hoe");
	list.push_back("shake");
	list.push_back("Black");
	list.push_back("fur");
	list.push_back("black");
	list.push_back("coat");
	list.push_back("GothBoiClique");
	list.push_back("in");
	list.push_back("the");
	list.push_back("back");
	list.push_back("hoe");
	list.push_back("Switchblades");
	list.push_back("cocaine");
	list.push_back("GothBoiClique");
	list.push_back("make");
	list.push_back("a");
	list.push_back("hoe");
	list.push_back("shake");
	list.push_back("Black");
	list.push_back("fur");
	list.push_back("black");
	list.push_back("coat");
	list.push_back("GothBoiClique");
	list.push_back("in");
	list.push_back("the");
	list.push_back("back");
	list.push_back("hoe");
	list.push_back("Switchblades");
	list.push_back("cocaine");
	list.push_back("GothBoiClique");
	list.push_back("make");
	list.push_back("a");
	list.push_back("hoe");
	list.push_back("shake");
	list.push_back("Black");
	list.push_back("fur");
	list.push_back("black");
	list.push_back("coat");
	list.push_back("GothBoiClique");
	list.push_back("in");
	list.push_back("the");
	list.push_back("back");
	list.push_back("hoe");
}