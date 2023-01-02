#include<iostream>
using namespace std;

void printArray(int arr[]){
    for(int i = 0; i < 6; i++){
        cout << arr[i] << " ";
    }
}

void selectionSort(int arr[], int n){
  int temp = 0;
  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
        if(arr[i] > arr[j]){
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
  }
}

int main{
  int arr[] = {5, 6, 2, 9, 7, 1};
    cout<<"Sort {5, 6, 2, 9, 7, 1}: "<<endl;
    selectionSort(arr, 0, 6);
    printArray(arr);
  return 0;
}
