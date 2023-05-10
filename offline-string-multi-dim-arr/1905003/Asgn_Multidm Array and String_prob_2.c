#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char C[100] = "Hello world";
char builtInCmd[][20] = {"InA", "InB",
                         "OutA", "OutB",
                         "A+B", "B+A",
                         "A-B", "B-A",
                         "A*B", "B*A",
                         "DetA", "DetB",
                         "TransA", "TransB",
                         "exit"};
int sum[5][5];
int diff[5][5];
int M[5][5];
int T[5][5];

/*void removeSpace(char S[], int Len)
{
    // remove leading and trailing white-spaces
    int i, leadSpace, trailSpace, j;

    for (i = 0; i < Len; i++) { // find total number of leading spaces
        if (S[i] != ' ') {
            leadSpace = i;
            // printf("%d\n", leadSpace);
            break;
        }
    }

    for (i = Len - 1; i >= 0; i--) { // find total number of trailing spaces
        if (S[i] != ' ') {
            trailSpace = Len - i - 1;
            // printf("%d\n", trailSpace);
            break;
        }
    }

    for (i = leadSpace; i < Len; i++) {
        S[i - leadSpace] = S[i];
    }

    S[Len - trailSpace - leadSpace + 1] = '\0';
    Len = Len - (leadSpace + trailSpace);
    // return Len;

    // remove duplicate spaces between adjacent two characters
    j = 0;
    for (i = 0; i < Len; i++)
    {
        if (S[i] == ' ')
        {
            if (S[i - 1] != ' ')
            {
                C[j] = S[i];
                j++;
            }
        }
        else
        {
            C[j] = S[i];
            j++;
        }
    }
    C[j] = '\0';
}*/
void removeSpace(char str[], int Len)
{
    int i, j;

    j = 0;
    for(i = 0 ; i < Len ; i++)
    {
        if(str[i] != ' ')
        {
            C[j] = str[i];
            j++;
        }
    }
    C[j] = '\0';
}

void addMatrix(int row_A, int col_A, int row_B, int col_B, int A[5][5], int B[5][5])
{
    int i, j;

    if (row_A == row_B && col_A == col_B)
    {
        for (i = 0; i < row_A ; i++)
        {
            for (j = 0; j < col_A; j++)
                printf("%d ", A[i][j] + B[i][j]);

            printf("\n");
        }
    }
    else
        printf("\nAddition not possible\n");
}

void diffMatrix(int row_A, int col_A, int row_B, int col_B, int A[5][5], int B[5][5])
{
    int i, j;

    if (row_A == row_B && col_A == col_B)
    {
        for (i = 0; i < row_A; i++)
        {
            for (j = 0; j < col_A; j++)
                printf("%d ", A[i][j] - B[i][j]);

            printf("\n");
        }
    }
    else
        printf("\nSubtraction not possible\n");
}

void multMatrix(int row_A, int col_A, int row_B, int col_B, int A[5][5], int B[5][5])
{
    int i, j, k;

    if (col_A != row_B)
        printf("\nMultiplication not possible\n");
    else
    {
        for (i = 0; i < row_A; i++)
            for (j = 0; j < col_B; j++)
            {
                M[i][j] = 0;
                for (k = 0; k < col_A; k++)
                    M[i][j] += A[i][k] * B[k][j];
            }

        printf("\n");
        for (i = 0; i < row_A; i++)
        {
            for (j = 0; j < col_B; j++)
                printf("%d ", M[i][j]);
            printf("\n");
        }
    }
}

