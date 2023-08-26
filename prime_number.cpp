#include <bits/stdc++.h>
using namespace std;

// Function to find if the number is prime or not
bool is_prime(int n){
    if(n == 1) return true;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

// Driver Program
int main()
{
	cout << boolalpha << is_prime(36) << endl;
	cout << boolalpha << is_prime(19) << endl;
	
	return 0;
}
