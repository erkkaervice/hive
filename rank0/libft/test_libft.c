/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:21:47 by eala-lah          #+#    #+#             */
/*   Updated: 2024/04/26 19:31:36 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	test_ft_atoi(void)
{
	if (ft_atoi("42") != 42 || ft_atoi("-42") != -42 || ft_atoi("42a") != 42)
		printf("Test ft_atoi: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_atoi: [\033[0;32mOK\033[0m]\n");
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
	if (ft_isascii('a') == 1 || ft_isascii(1) == 1 || ft_isascii(128) == 0)
		printf("Test ft_isascii: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_isascii: [\033[0;32mOK\033[0m]\n");
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
	if (ft_isprint('a') == 1 || ft_isprint(1) == 1 || ft_isprint(128) == 0)
		printf("Test ft_isprint: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_isprint: [\033[0;32mOK\033[0m]\n");
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

void	test_ft_strlcat(void)
{
	char	str1[50];
	char	str2[50];

	ft_strlcat(str1, "Hello", 50);
	ft_strlcat(str2, "Hello", 50);
	if (strcmp(str1, str2))
		printf("Test ft_strlcat: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_strlcat: [\033[0;32mOK\033[0m]\n");
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

void	test_ft_strncmp(void)
{
	if (ft_strncmp("Hello", "Hello", 5) != 0 || ft_strncmp("Hello", "Hell", 5) != 0)
		printf("Test ft_strncmp: [\033[0;31mKO\033[0m]\n");
	else
		printf("Test ft_strncmp: [\033[0;32mOK\033[0m]\n");
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

