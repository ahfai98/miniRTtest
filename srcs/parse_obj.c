/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:27:51 by jyap              #+#    #+#             */
/*   Updated: 2024/09/15 20:36:52 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

t_obj	*last_object(t_obj	*lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	object_add_end(t_obj **lst, t_obj *new)
{
	t_obj	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = last_object(*lst);
	last->next = new;
}

void	parse_obj(char *line, t_mlxs *mlxs, t_obj_type type)
{
	t_obj	*new_obj;

	new_obj = ft_calloc(sizeof(t_obj), 1);
	if (new_obj == NULL)
		print_err_exit("Malloc failed.\n", &mlxs, line);
	mlxs->new_obj = new_obj;
	if (type == PLANE)
	{
		new_obj->type = PLANE;
		new_obj->obj_ptr = ft_calloc(sizeof(t_plane), 1);
		if (new_obj->obj_ptr == NULL)
			print_err_exit("Malloc failed.\n", &mlxs, line);
		parse_plane(line, mlxs, new_obj);
	}
	else if (type == SPHERE)
	{
		new_obj->type = SPHERE;
		new_obj->obj_ptr = ft_calloc(sizeof(t_sphere), 1);
		if (new_obj->obj_ptr == NULL)
			print_err_exit("Malloc failed.\n", &mlxs, line);
		parse_sphere(line, mlxs, new_obj);
	}
	else if (type == CYLINDER)
	{
		new_obj->type = CYLINDER;
		new_obj->obj_ptr = ft_calloc(sizeof(t_cylinder), 1);
		if (new_obj->obj_ptr == NULL)
			print_err_exit("Malloc failed.\n", &mlxs, line);
		parse_cylinder(line, mlxs, new_obj);
	}
	new_obj->next = NULL;
	object_add_end(&mlxs->sc->obj, new_obj);
	mlxs->new_obj = NULL;
}

void	parse_plane(char *line, t_mlxs *mlxs, t_obj *new_obj)
{
	char		**split;
	t_plane		*plane;

	split = ft_split(line, ' ');
	if (split == NULL)
		print_err_exit("Mallco ft_split failed.\n", &mlxs, line);
	plane = (t_plane *)new_obj->obj_ptr;
	if (count_arr_elements(split) != 4)
	{
		free_str_arr(split);
		print_err_exit("Invalid info for Plane.\n", &mlxs, line);
	}
	plane->pos = parse_coord(split, 1, line, mlxs);
	plane->norm = parse_vector(split, 2, line, mlxs);
	plane->color = parse_color(split, 3, line, mlxs);
	free_str_arr(split);
}

void	parse_sphere(char *line, t_mlxs *mlxs, t_obj *new_obj)
{
	char		**split;
	t_sphere	*sphere;

	split = ft_split(line, ' ');
	if (split == NULL)
		print_err_exit("Mallco ft_split failed.\n", &mlxs, line);
	sphere = (t_sphere *)new_obj->obj_ptr;
	if (count_arr_elements(split) != 4)
	{
		free_str_arr(split);
		print_err_exit("Invalid info for Sphere.\n", &mlxs, line);
	}
	sphere->pos = parse_coord(split, 1, line, mlxs);
	sphere->dia = parse_dia_height(split, 2, line, mlxs);
	sphere->color = parse_color(split, 3, line, mlxs);
	free_str_arr(split);
}

void	parse_cylinder(char *line, t_mlxs *mlxs, t_obj *new_obj)
{
	char		**split;
	t_cylinder	*cylinder;

	split = ft_split(line, ' ');
	if (split == NULL)
		print_err_exit("Mallco ft_split failed.\n", &mlxs, line);
	cylinder = (t_cylinder *)new_obj->obj_ptr;
	if (count_arr_elements(split) != 6)
	{
		free_str_arr(split);
		print_err_exit("Invalid info for Cylinder.\n", &mlxs, line);
	}
	cylinder->pos = parse_coord(split, 1, line, mlxs);
	cylinder->norm_axis = parse_vector(split, 2, line, mlxs);
	cylinder->dia = parse_dia_height(split, 3, line, mlxs);
	cylinder->height = parse_dia_height(split, 4, line, mlxs);
	cylinder->color = parse_color(split, 5, line, mlxs);
	free_str_arr(split);
}