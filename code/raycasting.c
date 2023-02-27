/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:40:11 by midfath           #+#    #+#             */
/*   Updated: 2023/02/27 16:56:20 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

void  ray_hit(t_window  *win, double rot_ang, int indx)
{
  t_ray      *ray;
  double      dis_ver;
  double      dis_hor;
  t_dou_xy    hor_hit;
  t_dou_xy    ver_hit;

  ray = &win->rays[indx];
  ray->angle = rot_ang;
  ray->face_up = ((ray->angle > P) && (ray->angle < 2 * P));
  ray->face_left = ((ray->angle > P / 2) && (ray->angle < 3 * P / 2));
  hor_hit = find_hit_point(win, ray, 1); 
  ver_hit = find_hit_point(win, ray, 0);
  dis_hor = fabs((hor_hit.x - win->ply.x) / cos(rot_ang));
  dis_ver = fabs((ver_hit.y - win->ply.y) / sin(rot_ang));
  if (dis_hor < dis_ver)
  {
    ray->hit_x = hor_hit.x;
    ray->hit_y = hor_hit.y;
    ray->distance = dis_hor;
    ray->is_horizontal = 1;
  }
  else 
  {
    ray->hit_x = ver_hit.x;
    ray->hit_y = ver_hit.y;
    ray->distance = dis_ver;
    ray->is_horizontal = 0;
  }
}

void  rays_calc(t_window *win)
{
  double ang;
  int    r;

  ang = win->ply.rot_ang - (FOV * ( P / 180)) / 2;
  r = 0;
  while (r < win->width)
  {
    if (ang < 0)
      ang = ang + 2 * P;
    else if (ang > 2 * P)
      ang = ang - 2 * P;
    ray_hit(win, ang, r);
    ang += (FOV * (P / 180)) / WIN_W;
    r++;
  }
}

void  rays_display(t_window *win)
{
  if (win)
    return ;
}
