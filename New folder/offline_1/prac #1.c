#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int n;
    long int pos_pow;
    double neg_pow;

    printf("\t\t\t-----------------------------------------------------------------\n\n");
    printf("\t\t\t2 to the power n\t\tn\t\t2 to the power -n\n\n");
    printf("\t\t\t-----------------------------------------------------------------\n\n");
    for(n=0;n<=20;n++)
    {
        pos_pow= pow(2,n);
        neg_pow= 1.0/pow(2,n);

        printf("\t\t\t%d\t\t\t\t%ld\t\t    %lf", pos_pow, n, neg_pow);

        printf("\n");
    }

    return 0;
}
