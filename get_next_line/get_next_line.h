/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabe <jabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:28:03 by jabe              #+#    #+#             */
/*   Updated: 2025/05/29 17:54:11 by jabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read_to_stock(int fd, char *stock);
char	*ft_get_line(char *stock);
char	*ft_new_stock(char *stock);
char	*ft_strchr(char	*s, int c);
size_t	ft_strlen(char	*s);
char	*ft_strjoin(char *stock, char *buffer);
char	*ft_strjoin_support(char *s1, char *s2);
char	*ft_allocate_string(void);

#endif