#include "fillit.h"

int    size_figure(int *coord_mas)
{
    int index;
    int max;

    index = 0;
    max = 0;
    while (index < 4)
    {
        if (max > coord_mas[index])
            max = coord_mas[index];
        index++;
    }
    return (++max);
}

int     move_in_out(int *coord_mas)
{
    int index;

    index = 0;
    while (index < 4)
    {
        if (coord_mas[index] == 0)
            return (0);
        index++;
    }
    while (index > 0)
    {
        coord_mas[index]--;
        index--;
    }
    return (move_in_out(&coord_mas[index)]);
}

void    put_figure_in_xy(int struct_index, char *buff, figure_struct *figure_depot)
{
    int xy_index;
    int buff_index;

    buff_index = 0;
    xy_index  = 0;
    while (buf[buff_index++])
    {
        if (buff[buff_index] == #)
        {
            figure_depot[struct_index]->x[xy_index] = buff_index % 5;
            figure_depot[struct_index]->y[xy_index++] = buff_index / 5;
        }
    }
}

void    put_figure_in_structure(int fd, figure_struct *figure_depot)
{
    char buff[22];
    int ret;
    int struct_index;
    
    struct_index = 0;
    figure_depot[struct_index].letter = A - 1;
    while (ret = read(fd, buff, 21) > 0)
    {
        buff[ret] = '\0';
        put_figure_in_xy(struct_index, buff, figure_depot)
        move_in_out(&(figure_depot[struct_index]->x));
        move_in_out(&(figure_depot[struct_index]->y));
        figure_depot[struct_index].width = size_figure(&(figure_depot[struct_index]->x));
        figure_depot[struct_index].height = size_figure(&(figure_depot[struct_index]->y));
        figure_depot[struct_index].letter = ++figure_depot[struct_index].letter;
         struct_index++;
    }
}
