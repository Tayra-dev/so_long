/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-roi <hle-roi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:31:28 by hle-roi           #+#    #+#             */
/*   Updated: 2024/02/05 09:50:43 by hle-roi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_error(char *str, char *str2)
{
	free(str);
	if (!str2)
		return (NULL);
	free(str2);
	return (NULL);
}

static char	*get_line(char *buff)
{
	char	*str;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = 0;
	while (i >= 0)
	{
		str[i] = buff[i];
		i--;
	}
	return (str);
}

char	*get_next_buff(char *buff)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
		return (ft_error(buff, 0));
	result = malloc((ft_strlen(buff) -i + 1) * sizeof(char));
	if (!result)
		return (ft_error(buff, 0));
	i++;
	while (buff[i])
		result[j++] = buff[i++];
	result[j] = 0;
	free(buff);
	return (result);
}

char	*ft_get_buff(int fd, char *buff)
{
	int		status;
	char	*read_buff;
	char	*tmp;

	status = 1;
	read_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buff)
		return (ft_error(buff, 0));
	while (status)
	{
		status = read(fd, read_buff, BUFFER_SIZE);
		if (status == -1)
			return (ft_error(buff, read_buff));
		read_buff[status] = 0;
		tmp = ft_strjoin(buff, read_buff);
		free(buff);
		buff = tmp;
		if (!buff)
			return (ft_error(read_buff, 0));
		if (ft_strchr(read_buff, '\n'))
			break ;
	}
	free(read_buff);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char		*buff;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff)
		buff = ft_calloc(1, sizeof(char));
	if (!buff)
		return (NULL);
	buff = ft_get_buff(fd, buff);
	if (!buff)
		return (NULL);
	line = get_line(buff);
	if (!line)
	{
		free(buff);
		buff = 0;
		return (NULL);
	}
	buff = get_next_buff(buff);
	return (line);
}

// # include <stdio.h>

// int	main(void)
// {
// 	int	fd;
// 	int	i;
// 	char *str;

// 	i = 0;
// 	fd = open("test.txt", O_RDONLY);
// 	while (i < 10)
// 	{
// 		str = get_next_line(fd);
// 		printf("%i: %s", i, str);
// 		free(str);
// 		i++;
// 	}
// 	close(fd);
// 	system("leaks a.out");
// }
