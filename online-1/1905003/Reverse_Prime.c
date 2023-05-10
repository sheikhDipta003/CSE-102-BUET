#include <stdio.h>

int main()
{
    int n, rem, num = 0, i, c;

    scanf("%d", &n);

    do{
        rem = n % 10;
        n = n / 10;

        num = num * 10 + rem;
    }while(n != 0);

    //printf("%d", num);

    c = 0;
    for(i = 1 ; i <= num ; i++)
        if(num % i == 0)
            c++;

    if(c == 2)
        printf("Yes");
    else
        printf("No");

    return 0;
}
