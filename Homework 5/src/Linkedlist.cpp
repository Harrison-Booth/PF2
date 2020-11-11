//Harrison Booth
//010788738

//implementation of header file for Linkedlist

#include "Linkedlist.h"

//Default constructor
Linkedlist::Linkedlist() {
	head = NULL;
	tail = NULL;
    numElements = 0;
}

//Constructor initializes the linked list with n nodes with elems from 0 to n-1
Linkedlist::Linkedlist(unsigned int n) {
    head = new Node();
    head -> next = NULL;
    head -> prev = NULL;

    tail = head;

    numElements = 0;

	for (unsigned int i = 1; i < n; i++) {
		push_back(i);
    }
}

Linkedlist::~Linkedlist(){
    Node* current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

//Returns 1 if the list contains nothing
bool Linkedlist::empty()const {
    if (head != NULL) {
        return false;
    }
    return true;
}

//Removes all elements from the list, leaving it with a container size of 0
void Linkedlist::clear() {
    Node* current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        delete current;
        current = next;
        numElements--;
    }
    head = NULL;
    tail = NULL;
}

//-----Element Access-----
//Returns last element
Linkedlist::reference Linkedlist::back() {
	return tail->elem;
}

Linkedlist::const_reference Linkedlist::back() const {
	return tail->elem;
}

//Returns first element
Linkedlist::reference Linkedlist::front() {
	return head -> elem;
}

Linkedlist::const_reference Linkedlist::front() const {
	return head -> elem;
}


Linkedlist& Linkedlist::operator=(const Linkedlist& l) {
	if(this != &l) {
		clear();
		Node* cur = l.head;
		while(cur != NULL) {
			push_back(cur->elem);
			cur = cur->next;
		}
	}
	return *this;
}

//-----Modifiers-----
//Deletes last item
void Linkedlist::pop_back ( ) {
	if (empty()) {
		return;
	}
	if (numElements == 1) {
		head = NULL;
		tail = NULL;

		numElements--;
		return;
	}


	tail = tail->prev;

	tail->next = NULL;

	numElements--;
}

//Deletes first item
void Linkedlist::pop_front ( ) {
	if (empty()) {
		return;
	}
	if (numElements == 1) {
		head = NULL;
		tail = NULL;

		numElements--;
		return;
	}

	Node* current = head->next;
	delete head;
	head = current;
	head->prev = NULL;

	numElements--;

}

//Adds item at end
void Linkedlist::push_back ( const element_type& x ) {

	Node* cur = new Node();
	cur->elem = x;
	cur->next = NULL;
	cur->prev = tail;
	if(tail != NULL)
		tail->next = cur;
	if (head == NULL) {
		head = cur;
	}
	tail = cur;

	numElements++;
}

//Insert element at beginning
void Linkedlist::push_front ( const element_type& x ) {
	Node* cur = new Node();
	cur->elem = x;
	cur->next = head;
	cur->prev = NULL;
    if(head != NULL)
        head->prev = cur;
    if (tail == NULL) {
        tail = cur;
    }
    head = cur;

    numElements++;

}

//Sort integers highest to lowest
void Linkedlist::sort ( ) {
    Node* ptr = new Node();
	Node* vari = new Node();

    //Nothing needs to change if their are only 1 or 0 elements in the list;
    if (head == NULL || head->next == NULL ) {
    	return;
    }

    int swappedcheck = 1;
    while (swappedcheck) {
    	//If stays 0, the list is already sorted and loop breaks
    	swappedcheck = 0;

        ptr = head;
        while (ptr->next != NULL) {
            if (ptr->elem > ptr->next->elem) {
                // Swapping, go again

            	swappedcheck = 1;

            	vari->elem = ptr->elem;
                ptr->elem = ptr->next->elem;
                ptr->next->elem = vari->elem;
            }
            ptr = ptr->next;
        }
    }

}

// print the linked list in the forward direction,
// similar to the show function of lab7
void Linkedlist::check() const {
    Node* current = head;
    if (head == NULL) {
        cout << "It is an empty list." << endl;
    }

    int i = 0;
    while (current != NULL) {
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->next;
        i++;
    }
    cout << "------------------------------------------------------------------------------------------" << endl;
}

// print the linked list in the backward direction,
// similar to the reverse_show function of lab8
void Linkedlist::rcheck() const {
    Node* current = tail;

    if (current == NULL)
        cout << "It is an empty list!" << endl;

    int i = 0;
    while (current != NULL)
    {
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->prev;
        i++;
    }

    cout << "------------------------------------------------------------------------------------------" << endl;
}


// insert a node with value specified by x after the node
// specified by pos. The first node has position 0.
// if the number of nodes in the linked list is less than
// pos, the node is inserted at the end.
void Linkedlist::insert(unsigned int pos, const element_type& x) {
	if (numElements < pos) {
		push_back(x);
		numElements++;

		return;
	}

	Node* cur = head;
	for (unsigned int i = 0; i < pos-1; i++) {
		cur = cur->next;
	}

	Node* ins = new Node();
	ins->elem = x;
	ins->next = cur->next;
	ins->prev = cur;

	cur->next = ins;
	ins->next->prev= ins;


	numElements++;
}

// remove the node specified by pos.
// if the number of nodes in the linked list is less than
// pos, the node at the end if any is removed.
void Linkedlist::erase(unsigned int pos) {
	if (numElements < pos) {
		pop_back();
		numElements--;
		return;
	}

	Node* cur = head;
	for (unsigned int i = 0; i < pos; i++) {
		cur = cur->next;
	}

	cur->prev->next = cur-> next;
	cur->next->prev = cur->prev;
	delete cur;
	numElements--;
}
