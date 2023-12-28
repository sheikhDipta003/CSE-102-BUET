#include <stdio.h>

int main()
{
    float income,tax;
    scanf("%f",&income);

    switch((income>=0) && (income<10000))
    {
    case 1:
        tax = 0.1*income;
        break;
    case 0:
        break;
    }
    switch((income>=10000) && (income<30000))
    {
    case 1:
        tax = 0.1*10000+0.15*(income-10000);
        break;
    case 0:
        break;
    }
    switch((income>=30000) && (income<50000))
    {
    case 1:
        tax = 0.15*30000+0.20*(income-30000);
        break;
    case 0:
        break;
    }
    switch(income>=50000)
    {
    case 1:
        tax = 0.20*50000+0.25*(income-50000);
        break;
    case 0:
        break;
    }

    printf("%f",tax);




    return 0;
}
