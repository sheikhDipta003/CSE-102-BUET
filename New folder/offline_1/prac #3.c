#include <stdio.h>
//#include <conio.h>

int main()
{
    int i,arr[5];

    for(i=0;i<5;i++)
    {
        scanf("%d ",&arr[i]);
    }

    //getch();


    /*for(i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(arr[j]>arr[i])
            {
                temp= arr[j];
                arr[j]= arr[i];
                arr[i]= temp;
            }
        }
    }*/

    /*max= arr[0];

    for(i=0;i<5;i++)
    {
        if(arr[i+1]>arr[i])
        {
            max= arr[i+1];
        }
    }*/

    for (i=0;i<3;i++)
    {

        if(arr[i+2]==arr[i+1])
        {
           printf("%d",arr[i+1]);
        }
        else
        {
           if(arr[i+1]==arr[i])
           {
               printf("%d",arr[i+2]);
           }

           else
           {
               printf("%d",arr[i+1]);
               printf("%d",arr[i+2]);
           }
        }

    }

    return 0;
}
