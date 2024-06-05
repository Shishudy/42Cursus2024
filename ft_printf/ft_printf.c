/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:26:15 by rafasant          #+#    #+#             */
/*   Updated: 2024/06/05 16:45:17 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(va_list args, const char *s)
{
	unsigned long	i;

	if (*s == '%')
		return (write(1, "%%", 1));
	else if (*s == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*s == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*s == 'd' || *s == 'i')
		return (ft_itoa_base(va_arg(args, int), "0123456789"));
	else if (*s == 'u')
		return (ft_itoa_base(va_arg(args, unsigned int), "0123456789"));
	else if (*s == 'x')
		return (ft_itoa_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (*s == 'X')
		return (ft_itoa_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (*s == 'p')
	{
		i = va_arg(args, unsigned long int);
		if (i == 0)
			return (write(1, "(nil)", 5));
		return (ft_putstr("0x") + ft_putptr(i, "0123456789abcdef"));
	}
	return (write(1, "%%", 1) + write(1, &*s, 1));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		total;
	int		value;

	if (!s)
		return (-1);
	va_start(args, s);
	total = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			value = ft_check_format(args, &*s);
			if (value == -1)
				return (-1);
			total = total + value;
		}
		else
			total = total + write(1, &*s, 1);
		s++;
	}
	va_end(args);
	return (total);
}

// int	main(void)
// {
// 	ft_printf("%d\n", ft_printf(" %c %c %c ", '0', 97, '1'));
// 	ft_printf("%d \n", ft_printf("ola%%%"));
// 	//printf("%d \n", printf("ola%%%"));
 
// 	int teste = printf("hello world\n");
// 	printf("imprimiu: %d\n", teste);
// 	int teste2 = ft_printf("hello world\n");
// 	ft_printf("imprimiu: %d\n", teste2);
// 	printf("\n");
// 	int x = 42;
// 	int x2 = 34;
// 	void *ptrx2 = &x2;
// 	void *ptr = &x;

	
// 	ft_printf("HELLO\n");
// 	ft_printf("%d \n", ft_printf(""));
// 	ft_printf("%d \n", ft_printf(NULL));
// 	ft_printf("CHARACTERS: %c %c\n", 'a', 'b');
// 	ft_printf("STRINGS: %s %s\n", "Good", "bye");
// 	ft_printf("DECIMAL: %i %d\n", 42, 123);
// 	ft_printf ("DECIMALS: %d %d\n", 1977, 650000L);
// 	ft_printf("POINTER NULO: %p \n", NULL );
// 	ft_printf("POINTER DE x é: %p\n", ptr);
// 	ft_printf("POINTER 0: %p %p \n", (void *)0, (void *)0);
// 	ft_printf ("DECIMAL e HEXADECIMAL: %d %x %X \n", 255, 255, 255);
// 	ft_printf ("HEXADECIMAL 0: %x %X\n", 0, 0);
// 	ft_printf ("Unsigned int: %u %u\n",  2147483647, UINT_MAX);
// 	ft_printf ("Unsigned int: %u \n", UINT_MAX);
// 	ft_printf ("Mix: %c, %s, %p, %d, %i, %x, %X, %u, %%, all mixed\n", 'A',
// 		"Mix", ptrx2, 34, 34, 255, 255, UINT_MAX);


// 	ft_printf("\n");
	
// 	printf("Hello\n");
// 	printf("%d \n", printf(""));
// 	printf("%d \n", printf(NULL));
// 	printf("Characters: %c %c\n", 'a', 'b');
// 	printf("Strings: %s %s\n", "Good", "bye");
// 	printf("Decimal: %d %d\n", 42, 123);
// 	printf ("Decimals: %d %ld\n", 1977, 650000L);
// 	printf("Pointer nulo: %p \n", NULL );
// 	printf("Pointer de x é: %p\n", ptr);
// 	printf("Pointer 0: %p %p \n", (void *)0, (void *)0);
// 	printf ("Decimal e hexadecimal: %d %x %X \n", 255, 255, 255);
// 	printf (" Hexadecimal 0: %x %X\n", 0, 0);
// 	printf ("Unsigned int: %u %u\n", 2147483647, UINT_MAX);
// 	printf ("Unsigned int: %u \n", UINT_MAX);
// 	printf ("Mix: %c, %s, %p, %d, %i, %x, %X, %u, %%, all mixed\n", 'A', "Mix",
// 		ptrx2, 34, 34, 255, 255, UINT_MAX);
// 	return (0);
// }