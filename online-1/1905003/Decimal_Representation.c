#include <stdio.h>

int P(int base, int exp)
{
    int r, i;

    if(exp == 0)
        return 1;
    else
    {
        r = 1;
        for(i = 1; i <= exp ; i++)
            r = r * base;
    }
    return r;
}

int main()
{
    int X, b, c, p, num, rem, i;
    scanf("%d%d", &X, &b);

    num = 0;
    c = 0;
    do
    {
        rem = X % 10;
        X = X / 10;

        num += rem * P(b, c);
        c++;
    }while(X != 0);

    printf("%d", num);

    return 0;
}
