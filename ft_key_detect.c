/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_detect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:29:51 by agianico          #+#    #+#             */
/*   Updated: 2020/03/10 12:48:19 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_f(t_cub *cub)
{
	if (cub->f == 0)
		cub->f = 1;
	else
		cub->f = 0;
}

int		key_pressed(int key, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (key == 0)
		cub->a = 1;
	if (key == 1)
		cub->s = 1;
	if (key == 2)
		cub->d = 1;
	if (key == 13)
		cub->w = 1;
	if (key == 124)
		cub->right = 1;
	if (key == 123)
		cub->left = 1;
	if (key == 53)
		ft_exit_hook(cub);
	if (key == 8)
		cub->c = 1;
	if (key == 3)
		key_f(cub);
	return (0);
}

int		key_released(int key, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (key == 0)
		cub->a = 0;
	if (key == 1)
		cub->s = 0;
	if (key == 2)
		cub->d = 0;
	if (key == 13)
		cub->w = 0;
	if (key == 124)
		cub->right = 0;
	if (key == 123)
		cub->left = 0;
	return (0);
}
