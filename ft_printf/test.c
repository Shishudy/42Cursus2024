#include "ft_printf.h"

int	ft_test_putstr(const char *s, int min, int max)
{
	int	i;
	int	str_len;
	int	period;
	int	total;

	if (!s)
		return (-1);
	period = 1;
	str_len = ft_strlen(s);
	total = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while ((min - max > 0) || (min > str_len))
		{
			write(1, " ", 1);
			total++;
			min--;
		}
		if (period == 1 && i == max)
			break ;
		write(1, &s[i], 1);
		total++;
		i++;
	}
	return (total);
}

int	ft_test_putnbr(int n, int min, int max)
{
	return (ft_test_putstr(ft_itoa(n), min, max));
}

int	main(void)
{
	// int	number = 12;

	// printf("%4.5d\n", number);
	// printf("%-10d\n", number);
    // printf("%010d\n", number);
    // printf("%-#10x\n", number);  
    // printf("%#x\n", number);

	/* Teste ft_putstr */
	// printf(" - %d\n", printf("printf :%6.4s", "2") - 8);
	// write(1, "ft_test_putstr:", 8);
	// printf(" - %d\n", ft_test_putstr("2", 6, 4));

	/* Teste ft_putnbr */
	printf(" - %d\n", printf("printf        :%1.d", 0) - 15);
	write(1, "ft_test_putnbr:", 15);
	printf(" - %d\n", ft_test_putnbr(0, 2, 5));

	printf("ft_atoi: %d\n", 05);
	// printf("%d%4.4d\n", 5, 0);
	// int	min = ft_atoi("040.");
	// printf("%d\n", min);
	// int	max = ft_atoi(".4d");
	// printf("%d\n", max);
}