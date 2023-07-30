/* 
Sum of all Subarrays

Given an array a[] of size n. Output sum of each subarray of the given array.
*/

#include <iostream>

using namespace std;

void displayArr(int arr[], int n){
    for(int i = 0; i < n ;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sumOfAllSubarrays(int arr[], int n){
    int result = 0;
    for(int i = 0; i < n ;i++){
        int sum = 0;
        for(int j = 0; j <= i; j ++){
            sum = sum + arr[j];
        }
        cout << sum << " ";
    }
}

int main() {
    int n = 10;
    int arr[10] = {10, 33, 22, 69, 2, 4, 1, 70, 500, 9};
    cout << "Initial Array: ";
    displayArr(arr, n);
    cout << " Result Array: ";
    sumOfAllSubarrays(arr, n);
    return 0;
}
