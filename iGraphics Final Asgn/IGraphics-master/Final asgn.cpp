# include "iGraphics.h"
# include "check_left_bound.h"
# include "check_right_bound.h"
# include "check_up_bound.h"
# include "check_low_bound.h"
# include "BgCoordinates.h"

//images of pacman moving
char movePac[12][25] = {"pacman left 1.BMP",
                   "pacman left 2.BMP",
                   "pacman left 3.BMP",
                   "pacman right 1.BMP",
                   "pacman right 2.BMP",
                   "pacman right 3.BMP",
                   "pacman up 1.BMP",
                   "pacman up 2.BMP",
                   "pacman up 3.BMP",
                   "pacman down 1.BMP",
                   "pacman down 2.BMP",
                   "pacman down 3.BMP"
};

//char moveGhosts[8][15] = { "Blinky 1.BMP", "Blinky 2.BMP", "Blinky 3.BMP", "Blinky 4.BMP", "Blinky 5.BMP", "Blinky 6.BMP",
//                           "Blinky 7.BMP", "Blinky 8.BMP"
//};

double ABS(double x)
{
    if(x > 0.0)
        return x;
    else
        return(-x);
}

//int x = 300, y = 300, r = 15;
int mode[4] = {0}, game_state = 0, player_x = 730, player_y = 290, j, counter;
int pos_y[4] = {655, 585, 515, 445};

int moving = 10, indPacL = 0, indPacR = 3, indPacU = 6, indPacD = 9;
int player_time_sec = 0, display_time_sec = 0, display_time_hr = 0, display_time_min = 0;
int Dots = 0, score, C[247] = {0};

/*
	function iDraw() is called again and again by the system.
*/

void drawTextBox(int i)
{
    iSetColor(255, 255, 0);
    iFilledRectangle(1250, pos_y[i], 155, 60);
}

