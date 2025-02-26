#include <unistd.h>

int		main(int ac, char **av)
{
	int i = 0;
	char *lw = NULL;

	if (ac == 2)
	{
		while (av[1][i])
		{
			if ((av[1][i] == ' ' || av[1][i] == '\t') && av[1][i + 1] > 32)
				lw = &av[1][i + 1];
			i++;
		}
		if (!lw && av[1][0] > 32)
			lw = av[1];
		while (lw && lw[i] > 32)
			write(1, lw++, 1);
	}
	write(1, "\n", 1);
	return (0);
}
