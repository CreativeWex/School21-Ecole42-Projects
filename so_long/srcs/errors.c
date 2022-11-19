/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnidorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:11:49 by jnidorin          #+#    #+#             */
/*   Updated: 2022/04/15 18:11:56 by jnidorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(const char *text)
{
	ft_putstr_fd(text, 1);
	ft_putstr_fd("\n", 1);
	exit(EXIT_FAILURE);
}

void	ft_check_enemy(t_game *game)
{
	if ((game->map[game->pos_y][game->pos_x] == 'T')
			|| (game->map[game->pos_y][game->pos_x] == 'X'))
		ft_win(game, 0);
}

void	ft_win(t_game *game, int flag)
{
	int	iw;
	int	ih;

	game->wall = mlx_xpm_file_to_image(game->mlx,
			"./img/wall.xpm", &iw, &ih);
	ft_put_images_to_window(game, 0, 0);
	if (flag == 1)
	{
		game->winner = 1;
		ft_error("You Win!!!\n");
	}
	else
	{
		game->winner = -1;
		ft_error("Game Over!\n");
	}
}
