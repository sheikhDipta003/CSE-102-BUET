#include <stdio.h>

int start[30], c = 0;

void replace(char original[], int Len_1, char find[], int Len_2, char replace[], int Len_3)
{
    int i, j, k, x, pos, p;

    //find the starting position of the find[] string!!
    for(i = 0 ; i <= (Len_1 - Len_2) ; i++)
    {
        j = 0;
        if(original[i] == find[j])
        {
            j++;
            for(k = i + 1 ; find[j] ; k++)
            {
                if(original[k] == find[j])
                {
                    x = 1;
                    j++;
                }
                else
                {
                    x = 0;
                    break;
                }
            }

            if(x == 1)
            {
                start[c] = i;
                c++;
            }
            else
                continue;
        }
    }

    printf("\n");
    for(i = 0 ; i < c ; i++)
        printf("%d ", start[i]);
    printf("\n\n");

    //replace the find[] string with replace[] string!

    if(Len_2 < Len_3)
    {
        for(i = c - 1 ; i >= 0 ; i--)
        {
            pos = start[i];
            k = 0;
            for(j = pos ; k < Len_2 ; j++)
            {
                original[j] = replace[k];
                k++;
            }

            for(j = Len_1 - 1; j >= pos + Len_2 ; j--)
                original[j + Len_3 - Len_2] = original[j];

            original[Len_1 + Len_3 - Len_2] = '\0';

            for(j = pos + Len_2 ; k < Len_3 ; j++)
            {
                original[j] = replace[k];
                k++;
            }

            Len_1 += (Len_3 - Len_2);
        }
    }
    else if(Len_2 > Len_3)
    {
       for(i = 0 ; i < c ; i++)
       {
           pos = start[i];

           for(j = pos + Len_2 ; j <= Len_1 ; j++)
           {
               original[j - Len_2 + Len_3] = original[j];
           }

           Len_1 -= (Len_2 - Len_3);
           //original[Len_1] = '\0';

           if(i != c - 1  &&  start[i+1] == (start[i] + Len_2 - 1))   c--;

           for(p = i + 1 ; p < c ; p++)
                start[p] -= (Len_2 - Len_3);

           k = 0;
           for(j = pos ; k < Len_3 ; j++)
           {
               original[j] = replace[k];
               k++;
           }
       }
    }
    else
    {
        for(i = c - 1 ; i >= 0 ; i--)
        {
            pos = start[i];
            k = 0;
            for(j = pos ; k < Len_2 ; j++)
            {
                original[j] = replace[k];
                k++;
            }
        }
    }

}

int main()
{
    char s1[100], s2[100], s3[10], ch;
    int i, Len_1, Len_2, Len_3;

    //first string
    i = 0;
    do{
        scanf("%c", &ch);
        if(ch != '\n')
        {
            s1[i] = ch;
            i++;
        }
        else
            break;

    }while(i < 100);
    s1[i] = '\0';
    Len_1 = i;

    //second string
    i = 0;
    do{
        scanf("%c", &ch);
        if(ch != '\n')
        {
            s2[i] = ch;
            i++;
        }
        else
            break;

    }while(i < 100);
    s2[i] = '\0';
    Len_2 = i;

    //third string
    i = 0;
    do{
        scanf("%c", &ch);
        if(ch != '\n')
        {
            s3[i] = ch;
            i++;
        }
        else
            break;

    }while(i < 10);
    s3[i] = '\0';
    Len_3 = i;

    replace(s1, Len_1, s2, Len_2, s3, Len_3);
    printf("%s\n", s1);

    return 0;
}

