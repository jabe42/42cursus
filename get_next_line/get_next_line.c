/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabe <jabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:03:08 by jabe              #+#    #+#             */
/*   Updated: 2025/05/30 15:06:03 by jabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_stock(char *stock)
{
	int		i;
	int		j;
	char	*str;

	if (!stock)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stock[i])
		str[j++] = stock[i++];
	str[j] = '\0';
	free(stock);
	return (str);
}

char	*ft_get_line(char *stock)
{
	int		i;
	char	*str;

	i = 0;
	if (!stock || stock[0] == '\0')
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		str[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
	{
		str[i] = stock[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_read_to_stock(int fd, char *stock)
{
	char	*buffer;
	int		word_count;

	word_count = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stock, '\n') && word_count != 0)
	{
		word_count = read(fd, buffer, BUFFER_SIZE);
		if (word_count == -1)
		{
			free(buffer);
			free(stock);
			return (NULL);
		}
		buffer[word_count] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	free (buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stock = ft_read_to_stock(fd, stock);
	if (!stock)
		return (NULL);
	line = ft_get_line(stock);
	stock = ft_new_stock(stock);
	return (line);
}
