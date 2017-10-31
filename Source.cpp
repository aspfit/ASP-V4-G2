#include <iostream>
using namespace std;

int const MAXSIZE = 10;

class Item {
public:
	int _info;
	int _priority;
	
	Item() {
		this->_info = 0;
		this->_priority = 0;
	}

	Item(int info, int priority) {
		this->_info = info;
		this->_priority = priority;
	}

	void Print() {
		//cout << "Value   : " << this->_info << endl;
		cout << "Priority: " << this->_priority << endl;
	}
};

class PriorityQueue {
private:
	int _counter;
	Item *_array[MAXSIZE]{ nullptr };

	bool IsFull() {
		if (this->_counter == MAXSIZE - 1)
			return true;

		return false;
	}
	bool IsEmpty() {
		if (this->_counter == -1)
			return true;

		return false;
	}

public:
	PriorityQueue() {
		this->_counter = -1;
	}

	void Enqueue(Item i) {
		if (this->IsFull())
			return;

		this->_counter++;
		this->_array[this->_counter] = new Item(i);
	}

	Item *Dequeue() {
		if (this->IsEmpty())
			throw exception("queue is empty!");

		int best = 0;
		for (int i = 1; i <= this->_counter; i++) 
			if (this->_array[best]->_priority >= this->_array[i]->_priority) 
				best = i;

		Item *toReturn = this->_array[best];
		this->_array[best] = this->_array[this->_counter--];
		return toReturn;
	}
};

int main() {
	Item a(3, 3);
	Item b(3, 7);
	Item c(3, 5);
	Item d(3, 1);
	Item e(3, 2);
	Item f(3, 4);

	PriorityQueue pq;
	pq.Enqueue(a);
	pq.Enqueue(b);
	pq.Enqueue(c);
	pq.Enqueue(d);
	pq.Enqueue(e);
	pq.Enqueue(f);

	Item *best = pq.Dequeue();
	best->Print();	
	Item *best1 = pq.Dequeue();
	best1->Print();
	Item *best2 = pq.Dequeue();
	best2->Print();



	getchar();
	return 0;
}
