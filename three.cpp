// C++ program to memoize
// recursive implementation of LCS problem
#include <bits/stdc++.h>
int arr[1000][1000];
int max(int a, int b);

// Returns length of LCS for X[0..m-1], Y[0..n-1] */
// memoization applied in recursive solution
int lcs(char *X, char *Y, int m, int n)
{
    // base case
    if (m == 0 || n == 0)
        return 0;

    // if the same state has already been
    // computed
    if (arr[m - 1][n - 1] != -1)
        return arr[m - 1][n - 1];

    // if equal, then we store the value of the
    // function call
    if (X[m - 1] == Y[n - 1])
    {

        // store it in arr to avoid further repetitive
        // work in future function calls
        arr[m - 1][n - 1] = 1 + lcs(X, Y, m - 1, n - 1);
        return arr[m - 1][n - 1];
    }
    else
    {
        // store it in arr to avoid further repetitive
        // work in future function calls
        arr[m - 1][n - 1] = max(lcs(X, Y, m, n - 1),
                                lcs(X, Y, m - 1, n));
        return arr[m - 1][n - 1];
    }
}

// Utility function to get max of 2 integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Driver Code
int main()
{
    memset(arr, -1, sizeof(arr));
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS is %d", lcs(X, Y, m, n));

    return 0;
}
