#pragma once
#include<iostream>
using namespace std;

template<class T>
class List
{
public:
	List(); // constructor default
	~List(); // destructor
	void pushBack(T data); // adds an element to the end of the List
	void pushFront(T data); // adds an element to the beginning of the List
	void popFront(); // deletes the first element from the List
	void popBack(); // deletes the last element from the List
	void insert(T data, int index); // inserts an element at a particular position
	void removeAt(int index); // deletes an element from a particular position
	void clear(); // deletes all elements in the List
	int getSize(); // returns the size of the list
	void print();//outputs all elements on the list
	T& getData(int index); // returns the element at the given index
	T& operator[](const int index); // overloads the operator[]

private:
#pragma region CLASS NODE
	template<class T>
	class Node
	{
	public:
		Node(T data = T(), Node* next = nullptr, Node* prev = nullptr)
		{
			_data = data;
			_next = next;
			_prev = prev;
		}
		Node* _next;
		Node* _prev;
		T _data;
	};
#pragma endregion

	Node<T>* _head;
	Node<T>* _tail; 
	int _size;
};

