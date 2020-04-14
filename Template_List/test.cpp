#include <iostream>
#include <string>
#include <thread>
#include <functional>
#include <vector>
#include <List.hpp>

//==========================================================

void test();
void test_push_back(int id, List<std::string> & list);
void test_push_front(int id, List<std::string> & list);
void test_range_based_loop(int id, List<std::string> & list);
void pop(int id);

enum { THREAD_NUM = 30 };

//==========================================================

int main()
{
	// test();


	List<std::string> list;
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



	std::vector<std::thread> v_thread(THREAD_NUM);
	for(int i(0); i < THREAD_NUM; ++i)
		v_thread[i] = std::thread(test_range_based_loop, i, std::ref(list));

	
	for(int i(0); i < THREAD_NUM; ++i)
		v_thread[i].join();


/*	std::cout << std::endl;
	for(Node<std::string> i:list)
		std::cout << i.data << " ";*/
	


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

void test_push_back(int id, List<std::string> & list)
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
	list.push_back("hoe\n");
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
	list.push_back("hoe\n");
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
	list.push_back("hoe\n");
}



void test_push_front(int id, List<std::string> & list)
{
	list.push_front("Switchblades");
	list.push_front("cocaine");
	list.push_front("GothBoiClique");
	list.push_front("make");
	list.push_front("a");
	list.push_front("hoe");
	list.push_front("shake");
	list.push_front("Black");
	list.push_front("fur");
	list.push_front("black");
	list.push_front("coat");
	list.push_front("GothBoiClique");
	list.push_front("in");
	list.push_front("the");
	list.push_front("back");
	list.push_front("hoe\n");
	list.push_front("Switchblades");
	list.push_front("cocaine");
	list.push_front("GothBoiClique");
	list.push_front("make");
	list.push_front("a");
	list.push_front("hoe");
	list.push_front("shake");
	list.push_front("Black");
	list.push_front("fur");
	list.push_front("black");
	list.push_front("coat");
	list.push_front("GothBoiClique");
	list.push_front("in");
	list.push_front("the");
	list.push_front("back");
	list.push_front("hoe\n");
	list.push_front("Switchblades");
	list.push_front("cocaine");
	list.push_front("GothBoiClique");
	list.push_front("make");
	list.push_front("a");
	list.push_front("hoe");
	list.push_front("shake");
	list.push_front("Black");
	list.push_front("fur");
	list.push_front("black");
	list.push_front("coat");
	list.push_front("GothBoiClique");
	list.push_front("in");
	list.push_front("the");
	list.push_front("back");
	list.push_front("hoe\n");
}

void test_range_based_loop(int id, List<std::string> & list)
{
	std::cout << std::endl;
	for(Node<std::string> i:list)
		std::cout << i.data << " ";
	std::cout << std::endl;
	for(Node<std::string> i:list)
		std::cout << i.data << " ";
	std::cout << std::endl;
	for(Node<std::string> i:list)
		std::cout << i.data << " ";
	std::cout << std::endl;
}