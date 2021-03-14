# C언어 재밌는 사실들
## 구조체 멤버 정렬
CPU가 메모리에 접근할 때,
32비트 머신이 있고 64비트 머신이 있지 않은가.
이는 각각 데이터를 접근할 때 4바이트 or 8바이트 단위로 접근함을 의미한다.
근데 char형만 보아도, 이것보다 작은 데이터들이 많다.
이 경우 시프트 연산이 발생한다.
이게 2로 딱 나눠 떨어지는 크기면 깔끔한데
또 그게 아닌 경우가 많다.
그래서 구조체는 2, 4, 8, 16 바이트 단위로 정렬을 한다.
즉 실제 구조체가 5바이트면, 8바이트로 올림해버림.

하지만 파일을 다룰 때나 네트워크로 전송할 때는 정렬을 하면 안되겠지!
그럴 때는 구조체를 1바이트 단위로 정렬해야 할것이고,
구조체 앞뒤로 다음을 붙여주면 된다.
```c
#pragma pack(push, 1)
struct Sample{
    char iHave1Byte;
    int iHave4Bytes;
};
#pragma pack(pop)
```
그렇게 해 sizeof 연산자로 크기를 확인한다면
안붙이면 8, 붙이면 5가 될 것이다.