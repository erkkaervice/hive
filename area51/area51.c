/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area51.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:14:41 by eala-lah          #+#    #+#             */
/*   Updated: 2024/04/23 17:46:42 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//testicals[1][2]

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*dest_ptr;

	dest_ptr = dest;
	if (!dest && !src)
		return (dest);
	if (dest == src)
		return (dest);
	if (dest > src)
	{
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	}
	else
	{
		while (n--)
			*(char *)dest++ = *(char *)src++;
	}
	return (dest_ptr);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For memcmp function

// Prototype of ft_memmove function
void *ft_memmove(void *dest, const void *src, size_t n);

int main() {
    // Example 1: No overlap
    char src1[] = "Hello, world!";
    char dest1[20]; // Make sure the destination buffer is large enough to hold the source data
    ft_memmove(dest1, src1, strlen(src1) + 1); // Copy src1 to dest1
    printf("Example 1 (No overlap):\n");
    printf("Source: %s\n", src1);
    printf("Destination: %s\n\n", dest1);

    // Example 2: Overlap (Destination starts before Source)
    char src2[] = "Destination is overlapped by Source";
    char dest2[] = "Destination is overlapped by Source";
    ft_memmove(dest2 + 10, src2, strlen(src2) + 1); // Copy src2 to dest2, with overlap
    printf("Example 2 (Overlap - Destination starts before Source):\n");
    printf("Source: %s\n", src2);
    printf("Destination: %s\n\n", dest2);

    // Example 3: Overlap (Destination starts after Source)
    char src3[] = "Source is overlapped by Destination";
    char dest3[] = "Source is overlapped by Destination";
    ft_memmove(dest3, src3 + 10, strlen(src3) + 1); // Copy src3 to dest3, with overlap
    printf("Example 3 (Overlap - Destination starts after Source):\n");
    printf("Source: %s\n", src3);
    printf("Destination: %s\n\n", dest3);

    // Example 4: Overlap (Identical Source and Destination)
    char dest4[] = "Identical Source and Destination";
    ft_memmove(dest4, dest4 + 10, strlen(dest4) + 1); // Copy dest4 to itself, with overlap
    printf("Example 4 (Overlap - Identical Source and Destination):\n");
    printf("Source/Destination: %s\n", dest4);

    return 0;
}
