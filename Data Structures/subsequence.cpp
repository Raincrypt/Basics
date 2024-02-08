// Recursion Basic... IMPORTANT

#include <bits/stdc++.h>
#include <math.h>
#include "aaHelper.h"
using namespace std;

// Time Complexity: O(2 ^ n)
void subsequence(vector<int> &arr, int index, vector<int> &subArr, vector<vector<int>> &result)
{

    // Base Case
    if (index == arr.size())
    {
        result.push_back(subArr);
        return;
    }

    // Take or pick the particular index into the subsequence
    subArr.push_back(arr[index]);
    subsequence(arr, index + 1, subArr, result);
    subArr.pop_back();

    // Not take or not pick the particular index into the subsequence
    subsequence(arr, index + 1, subArr, result);
}

int main()
{
    vector<int> arr = {2, 7, 9};
    vector<int> subArr;
    vector<vector<int>> result;

    subsequence(arr, 0, subArr, result);
    printVec2D(result);

    return 0;
}
