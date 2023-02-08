/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:06:13 by midfath           #+#    #+#             */
/*   Updated: 2023/02/08 03:56:52 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

void	ft_put_img(t_window *w, void *img, int x, int y)
{
	mlx_put_image_to_window(w->mlx, w->win_ptr,
		img, (x * 38), (y * 38));
}

t_tileset	ft_assign_tiles(t_window *w)
{
	int		size;

	size = 38;
	w->tileset.terrain = mlx_xpm_file_to_image(w->mlx, \
		"assets/terrain.xpm", &size, &size);
	w->tileset.wall = mlx_xpm_file_to_image(w->mlx, \
		"assets/wall.xpm", &size, &size);
}

int	key_pressed(int key, t_window *w)
{
	// if ((key == KEY_W || key == KEY_UP)) 
		// ft_go_up(w);
	// else if (key == KEY_S || key == KEY_DOWN) 
		// ft_go_down(w);
	// else if (key == KEY_A || key == KEY_LEFT)
		// ft_go_right(w);
	// else if (key == KEY_D || key == KEY_RIGHT)
		// ft_go_left(w);
	if (key == KEY_ESC)
		end_window(w);
	return (0);
}


int	end_window(t_window *w)
{
	ft_matfreex(&w->map);
	mlx_clear_window(w->mlx, w->win_ptr);
	mlx_destroy_window(w->mlx, w->win_ptr);
	exit (0);
	return (0);
}
