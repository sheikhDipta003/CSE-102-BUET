#include <stdio.h>

int curr_pos = 0;

int findThePath(int curr_pos, int A[], int n)
{
    int final_pos, temp;

    if(curr_pos == n - 1)
        return 1;

    if(curr_pos + A[curr_pos] > n - 1)
    {
        final_pos = curr_pos - A[curr_pos] ;
        if(A[final_pos] == 0)
            return 0;
        curr_pos = final_pos;
    }
    else if(curr_pos + A[curr_pos] <= n - 1 && curr_pos + A[curr_pos] >= 0)
    {
        temp = curr_pos + A[curr_pos] ;
        if(A[temp] != 0)
        {
            final_pos = temp;
            curr_pos = final_pos;
        }
        else
        {
            if(curr_pos - A[curr_pos] < 0)
            {
                final_pos = curr_pos + A[curr_pos] ;
                if(A[final_pos] == 0)
                    return 0;
                curr_pos = final_pos;
            }
            else
            {
                final_pos = curr_pos - A[curr_pos] ;
                if(A[final_pos] == 0)
                    return 0;
                curr_pos = final_pos;
            }
        }
    }
    else
    {
        final_pos = curr_pos + A[curr_pos] ;
        if(A[final_pos] == 0)
            return 0;
        curr_pos = final_pos;
    }

    findThePath(curr_pos, A, n);
}

int main()
{
    int n, i, A[30], x;
    scanf("%d", &n);

    for(i = 0 ; i < n ; i++)
        scanf("%d", &A[i]);

    x = findThePath(0, A, n);

    printf("%d", x);

    return 0;
}
