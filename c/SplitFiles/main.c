#include "calc.h"
#include "print.h"

int main()
{
    CALC_DATA data1;
    data1.op1 = 10;
    data1.op2 = 20;

    add(&data1);
    print(&data1);

    CALC_DATA data2;
    data2.op1 = 40;
    data2.op2 = 15;

    sub(&data2);
    print(&data2);

    return 0;
}