#include <unistd.h>
#include <stdarg.h>

#include "ft_printf.h"

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putnbr2(unsigned int n)
{
	int ret;

	ret = 0;
	if (n >= 10)
	{
		ret += ft_putnbr2(n / 10);
		ret += ft_putchar(n % 10 + '0');
	}
	else
		ret += ft_putchar(n + '0');
	return (ret); 
}

int ft_putnbr(int n)
{
	int ret;

	ret = 0;
	if (n < 0)
		{
			write(1, "-", 1);
			ret++;
			n *= -1;
		}
	return(ft_putnbr2(n) + ret);
}

int ft_putstr(char *s)
{
	int ret;
	int i;

	ret = 0;
	i = -1;
	if (!s)
		s = "(null)";
	while(s[++i])
	{
		write(1, &s[i], 1);
		ret++;
	}
	return (ret);
}

int ft_putptr2(unsigned long int n)
{
	int ret;

	ret = 0;
	if(n >= 16)
	{
		ret += ft_putptr2(n / 16);
		ret += ft_putptr2(n % 16);
	}
	else if(n <= 9)
		ret += ft_putchar(n + '0');
	else 
		ret += ft_putchar(n - 10 + 'a');
	return(ret);
}

int ft_putptr(unsigned long long int n)
{
	int ret;

	ret = 0;
	ret += write(1, "0x", 2);
	if (n == 0)
		ret += write(1, "0", 1); // verificar
	else
	   ret += ft_putptr2(n);
	return (ret);
}

int ft_putx(unsigned int n, char conv)
{
	int ret;

	ret = 0;
	if(n >= 16)
	{
		ret += ft_putx(n / 16, conv);
		ret += ft_putx(n % 16, conv);
	}
	else if(n <= 9)
		ret += ft_putchar(n + '0');
	else if(conv == 'x')
		ret += ft_putchar(n - 10 + 'a');
	else if(conv == 'X')
		ret += ft_putchar(n - 10 + 'A');
	return(ret);
}

int ft_printer(char  conv, va_list *ap)
{
	int ret;

	ret = 0;
	if (conv == '%')
		ret += write(1, "%", 1);
	if (conv == 'c')
		ret += ft_putchar(va_arg(*ap, int));
	if (conv == 's')
		ret += ft_putstr(va_arg(*ap, char *));
	if (conv == 'd' || conv == 'i')
		ret += ft_putnbr(va_arg(*ap, int));
	if (conv == 'u')
		ret += ft_putnbr2(va_arg(*ap, unsigned int));
	if (conv == 'p')
		ret += ft_putptr(va_arg(*ap, unsigned long int));
	if (conv == 'x' || conv == 'X')
		ret += ft_putx(va_arg(*ap, unsigned int), conv);
	return (ret);
}

int ft_printf(const char *format, ...)
{
	int ret;
	int i;
	va_list ap;

	ret = 0;
	i = 0;
	va_start(ap, format);
	while(format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			ret++;
		}
		if (format[i] == '%')
		{
			i++;
			ret += ft_printer(format[i], &ap);
		}
		i++;
	}
	va_end(ap);
	return (ret);
}


#include <stdio.h>

int main(void)
{
	char c = 'c';
	char *s = "string";
	int i = -420;
	int *pi = &i;
	unsigned int u = 4294967295;
	int ret = 0;
	unsigned int x = 2319021421;

	printf("\nTESTE PRINTF\n");
	ret = printf("%%c:%c\n%%s:%s\n%%i/d:%i\n%%u:%u\n%%p:%p\n%%x:%x\n%%X:%X", c, s, i, u, pi, x, x);
	printf("\nreturn:%i\n", ret);
	ft_printf("\nTESTE FT_PRINTF\n");
	ret = ft_printf("%%c:%c\n%%s:%s\n%%i/d:%i\n%%u:%u\n%%p:%p\n%%x:%x\n%%X:%X", c, s, i, u, pi, x, x);
	ft_printf("\nreturn:%i\n\n", ret);
	return(0);
}
