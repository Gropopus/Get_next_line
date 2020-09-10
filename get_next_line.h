/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:48:45 by thsembel          #+#    #+#             */
/*   Updated: 2020/09/10 15:27:40 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFFER_SIZE 4096

int		get_next_line(int fd, char **line);
int		ft_strlen_null(char *str);
int		ft_check_c(char *str, int c);
int		ft_free_and_exit(char **str, char **new_line);
char	*ft_strcpy(char *dest, char *src);

#endif
