#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of scalar multiplications needed to multiply the chain of matrices
int matrixChainOrder(int p[], int n) {
    int m[n][n]; // Array to store the minimum number of scalar multiplications needed
    
    // Initialize the m[i][i] entries to 0 as multiplying one matrix doesn't cost anything
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // 'l' is the chain length
    for (int l = 2; l < n; l++) /*Outer loop (L): Iterates over different lengths of matrix chains.*/
     { 
        for (int i = 1; i < n - l + 1; i++) /*Inner loop (i): Iterates over all possible starting indices of these chains.*/
        {
            int j = i + l - 1; /*Ending index (j): Calculates the ending index based on the current starting index and chain length.*/
            
            m[i][j] = INT_MAX; // Set the minimum value initially to the maximum possible integer



//             i: Starting index of the current subsequence of matrices.
// j: Ending index of the current subsequence of matrices.
// k: The position where the current subsequence can be split into two parts.
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1]; // Return the minimum number of scalar multiplications needed
}

/*
For a concrete example, consider 4 matrices with dimensions given by array p[] = {1, 2, 3, 4, 5}, corresponding to matrices:

A1: 1x2
A2: 2x3
A3: 3x4
A4: 4x5
The m table will be filled as follows:

m[1][1], m[2][2], m[3][3], m[4][4] are all 0 (single matrices).
For chain length 2, compute m[1][2], m[2][3], and m[3][4].
For chain length 3, compute m[1][3] and m[2][4].
For chain length 4, compute m[1][4].
After filling the table, m[1][4] will contain the minimum number of scalar multiplications needed to multiply matrices A1, A2, A3, and A4.
*/
int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int arr[n + 1]; // Array to store dimensions of matrices
    printf("Enter the dimensions of matrices (separate by space): ");
    for (int i = 0; i <= n; i++)
        scanf("%d", &arr[i]);

    printf("Minimum number of multiplications is %d\n", matrixChainOrder(arr, n + 1));

    return 0;
}