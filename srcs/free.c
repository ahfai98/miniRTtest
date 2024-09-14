/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:13:50 by jyap              #+#    #+#             */
/*   Updated: 2024/09/14 18:34:50 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	free_double_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}


void	free_obj_list(t_scene *sc)
{
	t_obj	*obj;

	while (sc->obj)
	{
		obj = sc->obj->next;
		free(obj->obj_ptr);
		free(sc->obj);
		sc->obj = obj;
	}
}

void free_scene(t_scene **sc)
{
	if (sc == NULL || *sc == NULL)
		return;
	if ((*sc)->obj != NULL)
		free_obj_list(*sc);
	free(*sc);
	*sc = NULL;
}

void	free_all(t_mlxs *mlxs)
{
	if (mlxs)
	{
		if (mlxs->img.img)  // Free image using MiniLibX functions
			mlx_destroy_image(mlxs->mlx, mlxs->img.img);
		if (mlxs->mlx_win)  // Destroy the window
			mlx_destroy_window(mlxs->mlx, mlxs->mlx_win);
		if (mlxs->mlx)  // Destroy the display connection (Linux only)
			mlx_destroy_display(mlxs->mlx);
		free_scene(mlxs->sc);
		free(mlxs);  // Free the mlx structure
	}
}
