# include "iGraphics.h"
# include "gl.h"

double offset = 500.0;
double dist[4] = {5.0, 5.0, 5.0, 5.0}, freq[3] = {0.03, 0.02, 0.01}, amp[3] = {100.0, 200.0, 250.0};
double pos_x[4], pos_y[4], ball_x[4] = {0.0}, ball_y[4] = {0.0}, wx[3], wx_1[3] = {0.0}, r[4] = {7.0, 7.0, 7.0, 7.0};
int d[4] = {1, 1, 1, 1}, c = 1, Tb[4] = {1, 1, 1, 1}, i, j;
double p[3] = {0.0}; //for phase change
double temp;

void iDraw()
{
    iClear();

    if(c == 1)
    {
        iSetColor(255, 255, 255);
        iLine(0.0, offset, 1500.0, offset);

        for(i = 0 ; i < 4 ; i++)
            pos_x[i] = 0.0;
        for(i = 0 ; i < 4 ; i++)
            pos_y[i] = 0.0;
        for(i = 0 ; i < 4 ; i++)
            wx[i] = 0.0;

        //first sine curve
        iSetColor(255, 0, 255);
        for(i = 0 ; i < 1500 ; i++)
        {
            iPoint(pos_x[0], pos_y[0], 0);
            pos_x[0] += 1.0;
            wx[0] = freq[0] * pos_x[0];
            pos_y[0] = offset + amp[0] * sin(wx[0] + p[0]);  //dx = angular frequency(w) * position(x)
        }

        //second sine curve
        iSetColor(255, 255, 0);
        for(i = 0 ; i < 1500 ; i++)
        {
            iPoint(pos_x[1], pos_y[1], 0);
            pos_x[1] += 1.0;
            wx[1] = freq[1] * pos_x[1];
            pos_y[1] = offset + amp[1] * sin(wx[1] + p[1]);  //dx = angular frequency(w) * position(x)
        }

        //single cosine curve
        iSetColor(0, 255, 255);
        for(i = 0 ; i < 1500 ; i++)
        {
            iPoint(pos_x[2], pos_y[2], 0);
            pos_x[2] += 1.0;
            wx[2] = freq[2] * pos_x[2];
            pos_y[2] = offset + amp[2] * cos(wx[2] + p[1]);  //dx = angular frequency(w) * position(x)
        }

        //sum of the 3 curves
        iSetColor(100, 150, 255);
        for(i = 0 ; i < 1500 ; i++)
        {
            iPoint(pos_x[3], pos_y[3], 0);
            pos_x[3] += 1.0;
            for(j = 0; j < 3 ; j++)
                wx[j] = freq[j] * pos_x[3];

            pos_y[3] = offset + amp[0] * sin(wx[0] + p[0]) + amp[1] * sin(wx[1] + p[1]) + amp[2] * cos(wx[2] + p[2]);  //dx = angular frequency(w) * position(x)
        }
    }

    //first ball
    if(Tb[0] == 1)
    {
        iSetColor(255, 0, 0);
        iFilledCircle(ball_x[0], ball_y[0], r[0]);
    }
    //second ball
    if(Tb[1] == 1)
    {
        iSetColor(190, 10, 255);
        iFilledCircle(ball_x[1], ball_y[1], r[1]);
    }
    //third ball
    if(Tb[2] == 1)
    {
        iSetColor(255, 255, 0);
        iFilledCircle(ball_x[2], ball_y[2], r[2]);
    }
    //fourth ball
    if(Tb[3] == 1)
    {
        iSetColor(120, 200, 40);
        iFilledCircle(ball_x[3], ball_y[3], r[3]);
    }
}

