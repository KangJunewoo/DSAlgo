void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getFactorial(int x)
{
    // 블로그엔 이렇게 나와있었지만 재귀보단 반복이 빠를듯.
    // if (x == 0)
    //     return 1;
    // return x * getFactorial(x - 1);

    if (x == 0)
        return 1;
    int answer = 1;
    for (int i = 1; i <= x; i++)
    {
        answer *= i;
    }
    return answer;
}