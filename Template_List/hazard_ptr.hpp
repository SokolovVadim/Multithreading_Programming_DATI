#include <atomic>
#include <memory>


template<typename T>
struct Node
{
 	std::shared_ptr<T> data;
 	Node<T>* next;
 	Node():
 		data{},
 		next(nullptr)
 	{}
	Node(const T& value):
		data(value),
		next(nullptr)
	{}
}; 


template<typename T>
class List
{
public:
	std::shared_ptr<T> pop();
private:
	std::atomic<Node<T>*> head;
	std::atomic<Node<T>*> tail;
};

std::atomic<void*>& get_hazard_pointer_for_current_thread()
{
	std::atomic<void*> ptr;
	return ptr;
}

template<typename T>
bool outstanding_hazard_pointers_for(Node<T>* node)
{
	return true;
}

template<typename T>
void reclaim_later(Node<T>* node)
{
	
}

void delete_nodes_with_no_hazards()
{
	
}

unsigned const MAX_HP = 2 << 7;



template<typename T>
std::shared_ptr<T> List<T>::pop()
{
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
    	return nullptr; ///!!!!!!!!
    }
	std::atomic<void*> & hp = get_hazard_pointer_for_current_thread();
	Node<T>* old_head = head.load();
	do
	{
		Node<T>* temp(nullptr);
		do
		{
			temp = old_head;
			hp.store(old_head);
			old_head = head.load();
		} while(old_head != temp);
	} while(old_head && !head.compare_exchange_strong(old_head, old_head->next));
	hp.store(nullptr);

	std::shared_ptr<T> res;
	if(old_head)
	{
		res.swap(old_head->data);
		if(outstanding_hazard_pointers_for(old_head))
		{
			reclaim_later(old_head);
		}
		else
		{
			delete old_head;
		}
		delete_nodes_with_no_hazards();
	}
	return res;
}