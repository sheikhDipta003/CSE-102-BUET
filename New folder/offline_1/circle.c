# include <stdio.h>
# include <math.h>

int main()
{
    int x1,y1,x2,y2,r1,r2,R,r;
    float C1C2;

    scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);

    C1C2 = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

    R = (r1>r2)?r1:r2;
    r = (r1<r2)?r1:r2;

    if (C1C2>(R+r))
        printf("Do not intersect");
    else if ((C1C2<=r+R) && (C1C2>=R-r))
        printf("Intersect");
    else if (C1C2<(R-r))
        printf("One inside the other");

    return 0;
}
