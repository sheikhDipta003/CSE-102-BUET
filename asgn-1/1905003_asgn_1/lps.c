#include <stdio.h>

int main()
{
    int num,i,pos,pos1,pos2,pos3,sum,sum1,sum2,sum3,length,length1,length2,length3;

    sum1=0;
    sum2=0;
    sum3=0;
    length1=0;
    length2=0;
    length3=0;
    i = 0;



    while(num !='q')
    {
        scanf("%d ",&num);

        while(num<0)
        {
            scanf("%d ",&num);
            i++;
        }

        if (num>0)
        {
            pos1 = i;
        }

        while(num>0)
        {
            sum1 = sum1 + num ;
            length1 = length1 + 1 ;
            scanf("%d ",&num);
            i++;
        }


        while(num<0)
        {
            scanf("%d ",&num);
            i++;
        }

        if (num>0)
        {
            pos2 = i;
        }

        while (num>0)
        {
            sum2 = sum2 + num ;
            length2 = length2 + 1 ;
            scanf("%d ",&num);
            i++;
        }

        if (length1>length2)
        {
            sum = sum1;
            length = length1;
            pos = pos1;
        }
        else
        {
            sum = sum2;
            length = length2;
            pos = pos2;
        }

        if (num!='q')
        {

            while(num<0)
            {
                scanf("%d ",&num);
                i++;
            }

            if (num>0)
            {
                pos3 = i;
            }

            while(num>0)
            {
                sum3 = sum3 + num ;
                length3 = length3 + 1 ;
                scanf("%d ",&num);
                i++;
            }

            if (length3>length)
            {
                sum = sum3;
                length = length3;
                pos = pos3;
            }

         }


    }

    printf("Length of LPS:%d\nSum of LPS:%d\nStarting position of LPS:%d",length,sum,pos);

    return 0;
}
