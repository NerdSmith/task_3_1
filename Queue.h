#pragma once
#include <sstream>
#include <iostream>

using namespace std;

class EmptyQueueException
{
};

template <typename T>
class Queue
{

private:
	class Node
	{
	public:
		Node *nextNode = nullptr;
		T val;
		Node(T value) : val(value) {}
	};
	Node *rootNode = nullptr;
	Node *backNode;
	int size = 0;

public:
	struct Iterator
	{
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using node_t = Node;
		using node_ptr = Node *;
		using node_ref = Node &;
		using type_ptr = T *;
		using type_ref = T &;

		Iterator(node_ptr ptr) : nPtr(ptr) {}

		Iterator operator++()
		{
			nPtr = nPtr->nextNode;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator stash = *this;
			nPtr = nPtr->nextNode;
			return stash;
		}

		type_ref operator*() const
		{
			return nPtr->val;
		}

		type_ptr operator->()
		{
			return &(nPtr->val);
		}

		bool operator==(const Iterator &other)
		{
			return nPtr == other.nPtr;
		}

		bool operator!=(const Iterator &other)
		{
			return nPtr != other.nPtr;
		}

	private:
		node_ptr nPtr;
	};

	Queue()
	{
		backNode = rootNode;
	}

	bool isEmpty()
	{
		return !size;
	}

	void enqueue(T item)
	{
		Node *n = new Node(item);
		if (rootNode == nullptr)
		{
			rootNode = n;
			backNode = rootNode;
		}
		else
		{
			backNode->nextNode = n;
			backNode = n;
		}
		size++;
	}

	T dequeue()
	{
		if (this->isEmpty())
		{
			throw EmptyQueueException();
		}
		T val = rootNode->val;
		Node *rootPtr = rootNode;
		rootNode = rootNode->nextNode;
		delete rootPtr;
		size--;
		return val;
	}

	int getSize()
	{
		return size;
	}

	T peek()
	{
		return rootNode->val;
	}

	Iterator begin() { return Iterator(rootNode); }
	Iterator end() { return Iterator(nullptr); }

	string toString()
	{
		stringstream ss;
		for (Node *p = this->rootNode; p != nullptr; p = p->nextNode)
		{
			ss << p->val << " ";
		}
		return ss.str();
	}

	~Queue()
	{
		Node *nPtr = this->rootNode;
		while (nPtr != nullptr)
		{
			Node *nextPtr = nPtr->nextNode;
			delete nPtr;
			nPtr = nextPtr;
		}
	}
};