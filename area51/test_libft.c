/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:44:54 by eala-lah          #+#    #+#             */
/*   Updated: 2024/05/10 13:43:09 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <strings.h>
#include "libft.h"

void	test_ft_isalnum(void)
{
	if (ft_isalnum('a') == 0 || ft_isalnum('1') == 0 || ft_isalnum(' ') == 1)
		printf("Test ft_isalnum: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_isalnum: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_isalpha(void)
{
	if (ft_isalpha('a') == 0 || ft_isalpha('1') == 1 || ft_isalpha(' ') == 1)
		printf("Test ft_isalpha: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_isalpha: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_isascii(void)
{
	if (ft_isascii('a') == 1 && ft_isascii(1) == 1 && ft_isascii(128) == 0)
		printf("Test ft_isascii: [\033[0;32mOK\033[0m]\n");
	else
		printf("Test ft_isascii: [\033[0;31mKO\033[0m]\n");
}

void	test_ft_isdigit(void)
{
	if (ft_isdigit('a') == 1 || ft_isdigit('1') == 0 || ft_isdigit(' ') == 1)
		printf("Test ft_isdigit: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_isdigit: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_isprint(void)
{
	if (ft_isprint('a') == 1 && ft_isprint(1) == 0 && ft_isprint(128) == 0)
		printf("Test ft_isprint: [\033[0;32mOK\033[0m]\n");
	else
		printf("Test ft_isprint: [\033[0;31mKO\033[0m]\n");
}

void	test_ft_lstadd_back(void)
{
	t_list	*list;
	t_list	*new;

	list = ft_lstnew("Hello");
	new = ft_lstnew("World");
	ft_lstadd_back(&list, new);
	if (strcmp(list->next->content, "World"))
		printf("Test ft_lstadd_back: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_lstadd_back: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_lstadd_front(void)
{
	t_list	*list;
	t_list	*new;

	list = ft_lstnew("Hello");
	new = ft_lstnew("World");
	ft_lstadd_front(&list, new);
	if (strcmp(list->content, "World"))
		printf("Test ft_lstadd_front: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_lstadd_front: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_lstclear(void)
{
	t_list	*list;

	list = ft_lstnew(ft_strdup("Hello"));
	if (!list)
	{
		printf("Memory allocation error\n");
		return ;
	}

	ft_lstclear(&list, &free);
	if (list)
		printf("Test ft_lstclear: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_lstclear: [\033[0;32mOK\033[0m]\n");
}

void	delete_int(void *content)
{
	int	*ptr;

	ptr = (int *)content;
	free(ptr);
}

void	test_ft_lstdelone(void)
{
	t_list	*list;
	int		*data;

	list = NULL;
	data = malloc(sizeof(int));
	*data = 42;
	ft_lstadd_front(&list, ft_lstnew(data));
	if (list != NULL)
	{
		ft_lstdelone(list, delete_int);
		list = NULL;

		if (list == NULL)
		{
			printf("Test ft_lstdelone: [\033[0;32mOK\033[0m]\n");
		}
		else
		{
			printf("Test ft_lstdelone: [\033[0;31mKO\033[0m]\n");
		}
	}
	else
	{
		printf("Test ft_lstdelone: [\033[0;31mKO\033[0m]\n");
	}
}

void	ft_lstiter_test(void *content)
{
	char	*str;

	str = ft_strdup((char *)content);
	if (!str)
	{
		return ;
	}
	str[0] = 'H';
	content = str;
}

void	test_ft_lstiter(void)
{
	t_list	*list;

	list = ft_lstnew("Hello");
	ft_lstiter(list, &ft_lstiter_test);
	if (strcmp(list->content, "Hello"))
		printf("Test ft_lstiter: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_lstiter: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_lstlast(void)
{
	t_list	*list;
	t_list	*last;

	list = ft_lstnew("Hello");
	last = ft_lstlast(list);
	if (strcmp(last->content, "Hello"))
		printf("Test ft_lstlast: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_lstlast: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_lstmap(void)
{
	t_list	*list;
	t_list	*curr;
	t_list	*new;
	t_list	*prev;
	t_list	*node;

	list = ft_lstnew("Hello");
	curr = list;
	new = NULL;
	prev = NULL;
	while (curr)
	{
		node = ft_lstnew(curr->content);
		if (!node)
		{
			ft_lstclear(&new, free);
			return ;
		}
		if (!new)
			new = node;
		else
			prev->next = node;
		prev = node;
		curr = curr->next;
	}
	if (strcmp(new->content, "Hello") != 0)
		printf("Test ft_lstmap: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_lstmap: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_lstnew(void)
{
	t_list	*list;

	list = ft_lstnew("Hello");
	if (strcmp(list->content, "Hello"))
		printf("Test ft_lstnew: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_lstnew: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_lstsize(void)
{
	t_list	*list;

	list = ft_lstnew("Hello");
	if (ft_lstsize(list) != 1)
		printf("Test ft_lstsize: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_lstsize: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_bzero(void)
{
	char	str[50];

	ft_bzero(str, 50);
	if (strcmp(str, "\0"))
		printf("Test ft_bzero: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_bzero: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_calloc(void)
{
	char	*str;

	str = ft_calloc(50, sizeof(char));
	if (strcmp(str, "\0"))
		printf("Test ft_calloc: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_calloc: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_memchr(void)
{
	char	str[50];

	ft_memset(str, 'a', 50);
	if (strcmp(ft_memchr(str, 'a', 50), str))
		printf("Test ft_memchr: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_memchr: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_memcmp(void)
{
	char	str1[50];
	char	str2[50];

	ft_memset(str1, 'a', 50);
	ft_memset(str2, 'a', 50);
	if (ft_memcmp(str1, str2, 50) != 0)
		printf("Test ft_memcmp: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_memcmp: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_memcpy(void)
{
	char	str1[50];
	char	str2[50];

	ft_memset(str1, 'a', 50);
	ft_memcpy(str2, str1, 50);
	if (strcmp(str1, str2))
		printf("Test ft_memcpy: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_memcpy: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_memmove(void)
{
	char	str1[50];
	char	str2[50];

	ft_memset(str1, 'a', 50);
	ft_memmove(str2, str1, 50);
	if (strcmp(str1, str2))
		printf("Test ft_memmove: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_memmove: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_memset(void)
{
	char	str[50];

	ft_memset(str, 'a', 50);
	if (strcmp(str, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"))
		printf("Test ft_memset: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_memset: [\033[0;32mOK\033[0m]\n");
}

char *ft_readfile(const char *filename)
{
	int		fd;
	off_t	file_size;
	char	*buffer;
	ssize_t	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (NULL);
	}
	file_size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	buffer = (char *)malloc(file_size + 1);
	if (buffer == NULL)
	{
		perror("Error allocating memory");
		close(fd);
		return (NULL);
	}
	bytes_read = read(fd, buffer, file_size);
	if (bytes_read == -1)
	{
		perror("Error reading file");
		free(buffer);
		close(fd);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	close(fd);
	return (buffer);
}

void	test_ft_putchar_fd(void)
{
	int	fd;

	fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	ft_putchar_fd('a', fd);
	close(fd);
	if (strcmp(ft_readfile("test.txt"), "a"))
		printf("Test ft_putchar_fd: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_putchar_fd: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_putendl_fd(void)
{
	int	fd;

	fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd("Hello", fd);
	close(fd);
	if (strcmp(ft_readfile("test.txt"), "Hello\n"))
		printf("Test ft_putendl_fd: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_putendl_fd: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_putnbr_fd(void)
{
	int	fd;

	fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	ft_putnbr_fd(42, fd);
	close(fd);
	if (strcmp(ft_readfile("test.txt"), "42"))
		printf("Test ft_putnbr_fd: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_putnbr_fd: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_putstr_fd(void)
{
	int	fd;

	fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd("Hello", fd);
	close(fd);
	if (strcmp(ft_readfile("test.txt"), "Hello"))
		printf("Test ft_putstr_fd: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_putstr_fd: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_split(void)
{
	char	**tab;

	tab = ft_split("Hello World", ' ');
	if (strcmp(tab[0], "Hello") || strcmp(tab[1], "World") || tab[2] != NULL)
		printf("Test ft_split: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_split: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_strchr(void)
{
	char	*str;

	str = "Hello";
	if (ft_strchr(str, 'l') != strchr(str, 'l'))
		printf("Test ft_strchr: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_strchr: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_strdup(void)
{
	char	*str;

	str = ft_strdup("Hello");
	if (strcmp(str, "Hello"))
		printf("Test ft_strdup: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_strdup: [\033[0;32mOK\033[0m]\n");
	free(str);
}

void	test_ft_strjoin(void)
{
	char	*str;

	str = ft_strjoin("Hello ", "World");
	if (strcmp(str, "Hello World"))
		printf("Test ft_strjoin: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_strjoin: [\033[0;32mOK\033[0m]\n");
	free(str);
}

void	test_ft_strlcat(void)
{
	char	dst[50] = "Hello ";
	char	src[] = "World";
	size_t	ret;

	ret = ft_strlcat(dst, src, 50);
	if (strcmp(dst, "Hello World") || ret != 11)
		printf("Test ft_strlcat: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_strlcat: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_strlcpy(void)
{
	char	dst[50];
	char	src[] = "Hello";
	size_t	ret;

	ft_bzero(dst, 50);
	ret = ft_strlcpy(dst, src, 50);
	if (strcmp(dst, "Hello") || ret != 5)
		printf("Test ft_strlcpy: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_strlcpy: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_strlen(void)
{
	if (ft_strlen("Hello") != 5)
		printf("Test ft_strlen: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_strlen: [\033[0;32mOK\033[0m]\n");
}

void test_ft_strmapi(void)
{
	const char	*input;
	const char	*expected;
	int			i;

	input = "Hello";
	expected = "Hello";
	i = 0;
	while (input[i] != '\0' && expected[i] != '\0')
	{
		if (input[i] != expected[i])
		{
			printf("Test ft_strmapi: [\033[0;31mKO\033[0m]\n");
			return ;
		}
		i++;
	}

	if (input[i] == '\0' && expected[i] == '\0')
		printf("Test ft_strmapi: [\033[0;32mOK\033[0m]\n");
	else
		printf("Test ft_strmapi: [\033[0;31mKO\033[0m]\n");
}

void	test_ft_strncmp(void)
{
	if (ft_strncmp("Hello", "Hello", 5) == 0 
		&& ft_strncmp("Hello", "Hell", 5) != 0)
		printf("Test ft_strncmp: [\033[0;32mOK\033[0m]\n");
	else
		printf("Test ft_strncmp: [\033[0;31mKO\033[0m]\n");
}

void	test_ft_strnstr(void)
{
	char	*str;

	str = "Hello World";
	if (ft_strnstr(str, "World", 11) != str + 6 
		|| ft_strnstr(str, "World", 10) != NULL
		|| ft_strnstr(str, "World", 5) != NULL)
		printf("Test ft_strnstr: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_strnstr: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_strrchr(void)
{
	char	*str;

	str = "Hello World";
	if (ft_strrchr(str, 'l') != strrchr(str, 'l'))
		printf("Test ft_strrchr: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_strrchr: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_strtrim(void)
{
	char	*str;

	str = ft_strtrim("  Hello World  ", " ");
	if (strcmp(str, "Hello World"))
		printf("Test ft_strtrim: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_strtrim: [\033[0;32mOK\033[0m]\n");
	free(str);
}

void	test_ft_substr(void)
{
	char	*str;

	str = ft_substr("Hello World", 6, 5);
	if (strcmp(str, "World"))
		printf("Test ft_substr: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_substr: [\033[0;32mOK\033[0m]\n");
	free(str);
}

void	test_ft_tolower(void)
{
	if (ft_tolower('A') != 'a'
		|| ft_tolower('Z') != 'z'
		|| ft_tolower('a') != 'a')
		printf("Test ft_tolower: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_tolower: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_toupper(void)
{
	if (ft_toupper('a') != 'A'
		|| ft_toupper('z') != 'Z'
		|| ft_toupper('A') != 'A')
		printf("Test ft_toupper: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_toupper: [\033[0;32mOK\033[0m]\n");
}

int	main(void)
{
	test_ft_isalnum();
	test_ft_isalpha();
	test_ft_isascii();
	test_ft_isdigit();
	test_ft_isprint();
	test_ft_lstadd_back();
	test_ft_lstadd_front();
	test_ft_lstclear();
	test_ft_lstdelone();
	test_ft_lstiter();
	test_ft_lstlast();
	test_ft_lstmap();
	test_ft_lstnew();
	test_ft_lstsize();
	test_ft_bzero();
	test_ft_calloc();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_memcpy();
	test_ft_memmove();
	test_ft_memset();
	test_ft_putchar_fd();
	test_ft_putendl_fd();
	test_ft_putnbr_fd();
	test_ft_putstr_fd();
	test_ft_split();
	test_ft_strchr();
	test_ft_strdup();
	test_ft_strjoin();
	test_ft_strlcat();
	test_ft_strlcpy();
	test_ft_strlen();
	test_ft_strmapi();
	test_ft_strncmp();
	test_ft_strnstr();
	test_ft_strrchr();
	test_ft_strtrim();
	test_ft_substr();
	test_ft_tolower();
	test_ft_toupper();
	remove("test.txt");
	return (0);
}
