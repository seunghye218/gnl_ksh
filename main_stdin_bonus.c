#include "get_next_line_bonus.h"
#include <stdio.h>

int main()
{
	char	*str;

	while ((str = get_next_line(0)))
	{
		printf("%s", str);
		free(str);
	}

	return (0);
}
