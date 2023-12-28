#include <stdio.h>

int isPrime(int num)
{
    int i;

    for(i = 2 ; i * i <= num ;i++)
        if(num % i == 0)
            return 0;
    return 1;
}

int ithPrime(int i)
{
    int count, c = 1;
    for(count = 2 ;; count++)
    {
        if(isPrime(count) == 1)
        {
            if(c == i)
                return count;
            c++;
        }

    }
}

int returnNcR(int n, int r)
{
    int numerator, denominator, i;

    if(r == 0  || r == n)
        return 1;
    else
    {
        numerator = 1;
        for(i = n ; i <= n - r + 1; i--)
            numerator *= i;

        denominator = 1;
        for(i = 1 ; i <= r ;i++)
            denominator *= i;

        printf("%d %d %d\n", numerator, denominator, numerator/denominator);
        return (numerator / denominator);
    }
}

int main()
{
    int num, sum = 0, i;
    scanf("%d", &num);

    //printf("%d %d %d", ithPrime(3), ithPrime(2), returnNcR(ithPrime(3), ithPrime(2)));

    for(i = 1 ; i <= num ;i++)
    {
        sum += returnNcR(ithPrime(i+1), ithPrime(i));
    }

    printf("%d", sum);
}
