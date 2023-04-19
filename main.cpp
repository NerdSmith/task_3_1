#include "Queue.h"
#include <iostream>

int main(int argc, char *argv[])
{
	auto q = new Queue<int>();
	q->enqueue(1);
	q->enqueue(2);
	q->enqueue(3);
	q->enqueue(4);
	q->enqueue(5);
	q->enqueue(6);
	cout << "q: " << q->toString() << endl;
	cout << "deq: " << q->dequeue() << endl;
	cout << "deq: " << q->dequeue() << endl;
	cout << "deq: " << q->dequeue() << endl;
	cout << "q: " << q->toString() << endl;

	for (auto i : *q)
	{
		cout << i << endl;
	}
	delete q;

	auto q2 = new Queue<double>();
	q2->enqueue(1.1);
	q2->enqueue(2.2);
	q2->enqueue(3.3);
	q2->enqueue(4.4);
	q2->enqueue(5.5);
	q2->enqueue(6.6);
	cout << q2->toString() << endl;
	cout << q2->dequeue() << endl;
	cout << q2->dequeue() << endl;
	// cout << q2->dequeue() << endl;
	cout << q2->toString() << endl;
	for (auto i : *q2)
	{
		cout << i << endl;
	}
	delete q2;
	return 0;
}