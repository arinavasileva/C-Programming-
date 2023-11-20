/******************************************************************************

TASK 1, 2, 3, 4 (4PCS TOTAL)

*******************************************************************************/
//task1 

#include <iostream>
#include <cstring>

using namespace std;

class String1 {
    
    private:
    
    char c_string[11];
    
    public:
    
    
    String1(const char* inputString) {
        
        strncpy(c_string, inputString, 10);
        
        c_string[10] = '\0';
    }

    void list() const {
        std::cout << "String: " << c_string << std::endl;
    }
};

void f(String1 s) {
    s.list(); 
}

int main() {
  
    String1 s("abcdefg");
    
    s.list();

    f(s);

    s.list();

    return 0;
};

//task2 and 3
/*by passing an oblect to a function in the class, you create a copy of it. To make sure,
no additional copies are made,
we should modify the function that takes String1 object by reference as a parameter.
This prevents the destructor from being called multiple times for the same dynamically allocated memory.*/

#include <iostream>
#include <cstring>

class String1 {
private:
    char* c_string;

public:
    
    String1(const char* inputString) {
        
        c_string = new char[strlen(inputString) + 1];
        
        strcpy(c_string, inputString);
    }

  
    ~String1() {
        
        std::cout << "Destructor done" << std::endl;
        
        delete[] c_string;
    }

   
    void list() const {
        std::cout << "String: " << c_string << std::endl;
    }
};


void f(const String1& s) {
    s.list(); 
}


int main() {
    
    String1 s("abcdefg");

    s.list();

    f(s);

    s.list();

    return 0;
}


//task 4

#include <iostream>
#include <cstring>

class String1 {
    
private:
    char* c_string;

public:
   
    String1(const char* inputString) {
        
        c_string = new char[strlen(inputString) + 1];
        
        strcpy(c_string, inputString);
    }

   /*The copy constructor: 
   This ensures that the dynamically allocated memory is duplicated,
   and each object has its own copy of the string.
   Without the copy constructor, a shallow copy would be made, leading to double
   deletion of the same memory when both the original and the copy go out of scope.
   */
   
    String1(const String1& other) {
        
        c_string = new char[strlen(other.c_string) + 1];
        
        strcpy(c_string, other.c_string);
    }

    
    ~String1() {
       
        std::cout << "Destructor done" << std::endl;
       
        delete[] c_string;
    }


    void list() const {
        std::cout << "String: " << c_string << std::endl;
    }
};


void f(String1 s) {
    s.list(); 
}

int main() {
    
    String1 s("abcdefg");

    s.list();

    f(s);

    s.list();

    return 0;
}




