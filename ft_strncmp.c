#include "ft_ls.h"

int     ft_strncmp(const char *s1, const char *s2, unsigned  int i)
{
    const unsigned char*str1;
    const unsigned char*str2;

    str1 = (const unsigned char*)s1;
    str2 = (const unsigned char*)s2;
    while (i > 0 && *str1 && *str2 && *str1 == *str2)
    {
        ++str1;
        ++str2;
        --i;
    }
    return ((i) ? (*str1 - *str2) : 0);
}
