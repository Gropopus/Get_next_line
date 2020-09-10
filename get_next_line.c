/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:54:15 by thsembel          #+#    #+#             */
/*   Updated: 2020/09/10 15:43:33 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_cat_next_line(char *str, char *buff)
{
	int		i;
	int		j;
	int		len;
	char	*new_line;

	len = ft_strlen_null(str) + ft_strlen_null(buff);
	i = 0;
	j = 0;
	if ((new_line = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	if (str)
	{
		new_line = ft_strcpy(new_line, str);
		i = ft_strlen_null(str);
	}
	while (buff[j])
	{
		new_line[i + j] = buff[j];
		j++;
	}
	new_line[i + j] = '\0';
	free(str);
	return (new_line);
}

static char		*ft_new_line(char *str, int *end)
{
	int		len;
	int		i;
	char	*line;

	len = 0;
	i = 0;
	len = ft_check_c(str, '\n') - 1;
	if (len == 0)
		len = ft_check_c(str, '\0') - 1;
	if (len == 0)
		*end = (-1);
	if ((line = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char		*ft_other_line(char *str)
{
	int		total_len;
	int		f_line_len;
	int		i;
	char	*new_str;

	i = 0;
	f_line_len = ft_check_c(str, '\n');
	total_len = ft_strlen_null(str) - f_line_len;
	if ((new_str = malloc(sizeof(char) * (total_len + 1))) == NULL)
		return (NULL);
	new_str[total_len] = '\0';
	while (i < total_len)
	{
		new_str[i] = str[f_line_len + i];
		i++;
	}
	free(str);
	return (new_str);
}

static int		ft_end(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	int			ret;
	int			end;
	char		buff[BUFFER_SIZE + 1];
	char		*new_line;
	static char *str = NULL;

	end = 0;
	if (fd < 0 || line == NULL || BUFFER_SIZE == 0 || (read(fd, buff, 0) < 0))
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((str = ft_cat_next_line(str, buff)) == NULL)
			return (ft_free_and_exit(&str, NULL));
		if (ft_check_c(buff, '\n') != 0)
			break ;
	}
	if ((new_line = ft_new_line(str, &end)) == NULL)
		return (ft_free_and_exit(&str, NULL));
	else if ((str = ft_other_line(str)) == NULL)
		return (ft_free_and_exit(&str, &new_line));
	*line = new_line;
	if (end == -1)
		ft_end(&str);
	return (1);
}
