// sort it according to second element (increasing)
// if second element is same sort it according to the fist element (decreasing)

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool mysort(pair <int, int> p1, pair <int, int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    if(p1.second = p2.second){
        if(p1.first > p2.first) return true;
        else return false;
    }
}

void displayPair(vector<pair <int, int>> p){
    for(auto it: p){
        cout << it.first << " " << it.second << endl;
    }
}

int main() {
    vector<pair <int, int>> p = {
        {1, 2},
        {2, 1},
        {4, 1},
        {3, 5},
        {2, 3},
        {7, 5}
    };
    cout << "Sorting" << endl;
    displayPair(p);
    
    sort(p.begin(), p.end(), mysort);
    
    cout << "After Sorting: " << endl;
    displayPair(p);
    return 0;
}
