#include <stdio.h>

int main()
{
    int num,sum=0,d,i,j,rem;

    scanf("%d",&num);

    for (i=1;num!=0;i++)
    {
        d = num%10;
        num=num/10;
        for(j=2;j<d;j++)
        {
            rem = d%j;
            if (rem==0)
                break;
        }
        if((rem!=0)&& (d!=1))
        {
            sum+=d;
        }
    }

    printf("%d",sum);


    return 0;
}
