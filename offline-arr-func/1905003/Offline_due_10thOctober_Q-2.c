#include <stdio.h>

int isPerfectOrNot(int num)  //returns 1 if perfect; 0 if not
{
    if(num == 1)
        return 0;   //1 is not a perfect number
    else
    {
        int i, sum = 0;
        for(i = 1 ; i * i <= num ; i++)   //sum all of the factors of that number 'num' [except 'num' itself] by going upto
        {                              //its sqrt; because factors greater than sqrt can be
            if(num % i == 0)            //found by (num / i)
                sum += i + (num / i);
        }

        sum = sum - num;     //discard from 'sum' the number itself

        if(sum == num)
            return 1;      //if sum of all the factors == the number, it is a perfect number
        else
            return 0;      //otherwise not
    }
}

int main()
{
    int n, i, sum = 0;

    scanf("%d", &n);

    for(i = 1 ; i <= n ; i++)     //check which number(s) are perfect from 1 to n(user input);
        if(isPerfectOrNot(i) == 1)   //add that number(s) if perfect, otherwise don't
            sum += i;

    printf("%d", sum);

    return 0;
}
