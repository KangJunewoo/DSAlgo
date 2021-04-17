#include <stdio.h>
#include <stdlib.h>

int *Setn; //순열과 조합을 생성할 집합을 만들 int 포인터형 전역 변수 Setn 선언
int *Copy; //Setn 변수를 복사(저장)할 int 포인터형 전역 변수 Copy 선언

int Fact(int x);                                                       //x팩토리얼 개수를 출력하는 함수 Fact
void Swap(int *a, int *b);                                             //순열과 조합을 구할떄 원소 위치를 바꿔줄 함수 Swap
void Permutation(int *Setn, int *Copy, int n, int r, int term, int i); //nPr 순열을 만드는 함수 Permutation
void Print_Permutation(int *Setn, int n);                              //순열 출력을 위한 함수 Print_Permutation
void Combination(int *Setn, int *Copy, int n, int r, int term);        //nCr 조합을 만드는 함수 Combination
void Print_Combination(int *Copy, int n);                              //조합 출력을 위한 함수 Print_Combination

void main()
{
    int n, r, i;

    printf("@ n의 값을 입력 하세요 : "); //사용자로부터 총 원소의 개수 n을 입력받는다.
    scanf("%d", &n);

    while (1)
    {               //예외처리를 위한 무한루프문
        if (n > 10) //n이 10보다 큰 경우 재입력 유도
        {
            printf("@ n의 값을 입력 하세요 : ");
            scanf("%d", &n);
        }
        else if (n < 1) //n이 1보다 작은 경우 재입력 유도
        {
            printf("@ n의 값을 입력 하세요 : ");
            scanf("%d", &n);
        }
        else if (1 <= n <= 10) //과제에서 주어진 범위인 1<= n <= 10 일떄 무한루프 탈출
        {
            break;
        }
    }
    printf("@ r의 값을 입력 하세요 : "); //순열을 나열할 개수 or 조합을 뽑을 개수인 r 을 사용자로부터 입력받음
    scanf("%d", &r);

    while (1)
    {              //예외처리를 위한 무한루프문
        if (r > n) //r 이 n 보다 클 경우 재입력 유도
        {
            printf("@ r의 값을 입력 하세요 : ");
            scanf("%d", &r);
        }
        else if (r <= n) //과제에서 주어진 범위인 r <= n 일때 무한루프 탈출
        {
            break;
        }
    }

    Setn = (int *)malloc(n * sizeof(int)); // 배열 Setn 을 사용자로부터 입력받은 n 크기 만큼 동적할당 받는다
    Copy = (int *)malloc(r * sizeof(int)); // 배열 Copy 을 사용자로부터 입력받은 r 크기 만큼 동적할당 받는다

    for (i = 0; i < n; i++) //for문을 사용하여 Setn 배열에 1부터 n 까지의 수 입력
    {
        Setn[i] = i + 1;
    }

    printf("원소의 %d-순열 (총 %d개) : ", r, Fact(n) / Fact(n - r)); // 순열의 개수를 x 팩토리얼을 계산하는 함수 Fact 를 >사용하여 구한다
    Permutation(Setn, Copy, n, r, r, i);
    printf("\n");
    printf("원소의 %d-조합 (총 %d개) : ", r, Fact(n) / (Fact(r) * Fact(n - r))); //조합의 개수를 x 팩토리얼을 계산하는 함수 Fact 를 사용하여 구한다.
    Combination(Setn, Copy, n, r, r);
    printf("\n");

    free(Setn); //동적할당 해제
    free(Copy); //동적할당 해제
}
int Fact(int x) // x! 을 계산하는 함수 Fact
{
    if (x == 0)
        return (1);
    else
        return (x * Fact(x - 1)); // x! = x * (x-1)! 을 이용한 재귀함수로 계산
}

void Swap(int *a, int *b) //순열을 생성하는데 사용할 Swap 함수
{
    int c = *a; //a 와 b 의 값 교환
    *a = *b;
    *b = c;
}

void Permutation(int *Setn, int *Copy, int n, int r, int term, int i) //순열을 생성하는 함수 Permutation
{

    if (r == 0) // r이 0이 될경우 Print_Permutation 함수 호출하여 순열 출력
    {
        Print_Permutation(Copy, term);
        return;
    }
    else
    {
        for (i = n - 1; i >= 0; i--)                        //Swap 함수로 Setn[i] 와  Setn[n-1] 의 위치를 바꾼후
        {                                                   //Setn[i] 값을 (Setn[n-1]로 바뀐) Copy[r-1] 에 저장해놓고
            Swap(&Setn[i], &Setn[n - 1]);                   //재귀함수 호출을 이용해서 과정을 반복한다.
            Copy[r - 1] = Setn[n - 1];                      //그 후 Swap  함수 재호출하여 Setn[i] 와 Setn[n-1]의 위치를 >바꾸어준다.
            Permutation(Setn, Copy, n - 1, r - 1, term, i); //이 과정으로 역순(큰 수부터 출력) 의 순열 생성
            Swap(&Setn[i], &Setn[n - 1]);
        }
    }
}
void Print_Permutation(int *Setn, int n) //순열 출력을 위해 사용하는 함수 Print_Permutation
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d", Setn[i]);
    }
    printf(", ");
}

void Combination(int *Setn, int *Copy, int n, int r, int term) //조합을 생성하는 함수 Combination
{
    if (r == 0) // r이 0이될 경우 Print_Combination 함수 호출하여 조합 출력
    {
        Print_Combination(Copy, term);
        return;
    }
    if (n < r) //r 이 n 보다 커질경우 탈출
    {
        return;
    }
    else                                             //그외의 경우 순열 생성과 비슷한 방법으로 조합을 생성한다.
    {                                                //순열과는 다르게, 순서에 상관없이 뽑기때문에 Swap 함수를 사용하지 않는다.
        Copy[r - 1] = Setn[n - 1];                   //Setn[n-1] 값을 Copy[r-1] 에 복사
        Combination(Setn, Copy, n - 1, r - 1, term); //재귀함수 호출을 이용해서 과정을 반복한다.
        Combination(Setn, Copy, n - 1, r, term);
    }
}

void Print_Combination(int *Copy, int n) //조합 출력을 위해 사용하는 함수 Print_Combination
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d", Copy[i]);
    }
    printf(", ");
}