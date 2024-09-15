/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_pl_sp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:11:37 by jyap              #+#    #+#             */
/*   Updated: 2024/09/15 22:34:49 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

t_inter	*intersect_plane(t_ray *ray, t_plane *plane)
{
	t_inter	*inter;
	double	t;
	double	denom;

	inter = ft_calloc(sizeof(t_inter), 1);
	if (inter == NULL)
		return (NULL);
	plane->norm = normalize(plane->norm);
	denom = dot_product(plane->norm, ray->dir);
	if (fabs(denom) < 1e-6)
	{
		inter->dist = INFINITY;
		return (inter);
	}
	t = dot_product(sub(plane->pos, ray->pos), plane->norm) / denom;
	if (t < 1e-4)
	{
		inter->dist = INFINITY;
		return (inter);
	}
	inter->type = PLANE;
	inter->obj_ptr = plane;
	inter->dist = t;
	inter->point = add(ray->pos, mult(ray->dir, t));
	//inter->point = add(inter->point, mult(inter->normal, E));
	inter->normal = plane->norm;
	return (inter);
}

t_inter	*intersect_sphere(t_ray *ray, t_sphere *sphere)
{
	t_inter	*inter;
	t_vect	origin_center;
	double	t;

	inter = ft_calloc(sizeof(t_inter), 1);
	if (inter == NULL)
		return (NULL);
	origin_center = sub(ray->pos, sphere->pos);
	t = solve_quadratic(dot_product(ray->dir, ray->dir), 2.0 * \
	dot_product(origin_center, ray->dir), 
	dot_product(origin_center, origin_center) 
	- sphere->dia / 2 * sphere->dia / 2);
	if (t < 0)
	{
		inter->dist = INFINITY;
		return (inter);
	}
	inter->type = SPHERE;
	inter->obj_ptr = sphere;
	inter->dist = t;
	inter->point = add(ray->pos, mult(ray->dir, t));
	inter->normal = normalize(sub(inter->point, sphere->pos));
	return (inter);
}