void iDraw()
{
    //place your drawing codes here
//    iClear();
//    iSetColor(20,200,255);
//    iFilledCircle(x,y,r);
    iClear();

    if(game_state == 0)
    {
        drawTextBox(0);     //START OPTION
        if(mode[0] == 1)
        {
            iSetColor(255, 0, 0);
            game_state = 1;
        }
        else
            iSetColor(50, 100, 200);

        iText(1290, 675, "START", GLUT_BITMAP_TIMES_ROMAN_24);

        drawTextBox(1);         //RESUME OPTION
        if(mode[1] == 1)
        {
            iSetColor(255, 0, 0);
        }
        else
            iSetColor(50, 100, 200);

        iText(1280, 605, "RESUME", GLUT_BITMAP_TIMES_ROMAN_24);

        drawTextBox(2);           //HIGHEST SCORE OPTION
        if(mode[2] == 1)
        {
            iSetColor(255, 0, 0);
        }
        else
            iSetColor(50, 100, 200);

        iText(1255, 535, "HIGH SCORE", GLUT_BITMAP_TIMES_ROMAN_24);

        drawTextBox(3);
        if(mode[3] == 1)
        {
            iSetColor(255, 0, 0);
        }
        else
            iSetColor(50, 100, 200);

        iText(1295, 465, "EXIT", GLUT_BITMAP_TIMES_ROMAN_24);

        iShowBMP(50, 150, "pacman start screen.BMP");
        iShowBMP(800, 350, "pacman start screen_2.BMP");
        iShowBMP(860, 300, "pacman start screen_3.BMP");
    }
    else
    {
        iShowBMP(500, 300, "black bgd.BMP");
        drawbackground();

        if(moving == -10 || moving == -1)
            iShowBMP2(player_x, player_y, movePac[indPacL], 0x00000000);
        else if(moving == 10 || moving == 1)
            iShowBMP2(player_x, player_y, movePac[indPacR], 0x00000000);
        else if(moving == 20 || moving == 2)
            iShowBMP2(player_x, player_y, movePac[indPacU], 0x00000000);
        else if(moving == -20 || moving == -2)
            iShowBMP2(player_x, player_y, movePac[indPacD], 0x00000000);

        char buffer[20];
        iSetColor(255, 0, 0);
        iText(1000, 920, "TIME: ", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(1070, 920, itoa(display_time_hr, buffer, 10), GLUT_BITMAP_TIMES_ROMAN_24);
        iText(1100, 920, itoa(display_time_min, buffer, 10), GLUT_BITMAP_TIMES_ROMAN_24);
        iText(1130, 920, itoa(display_time_sec, buffer, 10), GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(100, 0, 255);
        iText(300, 920, "SCORE: ", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(390, 920, itoa(score, buffer, 10), GLUT_BITMAP_TIMES_ROMAN_24);
    }

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    //place your codes here
        //printf("x = %d, y= %d\n",mx,my);
//        x += 5;
//        y += 5;
    if(game_state == 0 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx >= 1250 && mx <= 1405 && my >= (pos_y[0] + 60) && my <= (pos_y[0] + 120))
        {
            mode[0] = 1;
            game_state = 1;
        }
        else if(mx >= 1250 && mx <= 1405 && my >= (pos_y[1] + 60) && my <= (pos_y[1] + 120))
        {
            mode[1] = 1;
        }
        else if(mx >= 1250 && mx <= 1405 && my >= (pos_y[2] + 60) && my <= (pos_y[2] + 120))
        {
            mode[2] = 1;
        }
        else if(mx >= 1250 && mx <= 1405 && my >= (pos_y[3] + 60) && my <= (pos_y[3] + 120))
        {
            mode[3] = 1;
            exit(0);
        }
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(game_state == 1)
    {
        if(key == 'r')
        {
            iResumeTimer(0);
        }
        if(key == 'p')
        {
            iPauseTimer(0);
        }
    }
    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
    if(game_state == 1)
    {
        if(key == GLUT_KEY_END)
        {
            exit(0);
        }
        if(key == GLUT_KEY_HOME)
        {
            game_state = 0;
        }
        if(key == GLUT_KEY_LEFT)
        {
            moving = -1;
        }
        if(key == GLUT_KEY_RIGHT)
        {
            moving = 1;
        }
        if(key == GLUT_KEY_UP)
        {
            moving = 2;
        }
        if(key == GLUT_KEY_DOWN)
        {
            moving = -2;
        }
    }
    //place your codes for other keys here
}

void changePacman()
{
    if(moving == -1)
    {
        if(crossLB(player_x - 10, player_y, 0))
        {
            player_x = player_x - 10;

            indPacL++;
            if(indPacL >= 3)
                indPacL = 0;
        }
        else
        {
            moving = -10;
            indPacL = 0;
        }
    }
    else if(moving == 1)
    {
        if(crossRB(player_x + 10, player_y, 0))
        {
            player_x = player_x + 10;

            indPacR++;
            if(indPacR >= 6)
                indPacR = 3;
        }
        else
        {
            moving = 10;
            indPacR = 3;
        }

    }
    else if(moving == 2)
    {
        if(crossUB(player_x, player_y + 10, 0) )
        {
            player_y = player_y + 10;

            indPacU++;
            if(indPacU >= 9)
                indPacU = 6;
        }
        else
        {
            moving = 20;
            indPacU = 6;
        }
    }
    else if(moving == -2)
    {
        if( crossLowB(player_x, player_y - 10, 0) )
        {
            player_y = player_y - 10;

            indPacD++;
            if(indPacD >= 12)
                indPacD = 9;
        }
        else
        {
            moving = -20;
            indPacD = 9;
        }
    }

//    indBlinky++;
//    if(indBlinky >= 8)
//            indBlinky = 0;
    player_time_sec += 50;
    display_time_sec = player_time_sec / 1000;
    display_time_min = (player_time_sec / 1000) / 60;
    display_time_hr = ( (player_time_sec / 1000) / 60 ) / 60;
    if(display_time_sec >= 60)
        display_time_sec = display_time_sec % 60;

    for(i = 0 ; i < NumOfDots ; i++)
        if(ABS(player_x - x[i]) <= 10.0  &&  ABS(player_y - y[i]) <= 15.0)
        {
            p[i] = 1;
            C[i]++;
            if(i != 51 && i != 56 && i != 110 && i != 153 && i != 154 && i != 208 && i != 223 && i != 240 && C[i] == 1)
                score += 10;
        }
}


int main()
{
    //place your own initialization codes here.
    iSetTimer(50, changePacman);
    iInitialize(1500, 1000, "Pacman");

    return 0;
}

