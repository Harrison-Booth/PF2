//Harrison Booth 010788738

#include <cstdlib>
#include <iostream>
//#include <string>
#include <fstream>
#include "Mystring.h"

#define string Mystring

using namespace std;

/*
 * Check function from the previous lab
 */
void check (const string s, const string name)
{
    cout << "checking " << name << endl;
    cout << name << " contains " << s << endl;
    cout << name << " capacity() is " << s.capacity() << endl;
    cout << name << " length() is " << s.length() << endl;
    cout << name << " size() is " << s.size() << endl;
    cout << name << " max_size() is " << s.max_size() << endl << endl;
}

int main()
{

    string s1("Hello, World!");
    string s1name("s1");
    check(s1, s1name);

    cout << "---Testing empty---\n";
    if (s1.empty()) {
    	cout << "s1 is empty" << endl;
    }
    else {
    	cout << "s1 is not empty" << endl;
    }

    cout << "--------------------------------------\n\n" ;

    cout << "---Testing assignment operator number 2---\n";
    string s2;
    s2 = "testing";
    string s2name("s2");
    check(s2, s2name);

    cout << "---Testing both comparison == operators---\n";
    if (s2 == "testing") {
    	cout << "s2 == testing works" << endl;
    }
    else {
    	cout << "s2 == testing is not working" << endl;
    }

    if ("testing" == s2) {
    	cout << "testing == s2 works" << endl;
    }
    else {
    	cout << "testing == s2 is not working" << endl;
    }
    cout << "--------------------------------------\n\n" ;

    cout << "---Testing all comparison != operators---\n";
    string s3;
    s3 = "not testing";
    string s3name("s3");
    check(s3, s3name);

    if (s2 != "not testing") {
    	cout << "s2 != not testing works" << endl;
    }
    else {
    	cout << "s2 !== not testing is not working" << endl;
    }

    if ("not testing" != s2) {
    	cout << "not testing != s2 works" << endl;
    }
    else {
    	cout << "not testing != s2 is not working" << endl;
    }

    if (s3 != s2) {
    	cout << "s3 != s2 works" << endl;
    }
    else {
    	cout << "not testing != s2 is not working" << endl;
    }

    cout << "--------------------------------------\n\n" ;


    cout << "---Testing array notation for a const char---\n";
    cout << "second char of s1 using normal input '1': "<< s1[1] << endl;
    int i = 1;
    cout << "second char of s1 using int i = 1: "<< s1[i] << endl;
    cout << "--------------------------------------\n\n" ;

    cout << "---Testing += operator ---\n";
    cout << "s1: " << s1 << endl << "s2: " << s2 << endl;
    s2 += s1;
    cout << "s2 after += s1: "<< s2 << endl;
    check(s2,"s2");
    cout << "Resetting s2" << endl;
    s2 = "testing";
    cout << "s2: " << s2 << endl;
    s2 += "c_string";
    cout << "s2 after += 'c_string': "<< s2 << endl;
    check(s2,"s2");
    cout << "Resetting s2" << endl;
    s2 = "testing";
    cout << "--------------------------------------\n\n" ;

    cout << "---Testing append ---\n";
    cout << "s1: " << s1 << endl << "s2: " << s2 << endl;
    s2.append(s1);
    cout << "s2 after s2.append(s1): "<< s2 << endl;
    check(s2,"s2");
    cout << "Resetting s2" << endl;
    s2 = "testing";
    cout << "s2: " << s2 << endl;
    s2.append("c_string");
    cout << "s2 after s2.append('c_string'): "<< s2 << endl;
    check(s2,"s2");
    cout << "Resetting s2" << endl;
    s2 = "testing";
    cout << "--------------------------------------\n\n" ;

    cout << "---Testing insert ---\n";
    cout << "s2: " << s2 << endl;
    s2.insert(6, "c++");
    cout << "s2 after s2.insert(6, 'c++'): "<< s2 << endl;
    check(s2,"s2");
    cout << "Resetting s2" << endl;
    s2 = "testing";

    cout << "s1: " << s1 << endl << "s2: " << s2 << endl;
    s2.insert(6, s1);
    cout << "s2 after s2.insert(6, s1): "<< s2 << endl;
    check(s2,"s2");
    cout << "Resetting s2" << endl;
    s2 = "testing1testing2testing3";
    cout << "--------------------------------------\n\n" ;

    cout << "---Testing replace ---\n";
    cout << "s2: " << s2 << endl;
    s2.replace(6, 1, "---");
    cout << "s2 after s2.replace(6, 1, '---'): "<< s2 << endl;
    check(s2,"s2");
    cout << "Resetting s2" << endl;
    s2 = "testing1testing2testing3";

    cout << "s1: " << s1 << endl << "s2: " << s2 << endl;
    s2.replace(6, 7, s1);
    cout << "s2 after s2.replace(6, 7, s1): "<< s2 << endl;
    check(s2,"s2");
    cout << "Resetting s2" << endl;
    s2 = "testing";
    cout << "--------------------------------------\n\n" ;

    cout << "---Testing find_first_of ---\n";
    cout << "s2: " << s2 << endl;
    cout << "s2 find first of aeiou after index 2: " << s2.find_first_of("aeiou", 2, 7);
    cout << "--------------------------------------\n\n" ;

    cout << "---Testing find_last_not_of ---\n";
    cout << "s2: " << s2 << endl;
    cout << "s2: " << s2.length() << endl;
    cout << "s2 find find_last_not_of !?: " << s2.find_last_not_of("!?");
    cout << "--------------------------------------\n\n" ;

    cout << "---Testing + ---\n";
    cout << "s1: " << s1 << endl << "s2: " << s2 << endl << "s3: " << s3 << endl;
    s3 = s1 + s2;
    cout << "s3 after s3 = s1 + s2: " << s3 << endl;
    cout << "--------------------------------------\n\n" ;

    return 0;
}
