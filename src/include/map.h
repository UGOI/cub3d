/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:35:03 by sdukic            #+#    #+#             */
/*   Updated: 2023/02/12 21:18:10 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "my_math.h"
# include "player.h"
# include "map.h"
# include "MLX42.h"
# include "./parser.h"

typedef struct s_texture
{
	char			**texture;
	t_int_vector	dimensions;
}				t_texture;

typedef struct s_map
{
	char			**raw_map;
	t_int_vector	raw_map_dimensions;

	char			**mini_map;
	float			minimap_scaling_factor;
	t_int_vector	minimap_dimensions;

	t_texture		south_texture;
	t_texture		north_texture;
	t_texture		east_texture;
	t_texture		west_texture;
	int				floor_color;
	int				ceiling_color;
}				t_map;

char			*get_next_line(int fd);
char			**scale_map(char **map, int scaling_factor);
float			get_fscaling_factor(t_int_vector raw_dimensions,
					t_int_vector scaled_dimensions);
char			**init_texture(char *map_file);
t_int_vector	get_map_dimesnions(char **map);
void			map_constructor(t_map *map, t_map_parsing *map_parsing);
int				draw_player(mlx_image_t *map_img, t_player *player, t_map *map);
int				draw_map(mlx_image_t *map_img, t_map *map, t_player *player);
char			**init_texture(char *texture_path);
void			map_destructor(t_map *map);
t_int_vector	get_texture_dim_in_file(char *map_file);
char			**allocate_map_memory(t_int_vector dim);
void			read_texture_from_file(char **map, int fd);
char			**init_texture(char *map_file);
char			**remove_newlines(char **map);
void			parser_cleaner(t_map_parsing *parser);
#endif
