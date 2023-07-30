// Always Applied to a sorted array

#include <iostream>
using namespace std;

int* sort(int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

void binarySearch(int arr[], int size, int target){
    sort(arr, size);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 10;
    int arr[n] = {4, 5, 2, 7, 10, 33, 22, 99, 0, 100};
    int target = 22;
    binarySearch(arr, n, target);
    return 0;
}
