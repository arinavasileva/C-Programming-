/******************************************************************************

TASK 1, 2, 3, 4 (total 4 KPL)

Task 3
Write a function
void reverse(int *t, int n);
which reverses the values in the given array to opposite order (n is the size of the array).



*******************************************************************************/
#include <iostream>

using namespace std;

void reverse(int *t, int n);

int main() {
    const int array_size = 7;
    int theOriginalArray[array_size] = {1, 2, 3, 4, 5, 6, 7};

    
    std::cout << "Original array: ";
    for (int i = 0; i < array_size; ++i) {
        std::cout << theOriginalArray[i] << " ";
    }
    std::cout << std::endl;

    
    reverse(theOriginalArray, array_size);

    
    std::cout << "Modified (reversed) array: ";
    for (int i = 0; i < array_size; ++i) {
        std::cout << theOriginalArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

void reverse(int *t, int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        
        int temp = t[start];
        t[start] = t[end];
        t[end] = temp;

        
        start++;
        end--;
    }
}
