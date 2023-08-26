#include <bits/stdc++.h>
using namespace std;

// Function to find GCD(Greatest Common Divisor) of number
int gcd(int n1, int n2){
    int gcd = 1;
    int n = n1 < n2 ? n1 : n2;
    for(int i = n; i >= 2; i--){
        if(n1 % i == 0 && n2 % i == 0){
          gcd = i;
          break;
        }
    }
    
    return gcd;
}

// Function to find GCD(Greatest Common Divisor) of number using euclidean algorithm
int gcd_euclidean(int n1, int n2){
    if(n1 == 0) return n2;
    if(n2 == 0) return n1;
    
    int greater_num = n1 > n2 ? n1 : n2;
    int smaller_num = n1 < n2 ? n1 : n2;
    
    int rem = greater_num % smaller_num;
    return gcd_euclidean(rem, smaller_num);
}

// Driver Program
int main()
{
	cout << gcd(36, 14) << endl;
  cout << gcd_euclidean(36, 14) << endl;
	
	return 0;
}
