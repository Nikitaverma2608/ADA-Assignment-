//Implement a dynamic programming algorithm for the Longest Common Subsequence Problem (LCS), and analyze //its time and space complexity using Big-O notation

/*
The longest common subsequence (LCS) is defined as the longest subsequence that is common to all the given sequences, provided that the elements of the subsequence are not required to occupy consecutive positions within the original sequences.

If S1 and S2 are the two given sequences then, Z is the common subsequence of S1 and S2 if Z is a subsequence of both S1 and S2. Furthermore, Z must be a strictly increasing sequence of the indices of both S1 and S2.

In a strictly increasing sequence, the indices of the elements chosen from the original sequences must be in ascending order in Z.
*/

#include <iostream>
#include <cstring>
using namespace std;

int lcs(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s1, s2;
    cout << "Enter string 1: ";
    cin >> s1;
    cout << "Enter string 2: ";
    cin >> s2;
    cout << "Length of LCS: " << lcs(s1, s2) << endl;

    return 0;
}

/*
This implementation uses a 2D array dp to store the lengths of the longest common subsequences of prefixes of the two input strings. The base cases are when either string is empty, in which case the length of the LCS is 0. For the general case, if the last characters of the two strings match, the LCS is the LCS of the prefixes without those characters plus one. Otherwise, the LCS is the maximum of the LCS of the first string without its last character and the second string, and the LCS of the second string without its last character and the first string.

The time complexity of this algorithm is O(mn), where m and n are the lengths of the input strings. This is because the algorithm fills in a table of size O(mn), and each cell of the table takes constant time to compute. The space complexity is also O(mn), since the table requires O(mn) space.

Note that there are more space-efficient algorithms for the LCS problem that use only O(min(m, n)) space, but their time complexity is still O(mn).  */