extern void ft_putnbr_base(int nbr, char *base);

int main()
{
	char base[11] = "abcdefghij";
	ft_putnbr_base(1234567890, base);
	return (0);
}
