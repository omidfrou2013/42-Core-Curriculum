#include <stdlib.h>

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = count_digits(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == -2147483648)
	{
		str[--len] = '8';
		n = n / 10;
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (--len >= 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
