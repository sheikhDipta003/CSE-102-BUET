#include <stdio.h>

int main()
{
    int n, i, j, N[100], count[100] = {0}, num, count_max, F[100] = {0}, c;  //N[] stores the
                                            //numbers input by user; count[] stores the frequency
    scanf("%d", &n);                        //of each distinct number; F[] stores distinct
                                            //numbers with the same maximum frequency
    for(i = 0 ; i < n ; i++)
        scanf("%d", &N[i]);    //store the input numbers

    for(i = 0 ; i < n ; i++)
    {
        num = N[i];            //read a number from the input array

        for(j = 0 ; j <= i ; j++)
            if(N[j] == num)
                count[i]++;      //find the frequency of that number in the portion of input
                                                //array currently under consideration
        count_max = count[0];
        for(j = 1 ; j <= i ; j++)
            if(count[j] > count_max)
                count_max = count[j];    //find maximum frequency

        printf("Most frequent number = ");

        c = 0;
        for(j = 0 ; j <= i ; j++)
            if(count[j] == count_max)
            {
                F[c] = N[j];
                c++;            //store distinct numbers with this maximum frequency
            }


        for(j = 0 ; j < c ; j++)   //print the number(s)
            if(j == c - 1)
                printf("%d", F[j]);
            else
                printf("%d, ", F[j]);

        printf("\n");
    }

    return 0;
}
