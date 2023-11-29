/******************************************************************************

Assignment 5 

*******************************************************************************/

// A

#include <iostream>
#include <cstring> 

class String {
private:
    char* data;

public:
    
    String(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    String(const String& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    ~String() {
        delete[] data;
    }

    
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    
    String operator+(const String& other) const {
        String result;
        result.data = new char[strlen(data) + strlen(other.data) + 1];
        strcpy(result.data, data);
        strcat(result.data, other.data);
        return result;
    }

    
    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.data;
        return os;
    }
};

int main() {
    String s1("abcdef");
    String s2("ghijklmn");
    String sum;

    std::cout << "String 1 is: " << s1 << std::endl;
    std::cout << "String 2 is: " << s2 << std::endl;

    // Testing assignment operator
    sum = s1 + s2;
    std::cout << "Sum is: " << sum << std::endl; // Output: abcdefghijklmn

    // Testing self-assignment
    sum = sum;
    std::cout << "Sum is still: " << sum << std::endl; // Output: abcdefghijklmn

    return 0;
}

//B


//B1

#include <iostream>
#include <cstring>

class String {
private:
    char* data;

public:
    // Constructors and Destructor
    String(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    String(const String& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    ~String() {
        delete[] data;
    }

    // Assignment operator
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Addition operator
    String operator+(const String& other) const {
        String result;
        result.data = new char[strlen(data) + strlen(other.data) + 1];
        strcpy(result.data, data);
        strcat(result.data, other.data);
        return result;
    }

    // Indexing operator
    char& operator[](int index) {
        return data[index];
    }

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.data;
        return os;
    }

    // Pre-increment operator (++s)
    String& operator++() {
        char* newData = new char[strlen(data) + 2];
        strcpy(newData, data);
        strcat(newData, "X");
        delete[] data;
        data = newData;
        return *this;
    }

    // Post-increment operator (s++)
    String operator++(int) {
        String temp(*this);
        char* newData = new char[strlen(data) + 2];
        strcpy(newData, data);
        strcat(newData, "X");
        delete[] data;
        data = newData;
        return temp;
    }
};

int main() {
    String s("abcdefg");

    // Testing post-increment operator
    std::cout << s++ << std::endl;

    // Testing pre-increment operator
    std::cout << ++s << std::endl;

    return 0;
}


//B2

#include <iostream>
#include <cstring>

class String {
private:
    char* data;

public:
    // Constructors and Destructor
    String(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    String(const String& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    ~String() {
        delete[] data;
    }

    // Assignment operator
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Addition operator
    String operator+(const String& other) const {
        String result;
        result.data = new char[strlen(data) + strlen(other.data) + 1];
        strcpy(result.data, data);
        strcat(result.data, other.data);
        return result;
    }

    // Indexing operator
    char& operator[](int index) {
        return data[index];
    }

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.data;
        return os;
    }
};

int main() {
    String s("abcdefg");

    
    std::cout << "Original String: ";
    for (int i = 0; i < 7; i++)
        std::cout << s[i] << " ";
    std::cout << std::endl;

    // Modifying a character 
    s[4] = 'X';

    // Testing indexing operator after modification
    std::cout << "Modified String: ";
    for (int i = 0; i < 7; i++)
        std::cout << s[i] << " ";
    std::cout << std::endl;

    return 0;
}

