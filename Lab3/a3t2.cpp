/******************************************************************************
Write a function
void read_values(int *t, int n);
which reads to the array given as a parameter integers from the keyboard
(n is the size of the array).
*******************************************************************************/

#include <iostream>

using namespace std;

void read_values(int *t, int n);

int main() {
    int array_size;
    std::cout << "Enter the size of the array, for instance 7: ";
    std::cin >> array_size;
    
    int *theGivenArray = new int(array_size);
     
    read_values(theGivenArray, array_size);
    
    std::cout << "Here are the values in the array: ";
    for (int i =0; i < array_size; i++) {
    std::cout << theGivenArray[i] << " ";
    }
    std::cout << std::endl;
    
    delete[] theGivenArray;

    return 0;
    
}

void read_values(int *t, int n) {
    std::cout << "Enter " << n << " integers:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter value for index " << i << ": ";
        std::cin >> t[i];
    }
}
