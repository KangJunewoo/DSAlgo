#include "calc.h"

void add(CALC_DATA *data)
{
    data->op = '+';
    data->result = data->op1 + data->op2;
}

void sub(CALC_DATA *data)
{
    data->op = '-';
    data->result = data->op1 - data->op2;
}