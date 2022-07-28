#include <stdio.h>
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

int print_p(unsigned long int)
{
    int ret;

    ret = 0;
    
    return(ret);
}

int ft_printer(char  conv, va_list *ap)
{
    int ret;

    ret = 0;
	if (conv == '%')
	{	
        write(1, "%", 1);
        ret++;
    }
    if (conv == 'c')
		ret += ft_putchar(va_arg(*ap, int));
	if (conv == 's')
		ret += ft_putstr(va_arg(*ap, char *));
    if (conv == 'd' || conv == 'i')
		ret += ft_putnbr(va_arg(*ap, int));
	if (conv == 'u')
		ret += ft_putnbr2(va_arg(*ap, unsigned int));
	if (conv == 'p')
		ret += print_p(va_arg(*ap, unsigned long int));
	/*if (conv == 'x' || conv == 'X')
		ret += print_h(va_arg(*ap, unsigned int), conv);
    */
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

int main(void)
{
    char c = 'c';
    char *s = "string";
    int i = -420;
    int *pi = &i;
    unsigned int u = 4294967295;

    printf("\n printf:\n// Conteudo em c:%c\n// Conteudo em *s:%s\n// Conteudo em i:%i\n// Conteudo em u:%u\n// Conteudo em *pi:%p\n", c, s, i, u, pi);
    ft_printf("\n ft_printf:\n// Conteudo em c:%c\n// Conteudo em *s:%s\n// Conteudo em i:%i\n// Conteudo em u:%u\n", c, s, i, u);

    return(0);
}