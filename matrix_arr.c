#include "so_long.h"

int	ft_get_height(char **argv)
{
	char	*line;
	int		count;
	int		fd;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nArgument is invalid\n", 1);
		exit(1);
	}
	while (get_next_line(fd, &line))
	{
		count++;
		free(line);
	}
	if (ft_strncmp(line, "", ft_strlen(line)))
		count++;
	free(line);
	close(fd);
	return (count);
}

int	ft_get_width(char **argv)
{
	char	buf;
	int		count;
	int		fd;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nArgument is invalid\n", 1);
		exit(1);
	}
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			break ;
		count++;
	}
	close(fd);
	return (count);
}

void	fill_matrix(char **argv, t_vars *var)
{
	int		fd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nArgument is invalid\n", 1);
		exit(1);
	}
	while (read(fd, &(var->buf), 1))
	{
		if (var->buf == '\n')
		{
			j = 0;
			i++;
			continue ;
		}
		var->arr[i][j] = var->buf;
		j++;
	}
	var->arr[i][j] = '\0';
	close(fd);
}
