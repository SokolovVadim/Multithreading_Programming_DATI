#include <iostream>
#include <string>
#include <List.hpp>

int main()
{

	List<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	
	std::cout << *list.begin() << std::endl;
	std::cout << *list.end() << std::endl;

/*	List<std::string> list;


	list.push_front("Hey!");
	list.push_back("It's");
	list.push_front("Wow!");
	list.push_back("corona");
	list.push_back("time!");
	list.display();*/
	/*list.pop_front();
	list.pop_back();
	list.pop_front();
	list.pop_back();
	list.display();
	list.pop_front();*/

/*	for(std::string s: list)
		std::cout << s << " ";*/
	


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