/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:41:23 by fabien            #+#    #+#             */
/*   Updated: 2024/09/20 10:16:59 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

bool	is_closest(t_inter *closest, t_inter *temp);

/* retruns the closest intersection in the ray */
t_inter	*closest_inter(t_rt *rt, t_ray *ray)
{
	t_inter		*closest;
	t_inter		*temp;
	t_objects	*curr_fig;

	closest = calloc_utils();
	closest->dist = INFINITY;
	curr_fig = rt->sc->obj;
	while (curr_fig)
	{
		closest->i = curr_fig->i;
		if (curr_fig->type == PLANE)
			temp = intersect_plane(ray, &curr_fig->fig.pl);
		else if (curr_fig->type == SPHERE)
			temp = intersect_sphere(ray, &curr_fig->fig.sp);
		else if (curr_fig->type == CYLINDER)
			temp = intersect_cylinder(ray, &curr_fig->fig.cy);
		if (temp == NULL)
		{
			free(closest);
			print_error("Malloc failed.\n");
		}
		if (is_closest(closest, temp))
		{
			free(closest);
			closest = temp;
			closest->i = curr_fig->i;
		}
		else
			free(temp);
		curr_fig = curr_fig->next;
	}
	return (closest);
}

bool	is_closest(t_inter *closest, t_inter *temp)
{
	if (temp->dist == INFINITY || temp->dist < 0)
		return (false);
	if (closest->dist == INFINITY)
		return (true);
	else if (temp->dist < closest->dist)
		return (true);
	return (false);
}