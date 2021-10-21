/*
 * Input: Integer array A[0, 1, ..., n-1]
 * Output: non-decreasingly sorted A
 *
 * Notice: this is a special case of BucketSort; here each bucket contains only one value.
 */
#include <stdio.h>
#include <stdlib.h>

int* DistributionCountingSort(int* A, int lenA, int lowA, int upA)
{
    // Initialize
    int lenD = upA - lowA + 1;
    int i, j;
    int* D = malloc(sizeof(int) * lenD);
    int* newA = malloc(sizeof(int) * lenA);
    for(i = 0; i < lenD; ++ i)
    {
        D[i] = 0;
    }

    // Count the number of each value in A
    // Now D is histogram
    for(i = 0; i < lenA; ++ i)
    {
        D[A[i] - lowA] += 1;
    }
    // Convert D into distribution
    for(i = 1; i < lenD; ++ i)
    {
        D[i] = D[i] + D[i - 1];
    }

    // For each elements in A,  A[i]: 
    // D[A[i]] shows the index of place that A[i] should be put in sorted newA 
    for(i = 0; i < lenA; ++ i)
    {
        j = A[i] - lowA;
        newA[D[j] - 1] = A[i];
        D[j] -= 1;
    }

    return newA;
}

void PrintArray(int* A, int lenA)
{
    int i;
    printf("[");
    for(i = 0; i < lenA; ++ i)
    {
        printf("%i, ", A[i]);
    }
    printf("]\n");

    return;
}

#define TEST_INPUT_LEN 9

int main(void)
{
    int A[TEST_INPUT_LEN] = {9, -1, -5, -5, 3, 0, 7, 3, 3};
    int lowA = -5;
    int upA = 9;
    PrintArray(A, TEST_INPUT_LEN);
    int* newA = DistributionCountingSort(A, TEST_INPUT_LEN, lowA, upA);
    PrintArray(newA, TEST_INPUT_LEN);

    return 0;
}