#include<iostream>
using namespace std;

void printArray(int arr[]){
    for(int i = 0; i < 6; i++){
        cout << arr[i] << " ";
    }
}

void selectionSort(int arr[], int n){
  
}

int main{
  int arr[] = {5, 6, 2, 9, 7, 1};
    cout<<"Sort {5, 6, 2, 9, 7, 1}: "<<endl;
    selectionSort(arr, 0, 5);
    printArray(arr);
  return 0;
}
