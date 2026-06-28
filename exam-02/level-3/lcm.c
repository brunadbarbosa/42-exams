int	ft_pgcd(unsigned int a, unsigned int b)
{
	if (b == 0)
		return (a);
	else
		return (ft_pgcd(b, a % b));

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (!a || !b)
		return (0);
	else
		return ((a * b) / ft_pgcd(a, b));
}
