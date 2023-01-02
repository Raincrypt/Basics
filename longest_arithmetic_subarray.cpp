#include<iostream>
using namespace std;

void printArray(int arr[]){
    for(int i = 0; i < 6; i++){
        cout << arr[i] << " ";
    }
}

int main(){
  int n = max(0, 5);
  cout << n;
  return 0;
}
