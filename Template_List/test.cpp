#include <iostream>
#include <string>
#include <List.hpp>

int main()
{
	std::cout << "Hello!\n";
	List<std::string> list;

	list.push_front("Hey!");
	list.push_back("It's");
	list.push_front("Wow!");
	list.push_back("corona");
	list.push_back("time!");
	list.display();
	list.pop_front();
	list.pop_back();
	list.pop_front();
	list.pop_back();
	list.display();
	list.pop_front();
	


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

	return 0;
}