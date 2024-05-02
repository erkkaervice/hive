/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:44:54 by eala-lah          #+#    #+#             */
/*   Updated: 2024/05/02 14:48:38 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
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

void	test_lstadd_front(void)
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
        return; // Handle error appropriately
    }

    ft_lstclear(&list, &free);
    if (list)
        printf("Test ft_lstclear: [\033[0;31mKO\033[0m]\n");
    else
        printf("Test ft_lstclear: [\033[0;32mOK\033[0m]\n");
}

void	delete_int(void *content) 
{
    int *ptr = (int *)content;
    free(ptr);
}

void	test_ft_lstdelone() 
{
    t_list *list = NULL;

    int *data = malloc(sizeof(int));
    *data = 42;
    ft_lstadd_front(&list, ft_lstnew(data));

    if (list != NULL) {
        ft_lstdelone(list, delete_int);
        list = NULL;

        if (list == NULL) {
            printf("Test ft_lstdelone: [\033[0;32mOK\033[0m]\n");
        } else {
            printf("Test ft_lstdelone: [\033[0;31mKO\033[0m]\n");
        }
    } else {
        printf("Test ft_lstdelone: [\033[0;31mKO\033[0m]\n");
    }
}

void	test_ft_lstiter(void)
{
    t_list *list = ft_lstnew(ft_strdup("hello"));

    t_list *curr = list;
    while (curr)
    {
        char *content = curr->content;
        char *ptr = content;
        while (*ptr)
        {
            *ptr = (*ptr >= 'a' && *ptr <= 'z') ? *ptr - 32 : *ptr;
            ptr++;
        }
        curr = curr->next;
    }

    if (strcmp(list->content, "HELLO") != 0)
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
    t_list *list = ft_lstnew("Hello");

    t_list *curr = list;
    t_list *new = NULL;
    t_list *prev = NULL;

    while (curr)
    {
        t_list *node = ft_lstnew(curr->content);
        if (!node)
        {
            ft_lstclear(&new, free);
            return;
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

void	test_ft_putchar_fd(void)
{
	int	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	ft_putchar_fd('a', fd);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	char	c;
	read(fd, &c, 1);
	if (c != 'a')
		printf("Test ft_putchar_fd: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_putchar_fd: [\033[0;32mOK\033[0m]\n");
	close(fd);
}

void	test_ft_putendl_fd(void)
{
	int	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd("Hello", fd);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	char	str[50];
	read(fd, str, 6);
	if (strcmp(str, "Hello\n") == 0)
		printf("Test ft_putendl_fd: [\033[0;32mOK\033[0m]\n");
	else
		printf("Test ft_putendl_fd: [\033[0;31mKO\033[0m]\n");
	close(fd);
}

void    test_ft_putnbr_fd(void)
{
    int     fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    ft_putnbr_fd(42, fd);
    close(fd);

    fd = open("test.txt", O_RDONLY);
    char    str[50];

    read(fd, str, 2);
    str[2] = '\0';

    if (strcmp(str, "42") == 0)
        printf("Test ft_putnbr_fd: [\033[0;32mOK\033[0m]\n");
    else
        printf("Test ft_putnbr_fd: [\033[0;31mKO\033[0m]\n");
    
    close(fd);
}


void	test_ft_putstr_fd(void)
{
	int	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd("Hello", fd);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	char	str[50];
	read(fd, str, 5);
	str[5] = '\0';
	if (strcmp(str, "Hello") == 0)
		printf("Test ft_putstr_fd: [\033[0;32mOK\033[0m]\n");
	else
		printf("Test ft_putstr_fd: [\033[0;31mKO\033[0m]\n");
	close(fd);
}

void	test_ft_atoi(void)
{
	if (ft_atoi("42") != 42 || ft_atoi("-42") != -42 || ft_atoi("42a") != 42)
		printf("Test ft_atoi: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_atoi: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_itoa(void)
{
	if (strcmp(ft_itoa(42), "42") || strcmp(ft_itoa(-42), "-42"))
		printf("Test ft_itoa: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_itoa: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_split(void)
{
	char	**array;

	array = ft_split("Hello World", ' ');
	if (strcmp(array[0], "Hello") || strcmp(array[1], "World"))
		printf("Test ft_split: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_split: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_strchr(void)
{
	char	str[50];

	ft_memset(str, 'a', 50);
	if (strcmp(ft_strchr(str, 'a'), str))
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
}

void    test_ft_striteri(void)
{
    char    str[50];

    strcpy(str, "Hello");

    unsigned int i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        i++;
    }

    if (strcmp(str, "HELLO") != 0)
        printf("Test ft_striteri: [\033[0;31mKO\033[0m]\n");
    else
        printf("Test ft_striteri: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_strjoin(void)
{
	char	*str;

	str = ft_strjoin("Hello", "World");
	if (strcmp(str, "HelloWorld"))
		printf("Test ft_strjoin: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_strjoin: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_strlcat(void)
{
	char	dst[15] = "Hello";
	char	src[] = " World!";
	size_t	expected_len = strlen(dst) + strlen(src);
	size_t	result = ft_strlcat(dst, src, sizeof(dst));
	if (result == expected_len)
		printf("Test ft_strlcat: [\033[0;32mOK\033[0m]\n");
	else
		printf("Test ft_strlcat: [\033[0;31mKO\033[0m]\n");
}

void	test_ft_strlcpy(void)
{
	char	str1[50];
	char	str2[50];

	ft_strlcpy(str1, "Hello", 50);
	ft_strlcpy(str2, "Hello", 50);
	if (strcmp(str1, str2))
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
    const char *input = "Hello";
    const char *expected = "Hello";

    int i = 0;
    while (input[i] != '\0' && expected[i] != '\0')
    {
        if (input[i] != expected[i])
        {
            printf("Test ft_strmapi: [\033[0;31mKO\033[0m]\n");
            return;
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
	if (ft_strncmp("Hello", "Hello", 5) == 0 && ft_strncmp("Hello", "Hell", 5) != 0)
		printf("Test ft_strncmp: [\033[0;32mOK\033[0m]\n");
	else
		printf("Test ft_strncmp: [\033[0;31mKO\033[0m]\n");
}

void	test_ft_strnstr(void)
{
	if (strcmp(ft_strnstr("Hello", "Hello", 5), "Hello") || strcmp(ft_strnstr("Hello", "Hell", 5), "Hello"))
		printf("Test ft_strnstr: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_strnstr: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_strrchr(void)
{
	char	str[50];

	ft_memset(str, 'a', 50);
	if (strcmp(ft_strrchr(str, 'a'), str + 49))
		printf("Test ft_strrchr: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_strrchr: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_strtrim(void)
{
	if (strcmp(ft_strtrim("Hello", "Hello"), ""))
		printf("Test ft_strtrim: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_strtrim: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_substr(void)
{
	if (strcmp(ft_substr("Hello", 0, 5), "Hello") || strcmp(ft_substr("Hello", 0, 3), "Hel"))
		printf("Test ft_substr: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_substr: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_tolower(void)
{
	if (ft_tolower('A') != 'a' || ft_tolower('a') != 'a' || ft_tolower('1') != '1')
		printf("Test ft_tolower: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_tolower: [\033[0;32mOK\033[0m]\n");
}

void	test_ft_toupper(void)
{
	if (ft_toupper('A') != 'A' || ft_toupper('a') != 'A' || ft_toupper('1') != '1')
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
	test_lstadd_front();
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
	test_ft_atoi();
	test_ft_itoa();
	test_ft_split();
	test_ft_strchr();
	test_ft_strdup();
	test_ft_striteri();
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