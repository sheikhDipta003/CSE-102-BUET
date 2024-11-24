#ifndef CHECK_LOW_BOUND_H_INCLUDED
#define CHECK_LOW_BOUND_H_INCLUDED

#include "BgCoordinates.h"

int crossLowB(double player_x, double player_y, int counter)
{
    if(player_y >= L_arr[2].line_y1)       counter++;
    else if(player_y >= L_arr[4].line_y1)
    {
        if(player_x >= L_arr[2].line_x1 && player_x <= L_arr[2].line_x2)    return 0;
        else if(player_x + 25 >= L_arr[18].line_x1 && player_x + 25 <= L_arr[18].line_x2)   return 0;
        else    counter++;
    }
    else if(player_y >= L_arr[5].line_y1)   counter++;
    else if(player_y >= L_arr[7].line_y1)
    {
        if(player_x >= L_arr[5].line_x1 && player_x <= L_arr[5].line_x2)    return 0;
        else if(player_x + 25 >= L_arr[15].line_x1 && player_x + 25 <= L_arr[15].line_x2)   return 0;
        else    counter++;
    }
    else if(player_y >= L_arr[10].line_y1)   counter++;
    else    return 0;

    if(counter == 1)
    {
        if( player_y >= (R_arr[0].bottom_left_y + R_arr[0].height) )    counter++;
        else if(player_y >= R_arr[0].bottom_left_y)
        {
            if(player_x + 25 >= R_arr[0].bottom_left_x && player_x <= (R_arr[0].bottom_left_x + R_arr[0].base) )
                return 0;
            else if(player_x >= R_arr[2].bottom_left_x && player_x <= (R_arr[2].bottom_left_x + R_arr[2].base) )
                return 0;
            else if(player_x + 25 >= R_arr[3].bottom_left_x && player_x + 25 <= (R_arr[3].bottom_left_x + R_arr[3].base) )
                return 0;
            else if(player_x >= R_arr[5].bottom_left_x && player_x <= (R_arr[5].bottom_left_x + R_arr[5].base) )
                return 0;
            else if(player_x + 25 >= R_arr[10].bottom_left_x && player_x + 25 <= (R_arr[10].bottom_left_x + R_arr[10].base) )
                return 0;
            else
                counter++;
        }
        else if( player_y >= (R_arr[1].bottom_left_y + R_arr[1].height) )       counter++;
        else if(player_y >= R_arr[1].bottom_left_y)
        {
            if(player_x + 25 >= R_arr[1].bottom_left_x && player_x <= (R_arr[1].bottom_left_x + R_arr[1].base) )
                return 0;
            else if(player_x >= R_arr[4].bottom_left_x && player_x <= (R_arr[4].bottom_left_x + R_arr[4].base) )
                return 0;
            else if(player_x + 25 >= R_arr[14].bottom_left_x && player_x + 25 <= (R_arr[14].bottom_left_x + R_arr[14].base) )
                return 0;
            else if(player_x + 25 >= R_arr[15].bottom_left_x && player_x <= (R_arr[15].bottom_left_x + R_arr[15].base) )
                return 0;
            else if(player_x + 25 >= R_arr[17].bottom_left_x && player_x <= (R_arr[17].bottom_left_x + R_arr[17].base) )
                return 0;
            else
                counter++;
        }
        else if( player_y >= (R_arr[16].bottom_left_y + R_arr[16].height) )     counter++;
        else if(player_y >= R_arr[16].bottom_left_y)
        {
            if(player_x >= R_arr[16].bottom_left_x && player_x <= (R_arr[16].bottom_left_x + R_arr[16].base) )
                return 0;
            else if(player_x + 25 >= R_arr[18].bottom_left_x && player_x + 25 <= (R_arr[18].bottom_left_x + R_arr[18].base) )
                return 0;
            else
                counter++;
        }
        else if( player_y >= (R_arr[31].bottom_left_y + R_arr[31].height) )     counter++;
        else if( player_y >= R_arr[15].bottom_left_y )
        {
            if(player_x + 25 >= R_arr[31].bottom_left_x && player_x <= (R_arr[31].bottom_left_x + R_arr[31].base) )
                return 0;
            else
                counter++;
        }
        else if( player_y >= (R_arr[6].bottom_left_y + R_arr[6].height) )       counter++;
        else if( player_y >= (R_arr[19].bottom_left_y + R_arr[19].height) )
        {
            if(player_x + 25 >= R_arr[6].bottom_left_x && player_x <= (R_arr[6].bottom_left_x + R_arr[6].base) )
                return 0;
            else if(player_x + 25 >= R_arr[7].bottom_left_x && player_x <= (R_arr[7].bottom_left_x + R_arr[7].base) )
                return 0;
            else
                counter++;
        }
        else if(player_y >= R_arr[6].bottom_left_y)
        {
            if(player_x + 25 >= R_arr[19].bottom_left_x && player_x <= (R_arr[19].bottom_left_x + R_arr[19].base) )
                return 0;
            else
                counter++;
        }
        else if( player_y >= (R_arr[8].bottom_left_y + R_arr[8].height) )       counter++;
        else if( player_y >= R_arr[27].bottom_left_y )
        {
            if(player_x + 25 >= R_arr[8].bottom_left_x && player_x <= (R_arr[8].bottom_left_x + R_arr[8].base) )
                return 0;
            else if(player_x + 25 >= R_arr[9].bottom_left_x && player_x <= (R_arr[9].bottom_left_x + R_arr[9].base) )
                return 0;
            else if(player_x + 25 >= R_arr[27].bottom_left_x && player_x <= (R_arr[27].bottom_left_x + R_arr[27].base) )
                return 0;
            else if(player_x + 25 >= R_arr[30].bottom_left_x && player_x <= (R_arr[30].bottom_left_x + R_arr[30].base) )
                return 0;
            else
                counter++;
        }
        else if( player_y >= (R_arr[11].bottom_left_y + R_arr[11].height) )     counter++;
        else if( player_y >= R_arr[11].bottom_left_y )
        {
            if(player_x >= R_arr[11].bottom_left_x && player_x <= (R_arr[11].bottom_left_x + R_arr[11].base) )
                return 0;
            else if(player_x + 25 >= R_arr[12].bottom_left_x && player_x + 25 <= (R_arr[12].bottom_left_x + R_arr[12].base) )
                return 0;
            else
                counter++;
        }
        else if( player_y >= R_arr[26].bottom_left_y )
        {
            if(player_x >= R_arr[22].bottom_left_x && player_x <= (R_arr[22].bottom_left_x + R_arr[22].base) )
                return 0;
            else if(player_x + 25 >= R_arr[24].bottom_left_x && player_x <= (R_arr[24].bottom_left_x + R_arr[24].base) )
                return 0;
            else if(player_x + 25 >= R_arr[26].bottom_left_x && player_x + 25 <= (R_arr[26].bottom_left_x + R_arr[26].base) )
                return 0;
            else
                counter++;
        }
        else if( player_y >= (R_arr[21].bottom_left_y + R_arr[21].height) )     counter++;
        else if( player_y >= R_arr[21].bottom_left_y )
        {
            if(player_x + 25 >= R_arr[21].bottom_left_x && player_x <= (R_arr[21].bottom_left_x + R_arr[21].base) )
                return 0;
            else if(player_x + 25 >= R_arr[23].bottom_left_x && player_x <= (R_arr[23].bottom_left_x + R_arr[23].base) )
                return 0;
            else
                counter++;
        }

        return 1;
    }
}

#endif // CHECK_LOW_BOUND_H_INCLUDED
