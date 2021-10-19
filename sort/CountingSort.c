/*
 * Counting Sort
 * Input : intiger array A[0, 1, ..., n-1]
 * Output: non-decreasedly sorted A
 * 
 * notice: it is like a match for many teams, where each pair will have one and only one game without tie, 
 *         then all teams will be ranked by the number of winning. 
 *         Here the strength of teams are so different that if a wins b and b wins c then a must win c.
 */

#include <stdio.h>
#include <stdlib.h>

int* CountingSort(int* A, int lenA)
{
    int* count = malloc(sizeof(int) * lenA);
    int* newA = malloc(sizeof(int) * lenA);
    int i, j;
    for(i = 0; i < lenA; ++ i) count[i] = 0;

    // For each element A[i], count the number of "elements not bigger than A[i]", and save it in count[i].
    // Values in count[] are distinct. If several elements have the same value, element with smaller index will have more count.
    // e.g.: for n = 4, A[0, 1, 2, 3] = {2, 0, 0, -1}.
    //       for i = 0, A[0] = 2, j = 123, 
    //          count[0] + 1, 
    //          count[0] + 1, 
    //          count[0] + 1;
    //       for i = 1, A[1j = 0, j = 23, 
    //          count[2] + 1 (because A[1] = 0 >= 0 = A[2]), 
    //          count[1] + 1;
    //       for i = 2, A[2] = 0, j = 3, count[2] + 1;
    //       for i = 3, A[3] = -1, but j = 4 makes it stop.
    // Thus, changing A[i] < A[j] into <= makes the element with bigger index have more count, if more than one element have same value. The result keeps correct.
    for(i = 0; i < lenA - 1; ++ i)
    {
        for(j = i + 1; j < lenA; ++ j)
        {
            if(A[i] < A[j]) count[j] += 1;
            else count[i] += 1;
        }
    }

    for(i = 0; i < lenA; ++ i)
    {
        newA[count[i]] = A[i];
    }

    return newA;
}

void PrintArray(int* A, int lenA)
{
    int i;
    printf("[");
    for(i = 0; i < lenA; ++ i)
    {
        printf("%i ", A[i]);
    }
    printf("]\n");

    return;
}

#define TEST_INPUT_LEN 8

int main(void)
{
    int testArray[TEST_INPUT_LEN] = {6, 3, 4, 2, 5, -1, 0, 0};

    PrintArray(testArray, TEST_INPUT_LEN);

    int* sortedArray = CountingSort(testArray, TEST_INPUT_LEN);

    PrintArray(sortedArray, TEST_INPUT_LEN);

    return 0;
}