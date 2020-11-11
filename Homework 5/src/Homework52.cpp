//Harrison Booth
//010788738

//Main file used for testing

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include "Linkedlist.h"

using namespace std;

/*
 * detailed points allocation removed.
 * but if your program pass all the test cases here
 * you will get 70/80 points allocated for correctness, efficiecy,
 * design, and testing.
 *
 */
int main(int argc, char** argv) {

    cout  << "1. ---Testing constructor and check function \n";
    Linkedlist list(5);
    cout << "This is list:" << endl;
    list.check();
    list.rcheck();
    Linkedlist list2;
    cout << "This is list2, an empty list:" << endl;
    list2.check();
    list2.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout  << "2. ---Testing push front 7  \n";
    cout << "before push front: " << endl;
    list.check();
    list.push_front(7);
    cout << "after push front: " << endl;
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout  << "2.1 ---Testing push front 7 on list2 (an empty list)  \n";
    cout << "before push front: " << endl;
    list2.check();
    list2.push_front(7);
    cout << "after push front: " << endl;
    list2.check();
    list2.rcheck();
    cout << "--------------------------------------\n\n" ;


      cout  << "3. ---Testing push back -1 on list2 (an empty list) \n";
     cout << "before push back: " << endl;
     list.check();
     list.push_back(-1);
     cout << "after push back: " << endl;
     list.check();
     list.rcheck();
     cout << "--------------------------------------\n\n" ;

    cout  << "3.1 ---Testing push back -1 on list2 (an empty list) \n";
    cout << "before push back: " << endl;
    list2.clear();
    list2.check();
    list2.push_back(-1);
    cout << "after push back: " << endl;
    list2.check();
    list2.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout  << "4. ---Testing insert 5 at position 2  \n";
    cout << "Before insert: " << endl;
    list.check();
    list.insert(2, 5);
    cout << "After insert: " << endl;
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout  << "4.1 ---Testing insert 5 at position 60 \n";
    cout << "Before insert: " << endl;
    list.check();
    list.insert(60, 5);
    cout << "After insert: " << endl;
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout  << "4.2 ---Testing insert 5 at position 2 on list2 (an empty list) \n";
    cout << "Before insert: " << endl;
    list2.clear();
    list2.check();
    list2.insert(2, 5);
    cout << "After insert: " << endl;
    list2.check();
    list2.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout  << "5. ---Testing front  \n";
    list.check();
    cout << "This is the first element: " << list.front() << endl;
    list.front() = 1234;
    list.check();
    cout << "This is the first element: " << list.front() << endl;
    cout << "--------------------------------------\n\n" ;


    cout  << "6. ---Testing back  \n";
    list.check();
    cout << "This is the last element: " << list.back() << endl;
    list.back()  = 5678;
    list.check();
    cout << "This is the last element: " << list.back() << endl;
    cout << "--------------------------------------\n\n" ;

    cout  << "7. ---Testing sort  \n";
    cout << "before sort: " << endl;
    list.check();
    list.sort();
    cout << "after sort: " << endl;
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout  << "7.1 ---Testing sort on list2 (an empty list)  \n";
    cout << "before sort: " << endl;
    list2.clear();
    list2.check();
    list2.sort();
    cout << "after sort: " << endl;
    list2.check();
    list2.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout  << "8. ---Testing pop_back  \n";
    cout << "before pop back: " << endl;
    list.check();
    list.pop_back();
    cout << "after pop back: " << endl;
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout  << "8.1 ---Testing pop_back on list2 (an empty list)  \n";
    cout << "before pop back: " << endl;
    list2.clear();
    list2.check();
    list2.pop_back();
    cout << "after pop back: " << endl;
    list2.check();
    list2.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout << "9. ---Testing pop_front \n";
    cout << "list before pop_front: " << endl;
    list.check();
    list.pop_front();
    cout << "list after pop_front: " << endl;
    list.check();
    list.rcheck();

    cout << "--------------------------------------\n\n" ;

    cout  << "9.1 ---Testing pop_back on list2 (an empty list)  \n";
    cout << "list before pop_front: " << endl;
    list2.check();
    list2.pop_front();
    cout << "list after pop_front: " << endl;
    list2.check();
    list2.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout  << "10. ---Testing erase at position 9  \n";
    cout << "Before erase: " << endl;
    list.check();
    list.erase(9);
    cout << "After erase: " << endl;
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout  << "10.1 ---Testing erase at position 3  \n";
    cout << "Before erase: " << endl;
    list.check();
    list.erase(3);
    cout << "After erase: " << endl;
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout  << "10.2 ---Testing erase at position 3 on list2 (an empty list) \n";
    cout << "Before erase: " << endl;
    list2.check();
    list2.erase(3);
    cout << "After erase: " << endl;
    list2.check();
    list2.rcheck();
    cout << "--------------------------------------\n\n" ;
    return 0;
}
