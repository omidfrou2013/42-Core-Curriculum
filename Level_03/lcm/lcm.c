unsigned int	gcd(unsigned int a, unsigned int b)
{
	unsigned int	tmp;

	while (b)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return (a);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);

	return (a / gcd(a, b) * b);
}

//--------------------------------------------------------------
// #include <stdio.h>

// int main(void)
// {
// 	printf("%u\n", lcm(0, 5));
// }