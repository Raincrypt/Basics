#include <iostream>
using namespace std;

int reverseNum(int num){
     int n = num, rev = 0, digit;

     while (num > 0){
         digit = num % 10;
         rev = (rev * 10) + digit;
         num = num / 10;
     } 
     return rev;
}

int main()
{
     int num, rev = 0;

     cout << "Enter a positive number: ";
     cin >> num;

     rev = reverseNum(num);

     cout << " The reverse of the number is: " << rev << endl;

     if (num == rev)
         cout << " The number is a palindrome.";
     else
         cout << " The number is not a palindrome.";

    return 0;
}
