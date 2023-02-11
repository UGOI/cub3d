#include <stdio.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../../../gnl/get_next_line.h"
#include "../../../libft/libft.h"

#include "parser.h"

int	get_line_after_wall(char **lines)
{
	int	i;
	int	j;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			// printf("%c\n",lines[i][j]);
			if (lines[i][j] == '0')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	is_first_line_wall(char *tmp_map)
{
	int	i;
	int	in_map;

	i = 0;
	in_map = 0;
	while (tmp_map[i] && !in_map)
	{
		if (tmp_map[i] != '\n')
		{
			in_map = 1;
			while (in_map)
			{
				if (tmp_map[i] != '1' && tmp_map[i] != ' ' && tmp_map[i] != '\n')
				{
					printf("Error\nTop wall not valid\n");
					return (FALSE);
				}
				if (tmp_map[i] == '\n' || tmp_map[i] == '\0')
					break ;
				i++;
			}
		}
		i++;
	}
	return (TRUE);
}

int	is_top_wall_valid(char *tmp_map)
{
	int		line_after_wall;
	int		end_diff;
	char	*space_end;
	char	*space_start;
	char	*wall_start;
	char	**split;
	int		map_line_count;

	if (is_first_line_wall(tmp_map) != TRUE)
		return (FALSE);
	split = ft_wall_split(tmp_map, '\n');
	if (!split)
		return (FALSE);
	if (!split[0] || !split[1])
		return (FALSE);
	line_after_wall = get_line_after_wall(split);
	if (line_after_wall == -1)
	{
		ft_free(split);
		return (FALSE);
	}
	printf("Num is :%d:\n", split_count(split));
	map_line_count = split_count(split);
	int tmp = line_after_wall;
	while (line_after_wall < map_line_count)
	{
		space_end = ft_strrchr(split[line_after_wall], '0');
		space_start = ft_strchr(split[line_after_wall], '0');
		wall_start = ft_strchr(split[line_after_wall - 1], '1');
		if (!space_end || !space_start || !wall_start)
			break ;
		end_diff = ft_strlen(split[line_after_wall])  - ft_strlen(space_end);
		printf("< %s : %s >\n", split[line_after_wall - 1], split[line_after_wall]);
		if ((int) ft_strlen(split[line_after_wall - 1]) - 1 < end_diff || \
	ft_strlen(split[line_after_wall - 1]) - ft_strlen(wall_start) > \
	ft_strlen(split[line_after_wall]) - ft_strlen(space_start))
	{
		printf("line of error:%d:\n", line_after_wall);
		return (FALSE);
	}
		line_after_wall++;
	}
	ft_free(split);
	return (TRUE);
}