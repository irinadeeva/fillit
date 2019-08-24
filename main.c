/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:21:40 by amargy            #+#    #+#             */
/*   Updated: 2019/08/22 23:05:30 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int	fd;

	figure_struct	figure_depot[26];
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0) 
		{
		 	ft_putendl("error");
				 return (0);
		}
		if (input_valid(fd) == 0 ) 
		{
			ft_putendl("error");
			return (0);
		} 
		// mistake in the next function - it does nothing  
		put_figure_in_structure(fd, figure_depot);
	}
	else		
		ft_putendl("usage: ./fillit input_file");
	return (0);
}
