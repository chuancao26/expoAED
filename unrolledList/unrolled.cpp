// C++ program to show the insertion operation of Unrolled Linked List 

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// class for each node
class UnrollNode {
public:
	UnrollNode* next;
	int num_elements;
	int* array;

	// Constructor
	UnrollNode(int n)
	{
		next = nullptr;
		num_elements = 0;
		array = new int[n];
	}
};

// Operation of Unrolled Function
class UnrollLinkList {

private:
	UnrollNode* start_pos;
	UnrollNode* end_pos;

	int size_node;
	int nNode;

public:
	// Parameterized Constructor
	UnrollLinkList(int capacity)
	{
		start_pos = nullptr;
		end_pos = nullptr;
		nNode = 0;
		size_node = capacity + 1;
	}

	// Insertion operation
	void Insert(int num)
	{
		nNode++;

		// Check if the list starts from NULL
		if (start_pos == nullptr) {
			start_pos = new UnrollNode(size_node);
			start_pos->array[0] = num;
			start_pos->num_elements++;
			end_pos = start_pos;
			return;
		}

		// Attaching the elements into nodes
		if (end_pos->num_elements + 1 < size_node) {
			end_pos->array[end_pos->num_elements] = num;
			end_pos->num_elements++;
		}

		// Creation of new Node
		else {
			UnrollNode* node_pointer = new UnrollNode(size_node);
			int j = 0;
			for (int i = end_pos->num_elements / 2 + 1;
				i < end_pos->num_elements; i++)
				node_pointer->array[j++] = end_pos->array[i];

			node_pointer->array[j++] = num;
			node_pointer->num_elements = j;
			end_pos->num_elements = end_pos->num_elements / 2 + 1;
			end_pos->next = node_pointer;
			end_pos = node_pointer;
		}
	}

	// Display the Linked List
	void display()
	{
		cout << "\nUnrolled Linked List = " << endl;
		UnrollNode* pointer = start_pos;
		while (pointer != nullptr) {
			for (int i = 0; i < pointer->num_elements; i++)
				cout << pointer->array[i] << " ";
			cout << endl;
			pointer = pointer->next;
		}
		cout << endl;
	}
};

// Main Class 
int main()
{
	srand(time(0));

	UnrollLinkList ull(5);

	// Perform Insertion Operation
	for (int i = 0; i < 12; i++) {

		// Generate random integers in range 0 to 99
		int rand_int1 = rand() % 100;
		cout << "Entered Element is " << rand_int1 << endl;
		ull.Insert(rand_int1);
		ull.display();
	}
	return 0;
}

// This code is contributed by Vikram_Shirsat

