/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:27:51 by jyap              #+#    #+#             */
/*   Updated: 2024/09/14 20:48:49 by jyap             ###   ########.fr       */
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

void	parse_obj(char *line, t_mlxs *mlxs, int type)
{
	t_obj	*new_obj;

	new_obj = ft_calloc(sizeof(t_obj), 1);
	if (new_obj == NULL)
	{
		free_scene(mlxs->sc);
		print_err_exit("Malloc failed.\n", mlxs, 1);
	}
	if (type == 1)
	{
		new_obj->type = 1;
		new_obj->obj_ptr = ft_calloc(sizeof(t_plane), 1);
		if (new_obj->obj_ptr == NULL)
		{
			free(new_obj);
			free_scene(mlxs->sc);
			print_err_exit("Malloc failed.\n", mlxs, 1);
		}
		new_obj->obj_ptr = parse_plane(line, new_obj, mlxs);
	}
	else if (type == 2)
	{
		new_obj->type = 2;
		new_obj->obj_ptr = ft_calloc(sizeof(t_sphere), 1);
		if (new_obj->obj_ptr == NULL)
		{
			free(new_obj);
			free_scene(mlxs->sc);
			print_err_exit("Malloc failed.\n", mlxs, 1);
		}
		new_obj->obj_ptr = parse_sphere(line, new_obj, mlxs);
	}
	else if (type == 3)
	{
		new_obj->type = 3;
		new_obj->obj_ptr = ft_calloc(sizeof(t_cylinder), 1);
		if (new_obj->obj_ptr == NULL)
		{
			free(new_obj);
			free_scene(mlxs->sc);
			print_err_exit("Malloc failed.\n", mlxs, 1);
		}
		new_obj->obj_ptr = parse_cylinder(line, new_obj, mlxs);
	}
	new_obj->next = NULL;
	object_add_end(&mlxs->sc->obj, new_obj);
}

t_plane	plane_parsing(char *line)
{
	int			i;
	char		**tab;
	t_plane		plane;

	i = 0;
	tab = ft_split(line, ' ');
	ft_bzero(&plane, sizeof(t_plane));
	plane.id = "pl";
	if (count_elements(tab) != 4)
		print_error("wrong number of elements for plane");
	while (tab[++i])
	{
		if (i == 1)
			plane.coord = parse_coord(tab[i], plane.coord);
		else if (i == 2)
			plane.ori = parse_vector(tab[i], plane.ori);
		else if (i == 3)
			plane.color = parse_color(tab[i], plane.color);
	}
	free_tab(tab);
	return (plane);
}

t_sphere	sphere_parsing(char *line)
{
	int			i;
	char		**tab;
	t_sphere	sphere;

	i = 0;
	tab = ft_split(line, ' ');
	ft_bzero(&sphere, sizeof(t_sphere));
	sphere.id = "sp";
	if (count_elements(tab) != 4)
		print_error("wrong number of elements for sphere");
	while (tab[++i])
	{
		if (i == 1)
			sphere.coord = parse_coord(tab[i], sphere.coord);
		else if (i == 2)
			sphere.r = parse_other(tab[i], sphere.r, 2) / 2;
		else if (i == 3)
			sphere.color = parse_color(tab[i], sphere.color);
	}
	free_tab(tab);
	return (sphere);
}

t_cylinder	cylinder_parsing(char *line)
{
	int			i;
	char		**tab;
	t_cylinder	cylinder;

	i = 0;
	tab = ft_split(line, ' ');
	ft_bzero(&cylinder, sizeof(t_cylinder));
	cylinder.id = "cy";
	if (count_elements(tab) != 6)
		print_error("wrong number of elements for cylinder");
	while (tab[++i])
	{
		if (i == 1)
			cylinder.coord = parse_coord(tab[i], cylinder.coord);
		else if (i == 2)
			cylinder.norm_vec = parse_vector(tab[i], cylinder.norm_vec);
		else if (i == 3)
			cylinder.r = parse_other(tab[i], cylinder.r, 2) / 2;
		else if (i == 4)
			cylinder.h = parse_other(tab[i], cylinder.h, 2);
		else if (i == 5)
			cylinder.color = parse_color(tab[i], cylinder.color);
	}
	free_tab(tab);
	return (cylinder);
}