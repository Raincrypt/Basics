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
    cout << endl << endl;
    return arr;
}

int binarySearch(int arr[], int size, int target){
    sort(arr, size);
    int left = 0;
    int right = size - 1;
    
    while(left <= right){
        int mid = (right + left) / 2;
        cout << "Mid Position: " << mid << endl;
        if(arr[mid]==target){
            cout << "Position: " << mid << endl;
            return 1;
        }
        else if(target > arr[mid]){
            cout << "Comparison: " << arr[mid] << " < " << target <<endl;
            cout << "Position: " << left << ", " << right << endl;
            cout << "element should be between: "<< arr[left] << " and " << arr[right] << endl << endl;
            left = mid;
            left++;
        }
        else if(target < arr[mid]){
            cout << "Comparison: " << arr[mid] << " > " << target <<endl;
            cout << "Position: " << left << ", " << right << endl;
            cout << "element should be between: "<< arr[left] << " and " << arr[right] << endl << endl;
            right = mid;
            right--;
        }
    }
    return -1;
}

int main() {
    int n = 10;
    int arr[n] = {4, 5, 2, 7, 10, 33, 22, 99, 0, 110};
    int target = 22;
    int result = binarySearch(arr, n, target);
    if(result == -1) cout<< target <<" Doesn't exist" << endl;
    else cout << target << " exists in the array." << endl;
    return 0;
}
