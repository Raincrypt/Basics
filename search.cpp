// Always Applied to a sorted array

#include <iostream>
using namespace std;

int* sort(int arr[], int size){
    cout << "Sorted Array: ";
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        cout << arr[i] << " ";
    }
    cout << endl;
    return arr;
}

int binarySearch(int arr[], int size, int target){
    sort(arr, size);
    int left = 0;
    int right = size - 1;
    
    while(left < right){
        int mid = (left + right) / 2;
        if(arr[mid]!=target){
            if(target > arr[mid]){
                left = mid;
                mid = (left + right)/2 + 1;
                cout << "element should be between: "<< arr[left] << " and " << arr[right] << endl;
                if(target == arr[mid]) return mid;
                left+=1;
            }
            else if(target < arr[mid]){
                right = mid;
                mid = (left + right)/2 + 1;
                cout << "element should be between: "<< arr[left] << " and " << arr[right] << endl;
                if(target == arr[mid]) return mid;
                right-=1;
            }
            else return -1;
        }
        else return 1;
    }
    return -1;
}

int main() {
    int n = 10;
    int arr[n] = {4, 5, 2, 7, 10, 33, 22, 99, 0, 110};
    int target = 23;
    int result = binarySearch(arr, n, target);
    if(result == -1) cout<<"Doesn't exist" << endl;
    else cout << target << " exists in the array." << endl;
    return 0;
}
