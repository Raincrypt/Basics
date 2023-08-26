#include <bits/stdc++.h>
using namespace std;

// Function to print all divisors (Time Complexity: O(n))
#include <bits/stdc++.h>
using namespace std;

// Function to print all divisors (Time Complexity: O(n))
void print_all_divisors(int n){
    for(int i = 1; i <= n; i++){
        if(n % i == 0) cout << i << " ";
    }
    cout << endl;
}

// Optimised (Time Complexity: O(sqrt(n))
void print_all_divisors_optimised(int n){
    vector<int> divisors;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0) divisors.emplace_back(i);
        if(n / i != i) divisors.emplace_back(n / i);
    }
    sort(divisors.begin(), divisors.end());
    for(auto divisor: divisors) cout << divisor << " ";
    cout << endl;
}

// Driver Program
int main()
{
	int x = 36;
	print_all_divisors(x);
	
	print_all_divisors_optimised(x);
	return 0;
}
