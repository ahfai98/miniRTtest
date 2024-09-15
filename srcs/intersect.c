/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:27:50 by jyap              #+#    #+#             */
/*   Updated: 2024/09/15 18:45:13 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

bool is_closest(t_inter *closest, t_inter *temp)
{
	if (temp->dist == INFINITY)
		return (false);
	if (closest->dist == INFINITY)
		return (true);
	else if (temp->dist < closest->dist)
		return (true);
	return (false);
}

void	closest_inter(t_mlxs *mlxs, t_ray *ray)
{
	t_inter		*closest;
	t_inter		*temp;
	t_obj	*curr_fig;

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
		if (closest && temp->dist > 0 && is_closest(closest, temp))
			free_inter(closest);
		if (closest && temp->dist > 0 && is_closest(closest, temp))
			closest = temp;
		else
			free_inter(temp);
		curr_fig = curr_fig->next;
	}
	return (closest);
}