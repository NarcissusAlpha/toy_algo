/*
 * Merge Sort
 * Input: unsorted n-array A[0, ..., n-1]
 * Output: increasingly sorted A
 * 
 * Notice: Some lines are for output by printing. 
 */

#include <stdio.h>
#include <stdlib.h>

#define INPUT_TYPE int
#define PRINT_FORMAT "%i "
void PrintArray(INPUT_TYPE* array, int lenofArray)
{
    int i;
    printf("[");
    for(i = 0; i < lenofArray; ++ i)
    {
        printf(PRINT_FORMAT, array[i]);
    }
    printf("]\n");

    return;
}

INPUT_TYPE* Merge(INPUT_TYPE* B, INPUT_TYPE* C, int lenB, int lenC)
{
    int lenM = lenB + lenC;
    int sB = 0, sC = 0, sM = 0;
    INPUT_TYPE* mergedArray = malloc(sizeof(INPUT_TYPE) * lenM);

    // If B and C are not empty, compare elements and move the smaller one into mergedArray.
    // If B is not empty but C is, directly move the rest of B into mergedArray.
    while(sB < lenB)
    {
        if(sC == lenC || B[sB] < C[sC])
        {
            mergedArray[sM] = B[sB];
            sB += 1;
            sM += 1;
        }
        else
        {
            mergedArray[sM] = C[sC];
            sC += 1;
            sM += 1;
        }
    }
    // If B is already empty, directly move the rest of C into mergedArray.
    while(sC < lenC)
    {
        mergedArray[sM] = C[sC];
        sC += 1;
        sM += 1;
    }


    printf("Merge begin\n");
    PrintArray(B, lenB);
    PrintArray(C, lenC);
    printf("->");
    PrintArray(mergedArray, lenM);
    printf("Merge end\n\n");

    return mergedArray;
}

INPUT_TYPE* MergeSort(INPUT_TYPE* A, int lenA)
{
    // just return array A with length 1: [a0]
    if(lenA == 1) return A;

    // for array A with length > 1, divide it into B and C
    int lenB = lenA / 2;
    int lenC = lenA - lenB;
    int i;
    INPUT_TYPE* B = malloc(sizeof(INPUT_TYPE) * lenB);
    INPUT_TYPE* C = malloc(sizeof(INPUT_TYPE) * lenC);

    for(i = 0; i < lenA; ++ i)
    {
        if(i < lenB) B[i] = A[i];
        else C[i - lenB] = A[i];
    }

    printf("Split begin\n");  
    PrintArray(A, lenA);
    printf("->");
    PrintArray(B, lenB);
    PrintArray(C, lenC);
    printf("Split end\n\n");

    // recursively sort B and C, then merge the sorted B and C
    INPUT_TYPE* newB = MergeSort(B, lenB);
    INPUT_TYPE* newC = MergeSort(C, lenC);

    return Merge(newB, newC, lenB, lenC);
}


// To test, 
// 1. Change the definition of INPUT_LEN_B to the length of test input array.
// 2. Change the initialization form of B to the array you want.
// 3. Compile and run. 
#define INPUT_LEN_B 10
int main(void)
{
    INPUT_TYPE B[INPUT_LEN_B] = {-2, 6, 4, 2, 0, 8, 12, 0, -24, 5};

    INPUT_TYPE* mergedArray = MergeSort(B, INPUT_LEN_B);
    PrintArray(mergedArray, INPUT_LEN_B);

    return 0;
}
