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
 	Node(const T& value, Node<T>* next = nullptr):
		data(value),
		next(next)
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
    	iterator operator++() { node_ = node_->next; return *this; }
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
	Node<T>* tail;
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

template<typename T>
void List<T>::push_back(const T& value)
{
	Node<T>* temp = new Node<T>(value, nullptr);

	if(head == nullptr)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = tail->next;
	}
}

//==========================================================

template<typename T>
void List<T>::push_front(const T& value)
{
	head = new Node<T>(value, head);

	// list with the only one element
	if(tail == nullptr)
		tail = head;
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

#endif // LIST_HPP
