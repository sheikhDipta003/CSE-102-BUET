#ifndef CHECK_RIGHT_BOUND_H_INCLUDED
#define CHECK_RIGHT_BOUND_H_INCLUDED

#include "BgCoordinates.h"

int crossRB(double player_x, double player_y, int counter)
{
    if(player_x + 25 <= L_arr[14].line_x1)
    {
        counter++;
    }
    else if(player_x + 25 <= L_arr[11].line_x1)
    {
        if(player_y + 25 > L_arr[14].line_y1 && player_y < L_arr[14].line_y2)
            return 0;
        else if(player_y + 25 > L_arr[17].line_y1 && player_y < L_arr[17].line_y2)
            return 0;
        else
            counter++;
    }
    else
    {
        if(player_y + 25 > L_arr[11].line_y1 && player_y < L_arr[11].line_y2)
            return 0;
        else if(player_y + 25 > L_arr[12].line_y1 && player_y < L_arr[12].line_y2)
            return 0;
        else if(player_y + 25 > L_arr[19].line_y1 && player_y < L_arr[19].line_y2)
            return 0;
        else
            counter++;
    }

    if(counter == 1)
    {
        if(player_x + 25 <= R_arr[0].bottom_left_x)
        {
            counter++;
        }
        else if(player_x + 25 <= (R_arr[11].bottom_left_x + R_arr[11].base))
        {
            if(player_y + 25 > R_arr[0].bottom_left_y && player_y < (R_arr[0].bottom_left_y + R_arr[0].height))
                return 0;
            else if(player_y + 25 > R_arr[1].bottom_left_y && player_y < (R_arr[1].bottom_left_y + R_arr[1].height))
                return 0;
            else if(player_y + 25 > R_arr[27].bottom_left_y && player_y < (R_arr[27].bottom_left_y + R_arr[27].height))
                return 0;
            else
                counter++;
        }
        else if(player_x + 25 <= R_arr[28].bottom_left_x)
        {
            if(player_y + 25 > R_arr[21].bottom_left_y && player_y < (R_arr[21].bottom_left_y + R_arr[21].height))
                return 0;
            else
                counter++;
        }
        else if(player_x + 25 <= (R_arr[28].bottom_left_x + R_arr[28].base))
        {
            if(player_y + 25 > R_arr[28].bottom_left_y && player_y < (R_arr[28].bottom_left_y + R_arr[28].height))
                return 0;
            else
                counter++;
        }
        else if(player_x + 25 <= R_arr[2].bottom_left_x)
        {
            counter++;
        }
        else if(player_x + 25 <= (R_arr[6].bottom_left_x + R_arr[6].base))
        {
            if(player_y + 25 > R_arr[2].bottom_left_y && player_y < (R_arr[2].bottom_left_y + R_arr[2].height))
                return 0;
            else if(player_y + 25 > R_arr[6].bottom_left_y && player_y < (R_arr[6].bottom_left_y + R_arr[6].height))
                return 0;
            else if(player_y + 25 > R_arr[8].bottom_left_y && player_y < (R_arr[8].bottom_left_y + R_arr[8].height))
                return 0;
            else if(player_y + 25 > R_arr[15].bottom_left_y && player_y < (R_arr[15].bottom_left_y + R_arr[15].height))
                return 0;
            else if(player_y + 25 > R_arr[22].bottom_left_y && player_y < (R_arr[22].bottom_left_y + R_arr[22].height))
                return 0;
            else
                counter++;
        }
        else if(player_x + 25 <= R_arr[14].bottom_left_x)
        {
            counter++;
        }
        else if(player_x + 25 <= (R_arr[8].bottom_left_x + R_arr[8].base))
        {
            if(player_y + 25 > R_arr[14].bottom_left_y && player_y < (R_arr[14].bottom_left_y + R_arr[14].height))
                return 0;
            else if(player_y + 25 > R_arr[19].bottom_left_y && player_y < (R_arr[19].bottom_left_y + R_arr[19].height))
                return 0;
            else if(player_y + 25 > R_arr[26].bottom_left_y && player_y < (R_arr[26].bottom_left_y + R_arr[26].height))
                return 0;
            else if(player_y + 25 > R_arr[31].bottom_left_y && player_y < (R_arr[31].bottom_left_y + R_arr[31].height))
                return 0;
            else
                counter++;
        }
        else if(player_x + 25 <= (R_arr[2].bottom_left_x + R_arr[2].base))
        {
            counter++;
        }
        else if(player_x + 25 <= R_arr[10].bottom_left_x)
        {
            counter++;
        }
        else if(player_x + 25 <= (R_arr[10].bottom_left_x + R_arr[10].base))
        {
            if(player_y + 25 > R_arr[10].bottom_left_y && player_y < (R_arr[10].bottom_left_y + R_arr[10].height))
                return 0;
            else if(player_y + 25 > R_arr[13].bottom_left_y && player_y < (R_arr[13].bottom_left_y + R_arr[13].height))
                return 0;
            else if(player_y + 25 > R_arr[20].bottom_left_y && player_y < (R_arr[20].bottom_left_y + R_arr[20].height))
                return 0;
            else if(player_y + 25 > R_arr[25].bottom_left_y && player_y < (R_arr[25].bottom_left_y + R_arr[25].height))
                return 0;
            else
                counter++;
        }
        else if(player_x + 25 <= R_arr[3].bottom_left_x)
        {
            counter++;
        }
        else if(player_x + 25 <= R_arr[9].bottom_left_x)
        {
            if(player_y + 25 > R_arr[3].bottom_left_y && player_y < (R_arr[3].bottom_left_y + R_arr[3].height))
                return 0;
            else if(player_y + 25 > R_arr[18].bottom_left_y && player_y < (R_arr[18].bottom_left_y + R_arr[18].height))
                return 0;
            else
                counter++;
        }
        else if(player_x + 25 <= (R_arr[31].bottom_left_x + R_arr[31].base))
        {
            if(player_y + 25 > R_arr[3].bottom_left_y && player_y < (R_arr[3].bottom_left_y + R_arr[3].height))
                return 0;
            else if(player_y + 25 > R_arr[18].bottom_left_y && player_y < (R_arr[18].bottom_left_y + R_arr[18].height))
                return 0;
            else if(player_y + 25 > R_arr[9].bottom_left_y && player_y < (R_arr[9].bottom_left_y + R_arr[9].height))
                return 0;
            else if(player_y + 25 > R_arr[23].bottom_left_y && player_y < (R_arr[23].bottom_left_y + R_arr[23].height))
                return 0;
            else
                counter++;
        }
        else if(player_x + 25 <= R_arr[7].bottom_left_x)
        {
            counter++;
        }
        else if(player_x + 25 <= (R_arr[7].bottom_left_x + R_arr[7].base))
        {
            if(player_y + 25 > R_arr[7].bottom_left_y && player_y < (R_arr[7].bottom_left_y + R_arr[7].height))
                return 0;
            else if(player_y + 25 > R_arr[17].bottom_left_y && player_y < (R_arr[17].bottom_left_y + R_arr[17].height))
                return 0;
            else if(player_y + 25 > R_arr[24].bottom_left_y && player_y < (R_arr[24].bottom_left_y + R_arr[24].height))
                return 0;
            else
                counter++;
        }
        else if(player_x + 25 <= R_arr[4].bottom_left_x)
        {
            counter++;
        }
        else if(player_x + 25 <= (R_arr[29].bottom_left_x + R_arr[29].base))
        {
            if(player_y + 25 > R_arr[4].bottom_left_y && player_y < (R_arr[4].bottom_left_y + R_arr[4].height))
                return 0;
            else if(player_y + 25 > R_arr[5].bottom_left_y && player_y < (R_arr[5].bottom_left_y + R_arr[5].height))
                return 0;
            else if(player_y + 25 > R_arr[29].bottom_left_y && player_y < (R_arr[29].bottom_left_y + R_arr[29].height))
                return 0;
            else if(player_y + 25 > R_arr[30].bottom_left_y && player_y < (R_arr[30].bottom_left_y + R_arr[30].height))
                return 0;
            else
                counter++;
        }
        else if(player_x + 25 <= R_arr[12].bottom_left_x)
        {
            counter++;
        }
        else
        {
            if(player_y + 25 > R_arr[12].bottom_left_y && player_y < (R_arr[12].bottom_left_y + R_arr[12].height))
                return 0;
            else
                counter++;
        }

        return 1;
    }
}

#endif // CHECK_RIGHT_BOUND_H_INCLUDED
