#ifndef BGCOORDINATES_H_INCLUDED
#define BGCOORDINATES_H_INCLUDED

#define NumOfLines 21
#define NumOfRect 33
#define NumOfDots 247

typedef struct {
    double line_x1;
    double line_y1;
    double line_x2;
    double line_y2;
} Line;

typedef struct {
    double bottom_left_x;
    double bottom_left_y;
    double base;
    double height;
} Rect;

Line L_arr[NumOfLines] = {{300, 900, 725, 900},  //0
                {300, 900, 300, 700},   //1
                {300, 700, 450, 700},   //2
                {450, 700, 450, 550},   //3
                {450, 550, 300, 550},   //4
                {300, 500, 450, 500},   //5
                {450, 500, 450, 440},   //6
                {450, 440, 300, 440},   //7
                {300, 440, 300, 325},   //8
                {300, 275, 300, 150},   //9
                {300, 150, 1200, 150},   //10
                {1200, 150, 1200, 275},   //11
                {1200, 325, 1200, 440},     //12
                {1200, 440, 1050, 440},     //13
                {1050, 440, 1050, 500},     //14
                {1050, 500, 1200, 500},     //15
                {1200, 550, 1050, 550},     //16
                {1050, 550, 1050, 700},     //17
                {1050, 700, 1200, 700},     //18
                {1200, 700, 1200, 900},     //19
                {1200, 900, 775, 900}      //20
};

Rect R_arr[NumOfRect] = {{350, 815, 100, 35},   //0
                        {350, 750, 100, 15},    //1
                        {500, 815, 175, 35},    //2
                        {825, 815, 175, 35},    //3
                        {1050, 750, 100, 15},   //4
                        {1050, 815, 100, 35},   //5
                        {500, 440, 15, 60},    //6
                        {985, 440, 15, 60},    //7
                        {500, 325, 150, 65},    //8
                        {850, 325, 150, 65},     //9
                        {725, 815, 50, 85},       //10
                        {300, 275, 75, 50},      //11
                        {1125, 275, 75, 50},     //12
                        {725, 690, 50, 60},      //13
                        {565, 750, 370, 15},     //14
                        {500, 550, 15, 215},     //15
                        {515, 690, 160, 15},     //16
                        {985, 550, 15, 215},     //17
                        {825, 690, 160, 15},     //18
                        {565, 440, 370, 15},     //19
                        {725, 325, 50, 115},    //20
                        {375, 200, 275, 15},     //21
                        {500, 215, 15, 60},     //22
                        {850, 200, 275, 15},        //23
                        {985, 215, 15, 60},      //24
                        {725, 200, 50, 60},      //25
                        {565, 260, 370, 15},         //26
                        {350, 375, 100, 15},       //27
                        {435, 275, 15, 100},       //28
                        {1050, 275, 15, 100},        //29
                        {1050, 375, 100, 15},        //30
                        {565, 520, 370, 100},       //31
                        {700, 615, 100, 10}     //32
};


int i, p[NumOfDots] = {0};
double x[NumOfDots + 1],y[NumOfDots + 1];

