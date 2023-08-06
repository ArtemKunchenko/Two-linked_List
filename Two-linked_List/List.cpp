#include "List.h"
template<class T>
List<T>::List()
{
	_size = 0;
	_head = nullptr;
	_tail = nullptr;
}

template<class T>
List<T>::~List()
{
	clear();
}

template<class T>
void List<T>::pushBack(T data)
{
	if (_head == nullptr)
	{
		_head = new Node<T>(data);
		_tail = _head; 
	}
	else
	{
		Node<T>* new_node = new Node<T>(data, nullptr, _tail);
		_tail->_next = new_node;
		_tail = new_node;
	}
	_size++;
}

template<class T>
void List<T>::pushFront(T data)
{
	if (_head == nullptr)
	{
		_head = new Node<T>(data);
		_tail = _head; 
	}
	else
	{
		Node<T>* new_node = new Node<T>(data, _head, nullptr);
		_head->_prev = new_node;
		_head = new_node;
	}
	_size++;
}

template<class T>
void List<T>::popFront()
{
	if (_head != nullptr)
	{
		Node<T>* temp = _head;
		_head = _head->_next;

		if (_head != nullptr)
			_head->_prev = nullptr;
		else
			_tail = nullptr; 

		delete temp;
		_size--;
	}
}

template<class T>
void List<T>::popBack()
{
	if (_tail != nullptr)
	{
		Node<T>* temp = _tail;
		_tail = _tail->_prev;

		if (_tail != nullptr)
			_tail->_next = nullptr;
		else
			_head = nullptr; 

		delete temp;
		_size--;
	}
}

template<class T>
void List<T>::insert(T data, int index)
{
	if (index <= 0)
	{
		pushFront(data);
		return;
	}
	if (index >= _size)
	{
		pushBack(data);
		return;
	}

	Node<T>* previous = _head;
	for (int i = 0; i < index - 1; i++)
		previous = previous->_next;

	Node<T>* new_node = new Node<T>(data, previous->_next, previous);
	previous->_next->_prev = new_node;
	previous->_next = new_node;
	_size++;
}

template<class T>
void List<T>::removeAt(int index)
{
	if (index >= 0 && index < _size)
	{
		if (index == 0)
		{
			popFront();
			return;
		}
		if (index == _size - 1)
		{
			popBack();
			return;
		}

		Node<T>* previous = _head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->_next;

		Node<T>* for_delete = previous->_next;
		previous->_next = for_delete->_next;
		for_delete->_next->_prev = previous;
		delete for_delete;
		_size--;
	}
}

template<class T>
void List<T>::clear()
{
	while (_size != 0)
		popFront();
}

template<class T>
int List<T>::getSize() { return _size; }

template<class T>
void List<T>::print()
{
	for (int i = 0; i < _size; i++)
	{
		cout<<getData(i)<<"  ";
	}
	cout << endl;
}

template<class T>
T& List<T>::getData(int index)
{
	if (index >= 0 && index < _size)
	{
		int counter = 0;
		Node<T>* temp = _head;
		while (temp != nullptr)
		{
			if (counter == index)
				return temp->_data;
			temp = temp->_next;
			counter++;
		}
	}
	return _head->_data;
}

template<class T>
T& List<T>::operator[](const int index)
{
	return getData(index); 
}
