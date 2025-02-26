#include <unistd.h>

int		check_doubles(char *str, char c, int pos)
{
	int i = 0;

	while (i < pos)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int i = 0;

	if (ac == 3)
	{
		while (av[1][i])
		{
			if (check_doubles(av[1], av[1][i], i))
				write(1, &av[1][i], 1);
			i++;
		}
		i = 0;
		while (av[2][i])
		{
			if (check_doubles(av[1], av[2][i], -1) && check_doubles(av[2], av[2][i], i))
					write(1, &av[2][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
