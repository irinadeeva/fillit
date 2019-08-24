/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:55:36 by amargy            #+#    #+#             */
/*   Updated: 2019/08/22 23:05:28 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		input_figure_valid(char *buff)
{
	int index;
	int coupling;

	index = 0;
	coupling = 0;
	while (buff[index])
	{
		if (buff[index] == '#')
		{
			if (buff[index + 1] == '#')
				coupling++;
			if (index != 0 && buff[index - 1] == '#')
				coupling++;
			if (index <= 13 && buff[index + 5] == '#')
				coupling++;
			if (index >= 5 && buff[index - 5] == '#')
				coupling++;
		}
		index++;
	}
	if (coupling == 6 || coupling == 8)
		return (1);
	return (0);
}

int		input_field_valid(char *buff)
{
	int	point;
	int grill;
	int slash_n;
	int index;

	point = 0;
	grill = 0;
	slash_n = 0;
	index = 0;
	while (buff[index])
	{
		if (buff[index] == '.')
			point++;
		if (buff[index] == '#')
			grill++;
		if (buff[index] == '\n')
			slash_n++;
		index++;		
	}
	if (point == 12 && grill == 4 && (slash_n == 5 || slash_n == 4))
		return (1);
	return (0);
}

int		input_valid(int fd)
{
	int ret;
	char buff[22];
	int	first_read_check;
	
	first_read_check = 0;
	while ((ret = read(fd, buff, 21)) > 0)
	{
		if (ret != 21 && ret != 20)
			return (0);	
		first_read_check++;
		buff[ret] = '\0';
		if (!(input_field_valid(buff)))
			return (0);
		if (!(input_figure_valid(buff)))
			return (0);			
	}	
	if (first_read_check == 0 || first_read_check == 1)
			return (0);
	return (1);
}
