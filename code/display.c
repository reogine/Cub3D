/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:06:13 by midfath           #+#    #+#             */
/*   Updated: 2023/02/12 18:31:47 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

void	ft_put_img(t_window *w, void *img, int x, int y)
{
	mlx_put_image_to_window(w->mlx, w->win_ptr,
		img, (x * 38), (y * 38));
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
	 // ft_matfreex(&w->map);
	// mlx_clear_window(w->mlx, w->win_ptr);
	// mlx_destroy_window(w->mlx, w->win_ptr);
  free(w->mlx);
	exit (0);
}
