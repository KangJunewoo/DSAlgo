#include <stdio.h>
#include "print.h"

void print(CALC_DATA *data)
{
    printf("%d %c %d = %d \n", data->op1, data->op, data->op2, data->result);
}