/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:33:52 by eala-lah          #+#    #+#             */
/*   Updated: 2024/06/06 12:07:22 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*sto = {0};
	char		*line;

	if (fd < 0)
	{
		return (NULL);
	}
	if ((sto && !ft_gnlchr(sto, '\n')) || !sto)
	{
		sto = ft_readbuf (fd, sto);
	}
	if (!sto)
	{
		return (NULL);
	}
	line = ft_newline(sto);
	if (!line)
	{
		return (ft_free(&sto));
	}
	sto = ft_cleanup(sto);
	return (line);
}
