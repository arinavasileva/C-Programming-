//TASK 1, 2, 3, 4 (total 4 KPL)
// Task 1
// Write a function
// int *allocate_table(int n);
// which reserves an integer array of the given size (n).
//Function returns a pointer to the beginning of the table.


#include <iostream>

using namespace std;

int *allocate_table(int n);

int main() {
    
    int array_size;
    std::cout << "Enter the size of the array, for example 6:";
    std::cin >> array_size;
    
    int *theGivenArray = allocate_table(array_size);
    
    std::cout << "Array is built successfully : " << theGivenArray << std::endl;
    
    delete[] theGivenArray;
    
    return 0;
}

int *allocate_table(int n) {
    
    int *array = new int [n];
    
    // returning a pointer to the beginning 
    
    return array;
    
}
