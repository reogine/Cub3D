/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostapha <mostapha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:44:09 by midfath           #+#    #+#             */
/*   Updated: 2023/02/08 13:24:48 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing/cub3d.h"
#include<window.h>

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
	t_window  *win;

	if (argc == 2)
	{
		var = malloc(sizeof(t_var));
		if (check_errors2(var, argv) == 1)
			return (1);
		ft_find_position(var);
		win = init_win(var);
		open_window(win);
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
	return (0);
}

// int main()
// {
//   
// }
