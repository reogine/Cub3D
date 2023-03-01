/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:27:03 by aomman            #+#    #+#             */
/*   Updated: 2023/02/28 21:18:52 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"cub3d.h"

void	ft_free(t_var *var)
{
	var->i = 0;
	while (var->map_elmnt[var->i])
	{
		free (var->map_elmnt[var->i]);
		var->i++;
	}
	free (var->f_colors);
	free (var->c_colors);
	free (var->map);
	free (var->map_elmnt);
}

int	func(int argc, char **argv)
{
	t_var	*var;

	if (argc == 2)
	{
		var = malloc(sizeof(t_var));
		if (check_errors2(var, argv) == 1)
			return (1);
		ft_find_position(var);
		printf("%d\n", var->f_colors[0]);
		printf("%d\n", var->f_colors[1]);
		printf("%d\n", var->f_colors[2]);
		ft_draw_walls();
		var->map_elmnt = var->map_elmnt - 6;
		ft_free (var);
		free (var);
	}
	else
	{
		ft_putstr("programe accepet programe name + map path\n", 2);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (func(argc, argv) == 1)
		return (1);
	system("leaks parsing");
	return (0);
}