#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
        int i,j,group1, group2, group3, group4, group5;

        scanf("%d %d %d %d %d",&group1, &group2, &group3, &group4, &group5);

        printf("\t\t\t|");
        printf("\nGroup-1");

        for(j=1;j<=3;j++)
        {
            printf("\t\t\t|");

            for(i=1;i<=group1;i++)
            {
                printf("*");
            }
            printf("\n");
        }


        printf("\t\t\t|");
        printf("\nGroup-2");

        for(j=1;j<=3;j++)
        {
            printf("\t\t\t|");

            for(i=1;i<=group2;i++)
            {
                printf("*");
            }
            printf("\n");
        }


        printf("\t\t\t|");
        printf("\nGroup-3");

        for(j=1;j<=3;j++)
        {
            printf("\t\t\t|");

            for(i=1;i<=group3;i++)
            {
                printf("*");
            }
            printf("\n");
        }


        printf("\t\t\t|");
        printf("\nGroup-4");

        for(j=1;j<=3;j++)
        {
            printf("\t\t\t|");

            for(i=1;i<=group4;i++)
            {
                printf("*");
            }
            printf("\n");
        }


        printf("\t\t\t|");
        printf("\nGroup-5");

        for(j=1;j<=3;j++)
        {
            printf("\t\t\t|");

            for(i=1;i<=group5;i++)
            {
                printf("*");
            }
            printf("\n");
        }




    return 0;
}

