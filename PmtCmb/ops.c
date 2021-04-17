#include <stdio.h>
#include "env.h"
#include "ops.h"
void printPermutations(int n, int *bucket, int bucketSize, int k)
{
    int i, lastIdx, smallest, item;
    if (k == 0)
    { // nP0은 그냥 싹다 출력하는 경우의 수임.
        for (i = 0; i < bucketSize; i++)
        {
            printf("%d ", bucket[i]);
        }
        printf("\n");
        return;
    }
    lastIdx = bucketSize - k - 1;
    smallest = 0;

    for (item = smallest; item < n; item++)
    {
        int chosen = FALSE;
        for (int j = 0; j <= lastIdx; j++)
        {
            if (bucket[j] == item)
            {
                chosen = TRUE;
                break;
            }
        }

        if (chosen)
            continue;
        bucket[lastIdx + 1] = item;
        printCombinations(n, bucket, bucketSize, k - 1); // 1개를 뽑았으므로 k-1개 뽑기
    }
}

void printCombinations(int n, int *bucket, int bucketSize, int k)
{
    int i, lastIdx, smallest, item;
    if (k == 0)
    { // nC0은 그냥 싹다 출력하는 경우의 수임.
        for (i = 0; i < bucketSize; i++)
        {
            printf("%d ", bucket[i]);
        }
        printf("\n");
        return;
    }
    lastIdx = bucketSize - k - 1;
    if (bucketSize == k)
    {
        smallest = 0;
    }
    else
    {
        smallest = bucket[lastIdx] + 1;
    }

    for (item = smallest; item < n; item++)
    {
        bucket[lastIdx + 1] = item;
        printCombinations(n, bucket, bucketSize, k - 1); // 1개를 뽑았으므로 k-1개 뽑기
    }
}