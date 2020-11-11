//Harrison Booth 010788738

#include "Mystring.h"

// default constructor
Mystring::Mystring()
{
    ptr_buffer  = new char[1];
    *ptr_buffer = '\0';
    buf_size    = 1;
    len         = 0;
}

// constructor from c-style string or "abc"
Mystring::Mystring(const char * s)
{
    len        = strlen(s);
    buf_size   = len + 1;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, s);

}

// copy constructor to be implemented
Mystring::Mystring(const Mystring& orig)
{
    len = orig.length();
    buf_size = len+1;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, orig.ptr_buffer);
}

// Destructor
Mystring::~Mystring()
{
    delete [] ptr_buffer;
}

// Iterators We will not implement them for hw4
//iterator begin();
//iterator end();

//=== Memory Related ===

// Change buffer size to n
void Mystring::reserve(size_type n)
{
    if (n > buf_size){
        // need to increase the capacity to n
        char * tmp = new char[n];
        buf_size = n;
        strcpy(tmp, ptr_buffer);
        // return the space to the system
        delete [] ptr_buffer;
        ptr_buffer = tmp;
    }
}

 Mystring::size_type Mystring::size() const
 {
     return len;
 }

 Mystring::size_type Mystring::length() const
 {
     return len;
 }

 Mystring::size_type Mystring::capacity() const
 {
       return buf_size;
 }

 Mystring::size_type Mystring::max_size() const
 {
       return (int)pow(2,30) -4 ;
 }

 bool Mystring::empty() const {
	 if((*ptr_buffer == '\0') && (len == 0)) {
		 return true;
	 }
	 return false;
 }

 //=== Overloading operators ===

     // Assignment operator

 Mystring& Mystring::operator=(const Mystring& orig)
 {

 	if (&orig != this) {
 		len=strlen(orig.ptr_buffer);
 		clear();

 		this -> ptr_buffer = new char[len+1];
 		this -> buf_size = len +1;
 		this -> ptr_buffer[len] = '\0';
 		strcpy(ptr_buffer, orig.ptr_buffer);

 	}
 	return *this;
 }

 Mystring& Mystring::operator=(const char * orig)
 {

	 	if (orig != this->c_str()) {
	 		len=strlen(orig);
	 		clear();

	 		this -> ptr_buffer = new char[len+1];
	 		this -> buf_size = len +1;
	 		this -> ptr_buffer[len] = '\0';
	 		strcpy(ptr_buffer, orig);

	 	}
	 	return *this;
 }


 // Array notation - returns a character at the position
 char Mystring::operator[](size_type pos) const
 {
	 if (pos > len) {
		 cout << "Str[" << pos << "] is an invalid position." << endl;
		 throw "error, an invalid position was specified";
	 }
	 return ptr_buffer[pos];
 }

 char& Mystring::operator[](size_type pos)
 {
	 if (pos > len) {
		 cout << "Str[" << pos << "] is an invalid position." << endl;
		 //exit(0);
		 throw "error, an invalid position was specified";
	 }
	 return ptr_buffer[pos];
 }


 // Append
 Mystring& Mystring::operator+=(const Mystring& str)
 {
		len = len + str.len;
		reserve(len);

		strcat(ptr_buffer, str.ptr_buffer);

		return *this;
 }

 Mystring& Mystring::operator+=(const char * str)
 {
	    len = len + strlen(str);
	    reserve(len);

	    strcat(ptr_buffer, str);

	    return *this;
 }


//=== Methods that modifiy the string
 void Mystring::clear()
 {
 	delete [] ptr_buffer;
 	ptr_buffer = NULL;
 }

void Mystring::push_back(char c)
{
    // do we still have room for one more character?
    if (len + 1 == buf_size){
        // no more room
        // call reserve function to increase capacity
        buf_size++;
    	reserve(buf_size);
    }
    ptr_buffer[len] = c;
    ptr_buffer[buf_size] = '\0';
    len++;
}

Mystring& Mystring::append(const Mystring& str)
{
	len = len + str.len;
	reserve(len);

	strcat(ptr_buffer, str.ptr_buffer);

	return *this;
}

Mystring& Mystring::append(const char * str)
{
    len = len + strlen(str);
    reserve(len);

    strcat(ptr_buffer, str);

    return *this;
}

Mystring& Mystring::insert(size_type pos, const Mystring& str)
{
    len = len + str.len;
    reserve(len);

    Mystring tmp = ptr_buffer + pos;
    strcpy(ptr_buffer + pos, str.c_str());
    append(tmp);

    return *this;
}

Mystring& Mystring::insert(size_type pos, const char * str)
{
    len = len + strlen(str);
    reserve(len);

    Mystring tmp = ptr_buffer + pos;
    strcpy(ptr_buffer + pos, str);

    append(tmp);

    return *this;
}

Mystring& Mystring::replace(size_type start, size_type span, const Mystring& str)
{
    len = len + str.len;
    reserve(len);

    Mystring tmp(ptr_buffer + start + span);

    strcpy(ptr_buffer + start, str.ptr_buffer);
    append(tmp);

    return *this;
}

Mystring& Mystring::replace(size_type start, size_type span, const char * str)
{
    len = len + strlen(str);
    reserve(len);

    Mystring tmp(ptr_buffer + start + span);

    strcpy(ptr_buffer + start, str);
    append(tmp);

    return *this;
}

//=== Conversion to c-string
 const char * Mystring::c_str() const
 {
     return ptr_buffer;
 }

 // buffer (3) version of the overloaded method
 Mystring::size_type Mystring::find_first_of(const char* s, size_type pos, size_type n) const
 {
	 if (pos > len) {
		 return npos;
	 }
	 for(size_type i = pos; i < len; i++) {
	     for(size_type j = 0; j < n; j++) {
	         if(*(ptr_buffer + i) == *(s + j))
	             return i;
	     }
	 }
	 return npos;
 }

 // c-string (2)
 Mystring::size_type Mystring::find_last_not_of(const char* s, size_type pos) const
 {
	 size_type start = 0;
	 if ((pos == npos) || (pos > len - 1)) {
		 start = len - 1;
	 }
	 else {
		 start = pos;
	 }
	 int track;

		 for(size_type i = start; i >= 0; i--) {
			 track = 0;
			 for(size_type j = 0; j < strlen(s); j++) {
				 if (*(s+j) == *(ptr_buffer+i)) {
					 track++;
				 }
			 }
			 if (track == 0) {
				 return i;
			 }
		 }

	 return npos;
 }

// Overload operator == for Mystring
bool operator==(const Mystring& lhs, const Mystring& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str())== 0;
}

bool operator==(const char * lhs, const Mystring& rhs)
{
	return strcmp(lhs, rhs.c_str()) == 0;
}

bool operator==(const Mystring& lhs, const char * rhs)
{
	return strcmp(lhs.c_str(), rhs) == 0;
}

// Overload operator != for Mystring
bool operator!=(const Mystring& lhs, const Mystring& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str());
}

bool operator!=(const char * lhs, const Mystring& rhs)
{
	return strcmp(lhs, rhs.c_str());
}

bool operator!=(const Mystring& lhs, const char * rhs)
{
	return strcmp(lhs.c_str(), rhs);
}

// Overload operator + for string as concatenation
Mystring operator+(const Mystring& lhs, const Mystring& rhs)
{
    Mystring tmp = lhs;
    tmp.append(rhs);
    return tmp;
	//return strcat((char*)lhs.c_str(), (char*)rhs.c_str());
}

//Output
ostream& operator<<(ostream& out, const Mystring& str)
{
    out << str.c_str();
    return out;
}


