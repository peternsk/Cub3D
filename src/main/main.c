/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:42:07 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/17 16:38:36 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{
	t_mini_map	*game;
	t_load_pos	var;

	var.i = 0;
	var.j = 0;
	var.x = 0;
	var.y = 0;
	int			fd;

	if (ac == 2)
	{
		printf("=========\n");
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (EXIT_FAILURE);
		game = ft_mini(av[1]);
		ft_map_to_arr(game, fd);
		game->width = max_len(game);
		game->mlx = mlx_init(game->width * 16, game->height * 16, "CUBE 3D", true);
		if (!game->mlx)
		{
			puts(mlx_strerror(mlx_errno));
			return (EXIT_FAILURE);
		}
		ft_arr_texture(game);
		ft_texture_to_image(game);
		ft_load_png(game, &var);
		mlx_key_hook(game->mlx, &ft_player_moves, game);
		mlx_loop(game->mlx);
		return (EXIT_SUCCESS);
	}
}

