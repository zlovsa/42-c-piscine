/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 11:16:59 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/21 11:17:01 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int		get_fd(int argc, char *argv[])
{
	int fd;

	if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
		return (-1);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Cannot read file.\n", 18);
		return (-1);
	}
	return (fd);
}

ssize_t	ft_read(int fd, char *buf)
{
	ssize_t rdc;

	rdc = read(fd, buf, 1024);
	if (rdc < 0)
		write(2, "Cannot read file.\n", 18);
	return (rdc);
}

int		main(int argc, char *argv[])
{
	int		fd;
	char	buf[1024];
	ssize_t	rdc;

	fd = get_fd(argc, argv);
	if (fd > -1)
	{
		rdc = ft_read(fd, buf);
		while (rdc > 0)
		{
			write(1, &buf, rdc);
			rdc = ft_read(fd, buf);
		}
		close(fd);
		return (0);
	}
	return (1);
}
