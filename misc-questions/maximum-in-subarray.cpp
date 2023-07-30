//Given an array a[] of size n. For every i from 0 to n-1 output max(a[0], a[1],..., a[i]).
#include <iostream>
#include <climits>
using namespace std;

void displayArr(int arr[], int n){
    for(int i = 0; i < n ;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void maxInSubArray(int arr[], int n){
    int result[n];
    int maxElement = INT_MIN;
    for(int i = 0; i < n; i++){
        maxElement = max(maxElement, arr[i]);
        result[i] = maxElement;
    }
    displayArr(result, n);
}

int main() {
    int n = 10;
    int arr[10] = {10, 33, 22, 69, 2, 4, 1, 70, 500, 9};
    cout << "Initial Array: ";
    displayArr(arr, n);
    cout << " Result Array: ";
    maxInSubArray(arr, n);
    return 0;
}