void drawbackground()
{
    iSetColor(0, 255, 255);

    for(int i = 0 ; i < NumOfLines ; i++)
        iLine(L_arr[i].line_x1, L_arr[i].line_y1, L_arr[i].line_x2, L_arr[i].line_y2);

    for(int i = 0 ; i < NumOfRect ; i++)
    {
        if(i == NumOfRect - 1)
            iSetColor(255, 255, 255);
        else
            iSetColor(255, 0, 150);
        iFilledRectangle(R_arr[i].bottom_left_x, R_arr[i].bottom_left_y, R_arr[i].base, R_arr[i].height);
    }

    //draw the dots

    x[0] = 330;
    y[0] = 875;
    for(i = 0 ; i < 15 ; i++)       //line 1-29
    {
        if(p[i] == 0)
        {
            iSetColor(0, 255, 0);
            iFilledCircle(x[i], y[i], 5);
        }
        //x += 25;
        x[i + 1] = x[i] + 25;
        y[i + 1] = y[i];
    }

    x[15] = 330;
    y[15] = 790;
    for(i = 15; i < 49 ; i++)          //line 1-25
    {
        if(p[i] == 0)
        {
            iSetColor(0, 255, 0);
            iFilledCircle(x[i], y[i], 5);
        }
        x[i + 1] = x[i] + 25;
        y[i + 1] = y[i];
    }

    x[49] = 330;
    y[49] = 850;
    for(i = 49 ; i < 54 ; i++)        //line 0-2
    {
        if(i != 51 && p[i] == 0)
        {
            iSetColor(0, 255, 0);
            iFilledCircle(x[i], y[i], 5);
        }
        x[i + 1] = x[i];
        y[i + 1] = y[i] - 30;
    }

    x[54] = 480;
    y[54] = 850;
    for(i = 54 ; i < 75 ; i++)        //line 0 - T 0
    {
        if(i != 56 && p[i] == 0)
        {
            iSetColor(0, 255, 0);
            iFilledCircle(x[i], y[i], 5);
        }
        x[i + 1] = x[i];
        y[i + 1] = y[i] - 30;
    }

    x[75] = 330;
    y[75] = 175;
    for(i = 75 ; i < 108 ; i++)          //line 12-14
    {
        if(p[i] == 0)
        {
            iSetColor(0, 255, 0);
            iFilledCircle(x[i], y[i], 5);
        }
        x[i + 1] = x[i] + 25;
        y[i + 1] = y[i];
    }

    x[108] = 1030;
    y[108] = 850;
    for(i = 108 ; i < 129 ; i++)        //line 26 - T1
    {
        if(i != 110 && p[i] == 0)
        {
            iSetColor(0, 255, 0);
            iFilledCircle(x[i], y[i], 5);
        }
        x[i + 1] = x[i];
        y[i + 1] = y[i] - 30;
    }

    x[129] = 805;
    y[129] = 875;
    for(i = 129 ; i < 144 ; i++)
    {
        if(p[i] == 0)                                   //line 25-27
        {
            iSetColor(0, 255, 0);
            iFilledCircle(x[i], y[i], 5);
        }
        x[i + 1] = x[i] + 25;
        y[i + 1] = y[i];
    }

    x[144] = 500;
    y[144] = 300;
    for(i = 144 ; i < 165 ; i++)
    {
        if(i != 153 && i != 154 && p[i] == 0)                                   //line 28-29
        {
            iSetColor(0, 255, 0);
            iFilledCircle(x[i], y[i], 5);
        }
        x[i + 1] = x[i] + 25;
        y[i + 1] = y[i];
    }

    x[165] = 540;
    y[165] = 480;
    for(i = 165 ; i < 183 ; i++)
    {
        if(p[i] == 0)                                   //Rectangle 6-7
        {
            iSetColor(0, 255, 0);
            iFilledCircle(x[i], y[i], 5);
        }
        x[i + 1] = x[i] + 25;
        y[i + 1] = y[i];
    }

    x[183] = 540;
    y[183] = 655;
    for(i = 183 ; i < 201 ; i++)
    {
        if(p[i] == 0)                                   //Rectangle 15-17
        {
            iSetColor(0, 255, 0);
            iFilledCircle(x[i], y[i], 5);
        }
        x[i + 1] = x[i] + 25;
        y[i + 1] = y[i];
    }

    x[201] = 540;
    y[201] = 730;
    for(i = 201 ; i < 209 ; i++)
    {
        if(i != 208 && p[i] == 0)                                   //Rectangle 13-15
        {
            iSetColor(0, 255, 0);
            iFilledCircle(x[i], y[i], 5);
        }
        x[i + 1] = x[i] + 25;
        y[i + 1] = y[i];
    }

    x[209] = 790;
    y[209] = 730;
    for(i = 209 ; i < 217 ; i++)
    {
        if(p[i] == 0)                                   //Rectangle 13-17
        {
            iSetColor(0, 255, 0);
            iFilledCircle(x[i], y[i], 5);
        }
        x[i + 1] = x[i] + 25;
        y[i + 1] = y[i];
    }

    x[217] = 325;
    y[217] = 415;
    for(i = 217 ; i < 232 ; i++)
    {
        if(i != 223 && p[i] == 0)                                   //Rectangle 20 - left border
        {
            iSetColor(0, 255, 0);
            iFilledCircle(x[i], y[i], 5);
        }
        x[i + 1] = x[i] + 25;
        y[i + 1] = y[i];
    }

    x[232] = 825;
    y[232] = 415;
    for(i = 232 ; i < NumOfDots ; i++)
    {
        if(i != 240 && p[i] == 0)                                   //Rectangle 20 - right border
        {
            iSetColor(0, 255, 0);
            iFilledCircle(x[i], y[i], 5);
        }
        x[i + 1] = x[i] + 25;
        y[i + 1] = y[i];
    }
}

#endif // BGCOORDINATES_H_INCLUDED
