#include <stdarg.h>
#include <unistd.h>
#include "ft_ls.h"

int     ft_octo(int nb)
{
    int     res[20];
    int     i;
    int     ret;

    i = 0;
    ret = 0;   
    if (nb == 0)
        ret = 1;
    while (nb != 0)
    {
        res[i++] = nb % 8;
        nb = nb / 8;
    }
    while (--i >= 0)
        ft_putnbr(res[i]);
    return (ret);
}

void    min_hexa(int i, int *res)
{
    if (res[i] == 10)
        ft_putchar('a');
    if (res[i] == 11)
        ft_putchar('b');
    if (res[i] == 12)
        ft_putchar('c');
    if (res[i] == 13)
        ft_putchar('d');
    if (res[i] == 14)
        ft_putchar('e');
    if (res[i] == 15)
        ft_putchar('f');
}

void    maj_hexa(int i, int *res)
{
    if (res[i] == 10)
        ft_putchar('A');
    if (res[i] == 11)
        ft_putchar('B');
    if (res[i] == 12)
        ft_putchar('C');
    if (res[i] == 13)
        ft_putchar('D');
    if (res[i] == 14)
        ft_putchar('E');
    if (res[i] == 15)
        ft_putchar('F');
}

void     ft_hexa(int nb, int min_maj)
{
    int     res[20];
    int     i;

    i = 0;
    while (nb != 0)
    {
        res[i++] = nb % 16;
        nb = nb / 16;
    }
    while (--i >= 0)
    {
        if (res[i] > 9 && min_maj == 0)
            min_hexa(i, res);
        else if (res[i] > 9 && min_maj == 1)
            maj_hexa(i, res);
        else
            ft_putnbr(res[i]);
    }
}

void    ft_putuns(unsigned int n)
{
    if (n >= 10)
    {
        ft_putuns(n / 10);
        ft_putchar(n % 10 + 48);
    }
    if ((int)n < 10 && (int)n >= 0)
        ft_putchar(48 + n);
}

void    verif(char *str)
{
    int     i;

    i = 0;
    if (!(ft_strchr(str, '%')))
    {
        while (str[i])
        {
            ft_putstr(str);
            i++;
        }
    }
}

void    guess_letter(char c, va_list *ap)
{
    if (c == 'd' || c == 'D')
        ft_putnbr(va_arg(ap, int));
    else if (c == '%')
        ft_putchar(c);
    else if (c == 'c' || c =='C')
        ft_putchar(va_arg(ap, int));
    else if (c == 's')
        ft_putstr(va_arg(ap, char *));
    else if (c == 'o')
        ft_octo(va_arg(ap, int));
    else if (c == 'x')
        ft_hexa(va_arg(ap, int), 0);
    else if (c == 'X')
        ft_hexa(va_arg(ap, int), 1);
    else if (c == 'u')
        ft_putuns(va_arg(ap, int));
}

void    ft_printf(char *str, ...)
{
    int     i;
    va_list ap;

    verif(str);
    i = 0;
    va_start(ap, str);
    if (ft_strchr(str, '%'))
    {
        while (str[i])
        {
            if (str[i] == '%')
            {
                i++;
                guess_letter(str[i], &ap);
            }
            else
                write(1, &(str[i]), 1);
            i++;
        }
    }
    va_end(ap);
}
