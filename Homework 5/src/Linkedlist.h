//Harrison Booth
//010788738

//Header file for Linkedlist
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <iomanip>
#include <cstring>
#include <math.h>
#include <cstddef>
#include <cstdlib>
using namespace std;

// Data element type
typedef int element_type;

// Basic Node structure
struct Node
{
    element_type elem;  // Data
    Node * next;        // Pointer to the next node in the chain
    Node * prev;        // Pointer to the previous node in the chain
};

class Linkedlist
{
public:
	//Types with scope in this class
	typedef element_type& reference;
	typedef const element_type& const_reference;

	//Default constructor
	Linkedlist(); //default constructor for empty list

	//Constructor initializes the linked list with n nodes with elems from 0 to n-1
	explicit Linkedlist(unsigned int n);

	//Destructor
	~Linkedlist(); //destructor to free nodes dynamically created to support the linklist

	//Returns 1 if the list contains nothing
	bool empty() const;

	//Removes all elements from the list, leaving it with a container size of 0
	void clear();

	//-----Element Access-----
	//Returns last element
	reference back();
	const_reference back() const;

	//Returns first element
	reference front();
	const_reference front() const;


	Linkedlist& operator=(const Linkedlist& l);

	//-----Modifiers-----
	//Deletes last item
	void pop_back ( );

	//Deletes first item
	void pop_front ( );

	//Adds item at end
	void push_back ( const element_type& x );

	//Insert element at beginning
	void push_front ( const element_type& x );

	//Sort integers highest to lowest
	void sort ( );

	// print the linked list in the forward direction,
	// similar to the show function of lab7
	void check() const;

	// print the linked list in the backward direction,
	// similar to the reverse_show function of lab8
	void rcheck() const;

	// insert a node with value specified by x after the node
	// specified by pos. The first node has position 0.
	// if the number of nodes in the linked list is less than
	// pos, the node is inserted at the end.
	void insert(unsigned int pos, const element_type& x);

	// remove the node specified by pos.
	// if the number of nodes in the linked list is less than
	// pos, the node at the end if any is removed.
	void erase(unsigned int pos);

private:
	Node* head;
	Node* tail;
	unsigned int numElements;
};


#endif /* LINKEDLIST_H_ */