void iKeyboard(unsigned char key)
{
    if(key == 'r')
    {
        iResumeTimer(0);
    }
    if(key == 'p')
    {
        iPauseTimer(0);
    }
    if(key == 'a')
    {
        for(i = 0 ; i < 3 ; i++)
            amp[i] += 50;
    }
    if(key == 'A')
    {
        for(i = 0 ; i < 3 ; i++)
            amp[i] -= 50;
    }
    if(key == 'f')
    {
        for(i = 0 ; i < 3 ; i++)
            freq[i] += 0.005;
    }
    if(key == 'F')
    {
        for(i = 0 ; i < 3 ; i++)
            freq[i] -= 0.005;
    }
    if(key == '+')
    {
        for(i = 0 ; i < 4 ; i++)
            dist[i] += 1.0;
    }
    if(key == '-')
    {
        for(i = 0 ; i < 4 ; i++)
            dist[i] /= 1.5;
    }
    if(key == 's')
    {
        c = 1;
    }
    if(key == 'S')
    {
        c = -1;
    }
    if(key == 'h')
    {
        for(i = 0 ; i < 3 ; i++)
            p[i] += 3.1416 / 6;
    }
    if(key == 'H')
    {
        for(i = 0 ; i < 3 ; i++)
            p[i] -= 3.1416 / 6;
    }

    if(key == '1')
    {
        Tb[0] = !Tb[0];
    }
    if(key == '2')
    {
        Tb[1] = !Tb[1];
    }
    if(key == '3')
    {
        Tb[2] = !Tb[2];
    }
    if(key == '4')
    {
        Tb[3] = !Tb[3];
    }
}

void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
}

void iMouse(int button, int state, int mx, int my)
{
    /*if(button == GLUT_LEFT_BUTTON  && state == GLUT_DOWN)
    {
        offset -= 10.0;
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        offset += 10.0;
    }*/
}

void iMouseMove(int mx, int my)
{
    /*for(i = 0 ; i < 3 ; i++)
    {
        if(Tb[i] == 1)
            amp[i] = my - offset;
    }*/
}

void ballChange()
{
    for(i = 0 ; i < 3 ; i++)
    {
        if(ball_x[i] >= 1500.0)
            d[i] = -1;
        if(ball_x[i] <= 0.0)
            d[i] = 1;

        if(d[i] == 1)
        {
            ball_x[i] += dist[i];
            wx_1[i] = freq[i] * ball_x[i];
            if(i < 2)
                ball_y[i] = offset + amp[i] * sin(wx_1[i] + p[i]);
            else
                ball_y[i] = offset + amp[i] * cos(wx_1[i] + p[i]);
        }
        if(d[i] == -1)
        {
            ball_x[i] -= dist[i];
            wx_1[i] = freq[i] * ball_x[i];
            if(i < 2)
                ball_y[i] = offset + amp[i] * sin(wx_1[i] + p[i]);
            else
                ball_y[i] = offset + amp[i] * cos(wx_1[i] + p[i]);
        }
    }

    if(i == 3)
    {
        if(ball_x[3] >= 1500.0)
            d[3] = -1;
        if(ball_x[3] <= 0.0)
            d[3] = 1;

        if(d[3] == 1)
        {
            ball_x[3] += dist[3];
            for(j = 0 ; j < 3 ; j++)
                wx_1[j] = freq[j] * ball_x[j];

            ball_y[3] = offset + amp[0] * sin(wx_1[0] + p[0]) + amp[1] * sin(wx_1[1] + p[1]) + amp[2] * cos(wx_1[2] + p[2]);
        }
        else
        {
            ball_x[3] -= dist[3];
            for(j = 0 ; j < 3 ; j++)
                wx_1[j] = freq[j] * ball_x[j];

            ball_y[3] = offset + amp[0] * sin(wx_1[0] + p[0]) + amp[1] * sin(wx_1[1] + p[1]) + amp[2] * cos(wx_1[2] + p[2]);
        }
    }
}

int main()
{
    iSetTimer(20, ballChange);

    iInitialize(1500, 1000, "2 sine, 1 cosine and their sum!!");
    return 0;
}
