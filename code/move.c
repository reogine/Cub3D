/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:37:22 by midfath           #+#    #+#             */
/*   Updated: 2023/03/02 23:46:56 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

void	ft_go_up(t_window *w)
{
	double	new_x;
	double	new_y;
	int		des;

	new_x = w->ply.x + cos(w->ply.rot_ang) * PPM;
	new_y = w->ply.y + sin(w->ply.rot_ang) * PPM;
	des = valid_des(w, new_x, new_y);
	if (!des)
		return ;
	if (des == 2)
	{
		if (valid_des(w, new_x, w->ply.y) == 1)
			w->ply.x += cos(w->ply.rot_ang) * (PPM / 2);
		else if (valid_des(w, new_y, w->ply.y) == 1)
			w->ply.y += sin(w->ply.rot_ang) * (PPM / 2);
	}
	else
	{
		w->ply.x = new_x;
		w->ply.y = new_y;
	}
}

void	ft_go_down(t_window *w)
{
	double	new_x;
	double	new_y;
	int		des;

	new_x = w->ply.x - cos(w->ply.rot_ang) * PPM;
	new_y = w->ply.y - sin(w->ply.rot_ang) * PPM;
	des = valid_des(w, new_x, new_y);
	if (!des)
		return ;
	if (des == 2)
	{
		if (valid_des(w, new_x, w->ply.y) == 1)
			w->ply.x -= cos(w->ply.rot_ang) * (PPM / 2);
		else if (valid_des(w, new_y, w->ply.y) == 1)
			w->ply.y -= sin(w->ply.rot_ang) * (PPM / 2);
	}
	else
	{
		w->ply.x = new_x;
		w->ply.y = new_y;
	}
}

void	ft_go_left(t_window *w)
{
	double	new_x;
	double	new_y;
	int		des;

	new_x = w->ply.x - cos(w->ply.rot_ang + (M_PI / 2)) * PPM;
	new_y = w->ply.y - sin(w->ply.rot_ang + (M_PI / 2)) * PPM;
	des = valid_des(w, new_x, new_y);
	if (!des)
		return ;
	if (des == 2)
	{
		if (valid_des(w, new_x, w->ply.y) == 1)
			w->ply.x -= cos(w->ply.rot_ang + (M_PI / 2)) * (PPM / 2);
		else if (valid_des(w, new_y, w->ply.y) == 1)
			w->ply.y -= sin(w->ply.rot_ang + (M_PI / 2)) * (PPM / 2);
	}
	else
	{
		w->ply.x = new_x;
		w->ply.y = new_y;
	}
}

void	ft_go_right(t_window *w)
{
	double	new_x;
	double	new_y;
	int		des;

	new_x = w->ply.x + cos(w->ply.rot_ang + (M_PI / 2)) * PPM;
	new_y = w->ply.y + sin(w->ply.rot_ang + (M_PI / 2)) * PPM;
	des = valid_des(w, new_x, new_y);
	if (!des)
		return ;
	if (des == 2)
	{
		if (valid_des(w, new_x, w->ply.y) == 1)
			w->ply.x += cos(w->ply.rot_ang + (M_PI / 2)) * (PPM / 2);
		else if (valid_des(w, new_y, w->ply.y) == 1)
			w->ply.y += sin(w->ply.rot_ang + (M_PI / 2)) * (PPM / 2);
	}
	else
	{
		w->ply.x = new_x;
		w->ply.y = new_y;
	}
}
