#include "fillit.h"

void    put_figure_in_structure(int fd, figure_struct *figure_depot)
{
    char buff[22];
    int ret;

    while ((ret = read(fd, buff, 21)) > 0)
    {
        buff[ret] = '\0';
    }
}