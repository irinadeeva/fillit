/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 19:39:45 by amargy            #+#    #+#             */
/*   Updated: 2019/08/22 20:30:20 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct figure_struct
{
	int		x[4];
	int		y[4];
	int		height;
	int		width;	
	char	letter;
}			figure_struct;

int		input_valid(int fd);
void    put_figure_in_structure(int fd, figure_struct *figure_depot);

#endif




