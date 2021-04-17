#include <stdio.h>
#include <stdlib.h>
#include "env.h"
#include "ops.h"

int main()
{
    int n, k, i;
    printf("n : ");
    scanf("%d", &n);
    printf("k : ");
    scanf("%d", &k);

    int *bucket = (int *)malloc(k * sizeof(int));

    printf("<%dP%d (총 %d개)>\n", n, k, getFactorial(n) / getFactorial(n - k));
    printPermutations(n, bucket, k, k);
    printf("\n\n");
    printf("<%dC%d (총 %d개)>\n", n, k, getFactorial(n) / (getFactorial(k) * getFactorial(n - k)));
    printCombinations(n, bucket, k, k);

    free(bucket);
    return 0;
}