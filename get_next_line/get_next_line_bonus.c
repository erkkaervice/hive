/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:33:52 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/06 12:08:25 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_cleanup(char *sto)
{
	char	*new;
	char	*ptr;
	int		len;

	ptr = ft_gnlchr(sto, '\n');
	if (!ptr)
	{
		new = NULL;
		return (ft_free(&sto));
	}
	else
	{
		len = (ptr - sto) + 1;
	}
	if (!sto[len])
	{
		return (ft_free(&sto));
	}
	new = ft_substr(sto, len, ft_strlen(sto) - len);
	ft_free(&sto);
	if (!new)
	{
		return (NULL);
	}
	return (new);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_newline(char *sto)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_gnlchr(sto, '\n');
	len = (ptr - sto) + 1;
	line = ft_substr(sto, 0, len);
	if (!line)
	{
		return (NULL);
	}
	return (line);
}

char	*ft_readbuf(int fd, char *sto)
{
	int		i;
	char	*buf;

	i = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		return (ft_free(&sto));
	}
	buf[0] = '\0';
	while (i > 0 && !ft_gnlchr(buf, '\n'))
	{
		i = read (fd, buf, BUFFER_SIZE);
		if (i > 0)
		{
			buf[i] = '\0';
			sto = ft_gnljoin(sto, buf);
		}
	}
	free(buf);
	if (i == -1)
	{
		return (ft_free(&sto));
	}
	return (sto);
}

char	*get_next_line(int fd)
{
	static char	*sto[OPEN_MAX];
	char		*line;

	if (fd < 0)
	{
		return (NULL);
	}
	if ((sto[fd] && !ft_gnlchr(sto[fd], '\n')) || !sto[fd])
	{
		sto[fd] = ft_readbuf (fd, sto[fd]);
	}
	if (!sto[fd])
	{
		return (NULL);
	}
	line = ft_newline(sto[fd]);
	if (!line)
	{
		return (ft_free(&sto[fd]));
	}
	sto[fd] = ft_cleanup(sto[fd]);
	return (line);
}