//finding determinant
void getCofactor(int A[5][5], int temp[5][5], int p, int q, int n)
{
	int i = 0, j = 0, row, col;

	for (row = 0; row < n; row++)
	{
		for (col = 0; col < n; col++)
		{
			if (row != p && col != q)
			{
				temp[i][j] = A[row][col];
				j++;

				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

int detMatrix(int A[5][5], int n)
{
	int det = 0, temp[5][5], sign = 1, col;

	if (n == 1)
		return A[0][0];


	for(col = 0; col < n; col++)
	{
		getCofactor(A, temp, 0, col, n);
		det += sign * A[0][col] * detMatrix(temp, n - 1);

		sign = -sign;
	}

	return det;
}

//find transpose
void transMatrix(int row, int col, int A[5][5])
{
    int i, j;

    for(i = 0 ; i < row ; i++)
    {
        for(j = 0 ; j < col ; j++)
            T[j][i] = A[i][j];
    }

    printf("\n");
    for(i = 0 ; i < col ; i++)
    {
        for(j = 0 ; j < row; j++)
            printf("%d ", T[i][j]);

        printf("\n");
    }
}

//division
void divideMatrix(int divisor, int row, int col, int A[5][5])
{
    int i, j;

    printf("\n");
    for(i = 0 ; i < row ; i++)
    {
        for(j = 0 ; j < col ; j++)
            printf("%.3f ", (float)A[i][j] / (float)divisor);
        printf("\n");
    }
}

int main()
{
    /*char str[100];
    int len;
    gets(str);
    printf("\n%s", str);
    removeSpace(str, strlen(str));
    printf("\n%s", C);*/
    char command[100];
    int  i, j, A[5][5], B[5][5], row_A, col_A, row_B, col_B, declare_A = 0, declare_B = 0, divisor, x, y;
    char ch;
    char div_form_A[6] = "A/", div_form_B[6] = "B/";

    while (1) {
        // input string
        // printf("\n%s\n", C);
        //gets(command);
        /*i = 0;
        do{
            ch = getchar();
            if(ch != '\n' && ch != EOF)
            {
                command[i] = ch;
                i++;
            }
            else
                break;
        }while(1);
        command[i] = '\0';*/
        scanf("%[^\n]s", command);
        ch = getchar();
        removeSpace(command, strlen(command));

        if (strcmpi(C, builtInCmd[14]) == 0)
            exit(0);
        else if (strcmpi(C, builtInCmd[0]) == 0)
        {
            // input array A
            scanf("%d%d", &row_A, &col_A);

            for (i = 0; i < row_A; i++) {
                for (j = 0; j < col_A; j++)
                    scanf("%d", &A[i][j]);
            }

            declare_A = 1;
        }
        else if (strcmpi(C, builtInCmd[1]) == 0)
        {
            // input array B
            scanf("%d%d", &row_B, &col_B);

            for (i = 0; i < row_B; i++) {
                for (j = 0; j < col_B; j++)
                    scanf("%d", &B[i][j]);
            }

            declare_B = 1;
        }
        else if (strcmpi(C, builtInCmd[2]) == 0)
        {
            if(declare_A == 1)
            {
                printf("\n");
                for (i = 0; i < row_A; i++) {
                    for (j = 0; j < col_A; j++)
                        printf("%d ", A[i][j]);
                    printf("\n");
                }
            }
            else
                printf("\nNo A matrix found\n");
            //break;
        }
        else if (strcmpi(C, builtInCmd[3]) == 0)
        {
            if(declare_B == 1)
            {
                printf("\n");
                for (i = 0; i < row_B; i++) {
                    for (j = 0; j < col_B; j++)
                        printf("%d ", B[i][j]);
                    printf("\n");
                }
            }
            else
                printf("\nNo B matrix found\n");
            // break;
        }
        else if (strcmpi(C, builtInCmd[4]) == 0 || strcmpi(C, builtInCmd[5]) == 0)
        {
            if(declare_A == 0 && declare_B == 0)
                printf("\nNo A or B matrix found\n");
            else if(declare_A == 0 && declare_B == 1)
                printf("\nNo A matrix found\n");
            else if(declare_A == 1 && declare_B == 0)
                printf("\nNo B matrix found\n");
            else
                addMatrix(row_A, col_A, row_B, col_B, A, B);
        }
        else if (strcmpi(C, builtInCmd[6]) == 0)
        {
            if(declare_A == 0 && declare_B == 0)
                printf("\nNo A or B matrix found\n");
            else if(declare_A == 0 && declare_B == 1)
                printf("\nNo A matrix found\n");
            else if(declare_A == 1 && declare_B == 0)
                printf("\nNo B matrix found\n");
            else
                diffMatrix(row_A, col_A, row_B, col_B, A, B);
        }
        else if (strcmpi(C, builtInCmd[7]) == 0)
        {
            if(declare_A == 0 && declare_B == 0)
                printf("\nNo A or B matrix found\n");
            else if(declare_A == 0 && declare_B == 1)
                printf("\nNo A matrix found\n");
            else if(declare_A == 1 && declare_B == 0)
                printf("\nNo B matrix found\n");
            else
                diffMatrix(row_B, col_B, row_A, col_A, B, A);
        }
        else if (strcmpi(C, builtInCmd[8]) == 0)
        {
            if(declare_A == 0 && declare_B == 0)
                printf("\nNo A or B matrix found\n");
            else if(declare_A == 0 && declare_B == 1)
                printf("\nNo A matrix found\n");
            else if(declare_A == 1 && declare_B == 0)
                printf("\nNo B matrix found\n");
            else
                multMatrix(row_A, col_A, row_B, col_B, A, B);
        }
        else if (strcmpi(C, builtInCmd[9]) == 0)
        {
            if(declare_A == 0 && declare_B == 0)
                printf("\nNo A or B matrix found\n");
            else if(declare_A == 0 && declare_B == 1)
                printf("\nNo A matrix found\n");
            else if(declare_A == 1 && declare_B == 0)
                printf("\nNo B matrix found\n");
            else
                multMatrix(row_B, col_B, row_A, col_A, B, A);
        }
        else if (strcmpi(C, builtInCmd[10]) == 0)
        {
            if(declare_A == 0)
                printf("\nNo A matrix found\n");
            else
            {
                if(row_A == col_A)
                    printf("\n%d\n", detMatrix(A, row_A));
                else
                    printf("\nDeterminant not possible\n");
            }
        }
        else if(strcmpi(C, builtInCmd[11]) == 0)
        {
            if(declare_B == 0)
                printf("\nNo B matrix found\n");
            else
            {
                if(row_B == col_B)
                    printf("\n%d\n", detMatrix(B, row_B));
                else
                    printf("\nDeterminant not possible\n");
            }
        }
        else if(strcmpi(C, builtInCmd[12]) == 0)
        {
            if(declare_A == 0)
                printf("\nNo A matrix found\n");
            else
                transMatrix(row_A, col_A, A);
        }
        else if(strcmpi(C, builtInCmd[13]) == 0)
        {
            if(declare_B == 0)
                printf("\nNo B matrix found\n");
            else
                transMatrix(row_B, col_B, B);
        }
        else
        {
            if(C[0] == 'A')
            {
                x = 0;
                for(i = 0; i < 2 ; i++)
                {
                    x += C[i] - div_form_A[i];
                }
                for(i = 2 ; C[i] != '\0' ; i++)
                {
                    if(isdigit(C[i]))
                        y = 1;
                    else
                    {
                        y = 0;
                        break;
                    }
                }

                if(x == 0  && y == 1)
                {
                    if(declare_A == 0)
                        printf("\nNo A matrix found\n");
                    else
                    {
                        divisor = 0;
                        for(i = 2 ; C[i] != '\0' ; i++)
                            divisor = divisor * 10 + (C[i] - 48);

                        divideMatrix(divisor, row_A, col_A, A);
                    }
                }
            }
            else if(C[0] == 'B')
            {
                x = 0;
                for(i = 0; i < 2 ; i++)
                {
                    x += C[i] - div_form_B[i];
                }
                for(i = 2 ; C[i] != '\0' ; i++)
                {
                    if(isdigit(C[i]))
                        y = 1;
                    else
                    {
                        y = 0;
                        break;
                    }
                }

                if(x == 0  && y == 1)
                {
                    if(declare_B == 0)
                        printf("\nNo B matrix found\n");
                    else
                    {
                        divisor = 0;
                        for(i = 2 ; C[i] != '\0' ; i++)
                            divisor = divisor * 10 + (C[i] - 48);

                        divideMatrix(divisor, row_B, col_B, B);
                    }
                }
            }
            else
                continue;
        }
    }

    return 0;
}
