#include <bits/stdc++.h>
using namespace std;

// Function to print all divisors
int print_all_divisors(int n){
    for(int i = 1; i <= n; i++){
        if(n % i == 0) cout << i << " ";
    }
    cout << endl;
}

// Driver Program
int main()
{
	int x = 36;
	print_all_divisors(x);
	return 0;
}
