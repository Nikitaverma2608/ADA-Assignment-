//Implement the Fibonacci sequence using dynamic programming in C++ Analyze the time complexity of your implementation and compare it with the time complexity of a recursive implementation.


/*Here's an implementation of the Fibonacci sequence using dynamic programming in C++:*/

#include <iostream>
using namespace std;

int fib(int n) {
    int memo[n+1];  // to store previously computed values
    memo[0] = 0;    // base case
    memo[1] = 1;    // base case

    for (int i = 2; i <= n; i++) {
        memo[i] = memo[i-1] + memo[i-2]; // compute Fibonacci number
    }

    return memo[n]; // return the nth Fibonacci number
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "The " << n << "th Fibonacci number is: " << fib(n) << endl;
    return 0;
}

/*
The time complexity of this implementation is O(n), since we only need to compute each Fibonacci number once and store it in the memo array for later use.*/

/*Now let's compare this to a recursive implementation: */


// #include <iostream>
// using namespace std;

// int fib(int n) {
//     if (n <= 1) {
//         return n; // base case
//     }
//     return fib(n-1) + fib(n-2); // recursive case
// }

// int main() {
//     int n;
//     cout << "Enter n: ";
//     cin >> n;
//     cout << "The " << n << "th Fibonacci number is: " << fib(n) << endl;
//     return 0;
// }

/*
The time complexity of this implementation is O(2^n), since we need to compute each Fibonacci number by recursively computing two smaller Fibonacci numbers, and we end up repeating a lot of work. As n grows larger, the recursive implementation quickly becomes impractical, while the dynamic programming implementation remains efficient.
*/



