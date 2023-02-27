/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:35:11 by midfath           #+#    #+#             */
/*   Updated: 2023/02/27 17:04:12 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

void  calc_ver_line(t_window *win, t_dou_xy *hit, t_ray *ray)
{
  while ((int)floor(hit->y / TILESIZE) > 0
    && (int)floor(hit->x / TILESIZE) > 0
    && (int)floor(hit->y / TILESIZE) < win->mini_map.col
    && (int)floor(hit->x / TILESIZE) < win->mini_map.row)
  {
    if(!ray->face_up && win->map[(int)floor(hit->y / TILESIZE)]
      [(int)floor(hit->x / TILESIZE)] == '1')
        break ;
    else if (ray->face_left && win->map[(int)floor(hit->y / TILESIZE)]
        [(int)floor(hit->x / TILESIZE)] == '1')
        break ;
    if (!ray->face_left)
        hit->x += TILESIZE;
    else
      hit->x -= TILESIZE;
    hit->y = win->ply.y + (hit->x - win->ply.x) * tan(ray->angle);
  }
}

void  calc_hor_line(t_window *win, t_dou_xy *hit, t_ray *ray)
{
  while ((int)floor(hit->y / TILESIZE) > 0
    && (int)floor(hit->x / TILESIZE) > 0
    && (int)floor(hit->y / TILESIZE) < win->mini_map.col
    && (int)floor(hit->x / TILESIZE) < win->mini_map.row)
  {
    if (!ray->face_up && win->map[(int)floor((hit->y / TILESIZE))]
      [(int)floor(hit->x / TILESIZE)] == '1')
        break ;
    else if (ray->face_up && win->map[(int)floor(hit->y / TILESIZE) - 1]
        [(int)floor(hit->x / TILESIZE)] == '1')
          break ;
    if (!ray->face_up)
      hit->y += TILESIZE;
    else
      hit->y -= TILESIZE;
    hit->x = win->ply.x + (hit->y - win->ply.y) / tan(ray->angle);
  }
}

t_dou_xy   find_hit_point(t_window *win,t_ray *ray, int is_hor)
{
  t_dou_xy  hit;

  if (is_hor)
  {
    hit.y = floor(win->ply.y / TILESIZE) * TILESIZE;
    if (!ray->face_up)
      hit.y += TILESIZE;
    hit.x = win->ply.x + (hit.y -  win->ply.y) / tan(ray->angle);
    calc_hor_line(win, &hit, ray);
  }
  else
  {
    hit.x = floor(win->ply.x / TILESIZE) * TILESIZE;
    if (!ray->face_left)
      hit.y += TILESIZE;
    hit.y = win->ply.y + (hit.x - win->ply.x) * tan(ray->angle);
    calc_ver_line(win, &hit, ray);
  }
  return (hit);
}
