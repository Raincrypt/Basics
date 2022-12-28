#include <bits/stdc++.h>
using namespace std;

/*
void reverseStr(string& str)
{
    int n = str.length();
 
    // Swap character starting from two corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
*/

int main()
{
    string s = "GeeksforGeeks";
    stack<char> st;
    for (char x : s)
        st.push(x);
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    return 0;
}
