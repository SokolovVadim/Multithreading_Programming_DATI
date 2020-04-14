#ifndef LIST_HPP
#define LIST_HPP

//==========================================================
// List with CAS insertion and iterator for_each
//==========================================================

#include<atomic>

template<typename T>
struct Node
{
 	T data;
 	Node<T>* next;
 	Node():
 		data{},
 		next(nullptr)
 	{}
 	/*Node(const T& value, Node<T>* next = nullptr):
		data(value),
		next(next)
	{}*/
	Node(const T& value):
		data(value),
		next(nullptr)
	{}
}; 

//==========================================================

template<typename T>
class List
{
public:
	class iterator {
   	public:
    	iterator(Node<T>* node): node_(node){}
    	iterator operator++();
    	bool operator!=(const iterator & other) const { return node_ != other.node_; }
    	const Node<T>& operator*() const { return *node_; }
    private:
    	Node<T>* node_;
   	};

	List();
	~List();

	void push_back(const T& value);
	void pop_back();
	void push_front(const T& value);
	void pop_front();
	void display();
	void loud_display();

	iterator begin();
	iterator end();
	iterator begin() const;
	iterator end() const;

private:
	std::atomic<Node<T>*> head;
	std::atomic<Node<T>*> tail;
};

//==========================================================

template<typename T>
List<T>::List():
	head(nullptr),
	tail(nullptr)
{
	std::cout << "List constructed\n";
}

//==========================================================

template<typename T>
List<T>::~List()
{
	std::cout << "List destructed\n";
}

//==========================================================
// https://en.cppreference.com/w/cpp/atomic/atomic/compare_exchange
//==========================================================

template<typename T>
void List<T>::push_back(const T& value)
{
	// Node<T>* temp = new Node<T>(value);
	Node<T>* new_node = new Node<T>(value);

	if(head == nullptr)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		Node<T>* old_tail = tail.load(std::memory_order_relaxed);
		int loop_counter(0); // debug variable showing number of thread tries to get the data
		do
		{
			if(loop_counter > 0)
				std::cout << "MISS" << std::endl;
			loop_counter++;
			old_tail->next = new_node;
		}while(!std::atomic_compare_exchange_weak_explicit(
													&tail,
													&old_tail,
													new_node,
													std::memory_order_release,
                               						std::memory_order_relaxed
													));
	}
}

//==========================================================

template<typename T>
void List<T>::push_front(const T& value)
{
	Node<T>* new_node = new Node<T>(value);
	Node<T>* old_head = head.load(std::memory_order_relaxed);
	int loop_counter(0); // debug variable showing number of thread tries to get the data
	do
	{
		if(loop_counter > 0)
			std::cout << "MISS" << std::endl;
		loop_counter++;
		new_node->next = old_head;
	}while(!head.compare_exchange_weak(old_head, new_node,
                                       std::memory_order_release,
                                       std::memory_order_relaxed));
	
	// list with the only one element
	if(tail == nullptr){
		tail = head.load(std::memory_order_relaxed);
	}
}

//==========================================================

template<typename T>
void List<T>::pop_back()
{
	// empty list
	if (head == nullptr)
    {
        throw std::out_of_range("Can't pop from empty list");
    }

    // list with the only one element
    if(head == tail)
    {
    	delete head;
    	head = nullptr;
    	tail = nullptr;
    	return;
    }

	Node<T>* temp = head;
	while(temp->next != tail)
	{
		temp = temp->next;
	}
	delete tail;
	tail = temp;
	tail->next = nullptr;
}

//==========================================================

template<typename T>
void List<T>::pop_front()
{
	// empty list
	if (head == nullptr)
    {
        throw std::out_of_range("Can't pop from empty list");
    }

    // list with the only one element
    if(head == tail)
    {
    	delete head;
    	head = nullptr;
    	tail = nullptr;
    	return;
    }

    Node<T>* temp = head->next;
    delete head;
    head = temp;
}

//==========================================================

template<typename T>
void List<T>::display()
{
	Node<T>* temp = head;

	while(temp != nullptr)
	{
		std::cout << temp->data << "\t";
		temp = temp->next;
	}
	std::cout << std::endl;
}

//==========================================================

template<typename T>
void List<T>::loud_display()
{
	Node<T>* temp = head;

	while(temp != nullptr)
	{
		std::cout << temp->data << "\t" << temp << "\t" << temp->next << "\t" << head << "\t" << tail;
		std::cout << std::endl;
		temp = temp->next;
	}
}

//==========================================================

template<typename T>
typename List<T>::iterator List<T>::begin() const
{
	return iterator(head);
}

//==========================================================

template<typename T>
typename List<T>::iterator List<T>::end() const
{
	return iterator(tail);
}

//==========================================================

template<typename T>
typename List<T>::iterator List<T>::begin()
{
	return iterator(head);
}

//==========================================================

template<typename T>
typename List<T>::iterator List<T>::end()
{
	return iterator(tail);
}

//==========================================================

template<typename T>
typename List<T>::iterator List<T>::iterator::operator++()
{
	node_ = node_->next;
	return *this;
}

#endif // LIST_HPP
