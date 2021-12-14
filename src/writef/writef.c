#include "writef.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_putnbr(int n)
{
	if (n < 0) {
		ft_putchar('-');
		n *= -1;
	}

	if (n > 10)
		ft_putnbr(n / 10);
	
	ft_putchar(n % 10 + '0');
}

void	writef(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format) {

		if (*format != '%') {
			ft_putchar(*format++);
			continue;
		}

		format++;

		switch(*format) {

			case 's': {
				ft_putstr(va_arg(args, char *));
				break;
			}
			
			case 'd': {
				ft_putnbr(va_arg(args, int));
				break;
			}
			
			default:
				break;
		}

		format++;
	}

	va_end(args);
}