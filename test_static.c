#include <stdio.h>
#include "get_next_line.h"

void    print_static(void)
{
    static char *str = "staic";

    printf("%s\n", str);
    str = ft_strjoin(str, " staic");
}


int main()
{
    print_static();
    print_static();
    print_static();

    return (0);
}