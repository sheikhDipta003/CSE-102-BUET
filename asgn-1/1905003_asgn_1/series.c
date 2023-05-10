#include <stdio.h>

int main()
{
    int n;
    float x,y,sum=1,term=1;
    scanf("%f",&x);

    y = 3.1416*x/180.00;


    for (n=1;n<=100;n++)
    {
        term = term*(-y*y/((2*n-1)*(2*n)));
        sum = sum+term;
    }

    printf("%.6f",sum);



    return 0;

}
