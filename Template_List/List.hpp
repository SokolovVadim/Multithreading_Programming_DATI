//==========================================================
// List with CAS insertion and iterator
//==========================================================
template<typename T>
struct Node
{
 	T data;
 	Node* next;
}; 

//==========================================================

template<typename T>
class List
{
public:

	List();
	~List();

private:
	Node<T>* head;
};

template<typename T>
List<T>::List():
	head(nullptr)
{
	std::cout << "List constructed\n";
}

template<typename T>
List<T>::~List()
{
	std::cout << "List destructed\n";
}


