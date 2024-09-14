/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:28:10 by tjien-ji          #+#    #+#             */
/*   Updated: 2024/09/14 17:05:51 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "vect.h"
# include "color.h"

typedef struct s_cylinder
{
	t_vect	pos;
	t_vect	norm_axis;
	t_color	color;
	double	dia;
	double	height;
}	t_cylinder;

t_cylinder	cylinder(t_vect pos, t_vect norm_axis, t_color color,
				double size_info[2]);
t_cylinder	*create_cylinder(t_vect pos, t_vect norm_axis, t_color color,
				double size_info[2]);
void		delete_cylinder(t_cylinder *ptr_cylinder);

#endif
