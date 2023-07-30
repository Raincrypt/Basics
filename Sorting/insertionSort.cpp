#include <iostream>
using namespace std;

void displayArr(int arr[], int n){
    for(int i = 0; i < n ;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int arr[], int n){
    
    for(int i = 1; i < n; i++){
        int current = arr[i];
        int j = i - 1;
        while(arr[j] > current && j >= 0){
            swap(arr[j], arr[j + 1]);
            current = arr[j];
            j--;
        }
    }
    cout << "Final Array: ";
    displayArr(arr, n);
}

int main() {
    int n = 7;
    int arr[7] = {2, 3, 4, 1, 7, 5, 9};
    cout << "Initial Array: ";
    displayArr(arr, n);
    cout << endl;
    
    insertionSort(arr, n);
    return 0;
}
