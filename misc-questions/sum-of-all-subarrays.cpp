/* 
Sum of all Subarrays

Given an array a[] of size n. Output sum of each subarray of the given array.
*/
#include <iostream>

using namespace std;

void displayArr(int arr[], int n, int s = 0){
    for(int i = s; i < n ;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sumOfAllSubarrays(int arr[], int n){
    int result = 0;
    for(int i = 0; i < n ;i++){
        int sum = 0;
        cout << "Sub-Array: ";
        displayArr(arr, n, i);
        for(int j = i; j < n; j ++){
            cout << "Sum of ";
            displayArr(arr, j+1, i);
            sum = sum + arr[j];
            cout << sum << endl;
        }
        cout << endl;
    }
}

int main() {
    int n = 3;
    int arr[10] = {1 ,2 ,2};
    cout << "Initial Array: ";
    displayArr(arr, n);
    cout << "Result: " << endl;
    sumOfAllSubarrays(arr, n);
    return 0;
}
