#include <iostream>
#include <string>
#include <List.hpp>

int main()
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

	return 0;
}