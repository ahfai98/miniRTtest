/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:09:42 by jyap              #+#    #+#             */
/*   Updated: 2024/09/14 18:15:39 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	print_err(char *msg, void *ptr)
{
	ft_putstr_fd(msg, 2);
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	print_err_exit(char *msg, void *ptr, int exit_n)
{
	ft_putstr_fd(msg, 2);
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
	exit (exit_n);
}

