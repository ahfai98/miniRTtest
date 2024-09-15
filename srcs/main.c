/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:07:00 by jyap              #+#    #+#             */
/*   Updated: 2024/09/15 14:40:36 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	main(int ac, char **av)
{
	t_mlxs	*mlxs;

	(void) av;
	if (ac != 2)
	{
		print_err("Invalid Arguments.\n", NULL);
		print_err_exit("./miniRT <file.rt>\n", NULL, NULL);
	}
	mlxs = ft_calloc(sizeof(t_mlxs), 1);
	if (mlxs == NULL)
		print_err_exit("Malloc mlxs failed.\n", NULL, NULL);
	parse(av[1], mlxs);
	if (mlxs->sc->obj == NULL)
		print_err_exit("No objects found.\n", &mlxs, NULL);
	if (mlxs->sc->cam.i != 1)
		print_err_exit("No camera found.\n", &mlxs, NULL);
	//make_window(mlxs);
	//free_all(mlxs);
	return (0);
}