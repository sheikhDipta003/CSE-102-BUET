#include <stdio.h>

int main()
{
    int n, i, H[100], j, max;

    scanf("%d", &n);     //H[] stores the input numbers

    for(i = 0 ; i < n ; i++)
    {
        scanf("%d", &H[i]);
    }

    max = H[0];             //find the maximum of the input numbers
    for(i = 1; i < n ; i++)
        if(H[i] > max)
            max = H[i];

    for(i = 1 ; i <= max ; i++)   //outputs vertically; highest length of the bar-chart is max
    {
        for(j = 0 ; j < n ; j++)   //outputs horizontally
        {
            if(i <= (max - H[j]))   //for every input, if it's <= max, print double space
                printf("  ");     //in its place
            else
                printf("**");     //if not, print double stars

            printf(" ");      //print a space after each output for an input
        }
        printf("\n");     //newline after each output for the whole input array
    }


    return 0;
}
