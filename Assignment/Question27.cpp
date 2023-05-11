// Implement the matrix chain multiplication problem using dynamic programming in
// C++. Analyze the time and space complexity of your implementation and
// compare it with the time and space complexity of a naive recursive implementation.


/*
Follow the below steps to solve the problem:

* Build a matrix dp[][] of size N*N for memoization purposes.
* Use the same recursive call as done in the above approach:
    * When we find a range (i, j) for which the value is already calculated, return the minimum value for that range (i.e., dp[i][j]).
    * Otherwise, perform the recursive calls as mentioned earlier.
* The value stored at dp[0][N-1] is the required answer.

*/

// C++ program using memoization
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];

// Function for matrix chain multiplication
int matrixChainMemoised(int* p, int i, int j)
{
	if (i == j)
	{
		return 0;
	}
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	dp[i][j] = INT_MAX;
	for (int k = i; k < j; k++)
	{
		dp[i][j] = min(
			dp[i][j], matrixChainMemoised(p, i, k)
					+ matrixChainMemoised(p, k + 1, j)
					+ p[i - 1] * p[k] * p[j]);
	}
	return dp[i][j];
}
int MatrixChainOrder(int* p, int n)
{
	int i = 1, j = n - 1;
	return matrixChainMemoised(p, i, j);
}

// Driver Code
int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	memset(dp, -1, sizeof dp);

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr, n);
}

/*
Time Complexity: O(N3 )
Auxiliary Space: O(N2) ignoring recursion stack space
*/

/*
Follow the steps mentioned below to implement the approach:

Create a recursive function that takes i and j as parameters that determines the range of a group.
Iterate from k = i to j to partition the given range into two groups.
Call the recursive function for these groups.
Return the minimum value among all the partitions as the required minimum number of multiplications to multiply all the matrices of this group.
The minimum value returned for the range 0 to N-1 is the required answer.
*/

// C++ code to implement the
// matrix chain multiplication using recursion

// #include <bits/stdc++.h>
// using namespace std;

// // Matrix Ai has dimension p[i-1] x p[i]
// // for i = 1 . . . n
// int MatrixChainOrder(int p[], int i, int j)
// {
// 	if (i == j)
// 		return 0;
// 	int k;
// 	int mini = INT_MAX;
// 	int count;

// 	// Place parenthesis at different places
// 	// between first and last matrix,
// 	// recursively calculate count of multiplications
// 	// for each parenthesis placement
// 	// and return the minimum count
// 	for (k = i; k < j; k++)
// 	{
// 		count = MatrixChainOrder(p, i, k)
// 				+ MatrixChainOrder(p, k + 1, j)
// 				+ p[i - 1] * p[k] * p[j];

// 		mini = min(count, mini);
// 	}

// 	// Return minimum count
// 	return mini;
// }

// // Driver Code
// int main()
// {
// 	int arr[] = { 1, 2, 3, 4, 3 };
// 	int N = sizeof(arr) / sizeof(arr[0]);

// 	// Function call
// 	cout << "Minimum number of multiplications is "
// 		<< MatrixChainOrder(arr, 1, N - 1);
// 	return 0;
// }

/*
The time complexity of the solution is exponential
Auxiliary Space: O(1)
*/

/*

In comparison, a naive recursive implementation of the matrix chain multiplication problem has a time complexity of O(2^n) and a space complexity of O(n), since it recursively computes all possible solutions for the subproblems. Therefore, the dynamic programming implementation is much more efficient for larger problem sizes.

*/