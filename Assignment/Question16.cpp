//Implement a divide-and-conquer algorithm for multiplying two large integers.


/*To multiply two large integers using divide-and-conquer approach, we can use the Karatsuba algorithm.

The steps of Karatsuba algorithm are as follows:

Divide both integers into two equal halves, a and b for the first integer and c and d for the second integer.
Recursively compute three products: ac, bd and (a+b)*(c+d).
The product of the two integers can be computed as ac * 10^n + (a+b)*(c+d) * 10^(n/2) + bd, where n is the number of digits in the input integers.
Here's an implementation of Karatsuba algorithm in C++:

*/

#include <iostream>
#include <string>

using namespace std;

string karatsuba(string num1, string num2) {
    int len1 = num1.length();
    int len2 = num2.length();

    if (len1 == 0 || len2 == 0) {
        return "0";
    }

    if (len1 == 1 && len2 == 1) {
        int n1 = num1[0] - '0';
        int n2 = num2[0] - '0';
        return to_string(n1 * n2);
    }

    int n = max(len1, len2);
    int half = n / 2;

    string a = num1.substr(0, len1 - half);
    string b = num1.substr(len1 - half, half);
    string c = num2.substr(0, len2 - half);
    string d = num2.substr(len2 - half, half);

    string ac = karatsuba(a, c);
    string bd = karatsuba(b, d);
    string abcd = karatsuba(to_string(stoll(a) + stoll(b)), to_string(stoll(c) + stoll(d)));

    string adbc = to_string(stoll(abcd) - stoll(ac) - stoll(bd));

    string result = ac;
    for (int i = 0; i < 2 * half; i++) {
        result += "0";
    }

    string temp = adbc;
    for (int i = 0; i < half; i++) {
        temp += "0";
    }
    result = to_string(stoll(result) + stoll(temp));

    result = to_string(stoll(result) + stoll(bd));

    return result;
}

int main() {
    string num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    string result = karatsuba(num1, num2);

    cout << "Product of " << num1 << " and " << num2 << " is " << result << endl;

    return 0;
}

/*
This algorithm has a time complexity of O(n^log2(3)) which is faster than the conventional O(n^2) algorithm for multiplying two n-digit numbers.*/