#include "../libft.h"

int	main(void)
{
	int	fd;

	fd = 0;
	while (fd < 3)
	{
		write(fd,"{\nAttendu : [t]\nObtenu :  [",27);
		ft_putchar_fd('t', fd);
		write(fd,"]\nAttendu : [test]\nObtenu :  [",30);
		ft_putstr_fd("test", fd);
		write(fd,"]\nAttendu : [test\n]\nObtenu :  [",31);
		ft_putendl_fd("test", fd);
		write(fd,"]\nAttendu : [-2147483648]\nObtenu :  [",37);
		ft_putnbr_fd(-2147483648, fd);
		write(fd,"]\n}\n",4);
		fd++;
	}
	return (0);
}
