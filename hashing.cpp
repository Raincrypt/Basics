#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void frequency(vector<int>& arr){
    unordered_map<int, int> mp;
    
    // Updating Frequency in the map
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
        mp[arr[i]]++;
    }
    cout << endl;
    int max = 0, num_max;
    
    // printing Key(number) and Value(frequency)
    for(auto it: mp){
        cout << it.first << " Appears => " << it.second << endl;
        
        // Storing the max frequency and corresponding key
        if(max < it.second) {
            max = it.second;
            num_max = it.first;
        }
    }
    cout << num_max << " Appeared Maximum time that is " << max << endl;
}

int main() {
    vector<int> arr = {1, 2, 5, 5, 2, 5, 12, 41, 3, 7, 19, 41, 50};
    int n = 41;
    frequency(arr);

    return 0;
}
