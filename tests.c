#include <unistd.h>
#include <strdup.h>
#include <sys/types.h>
#include <fcntl.h>

#define BLUE	"\e[34m"
#define GREEN	"\e[32;1;1m"
#define RED	"\e[31;1;1m"

int	ft_strlen(char *str);
char	*ft_strcpy(char *dst, char *src);
int	ft_strcmp(char *str1, char *str2);
size_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);

void	main(void)
{
	printf(BLUE); printf("*** ft_strlen ***\n");
		char	*s1;

		s1 = strdup("... I wish i was the monster i you think i am!");
		if (ft_strlen(s1) == strlen(s1))
		{	printf(GREEN); printf("1 : good\n");	}
		else
		{	printf(RED); printf("1: bad\n");	}
	

	printf(BLUE); printf("*** ft_strcpy ***\n");
		char	*s2;

		s2 = ft_strcpy(s2, s1);
		if (strcmp(s1, s2) == 0)
		{	printf(GREEN); printf("1 : good\n");	}
		else
		{	printf(RED); printf("1 : bad\n");	}

	printf(BLUE); printf("*** ft_strcmp ***");
		if (ft_strcmp(s1, s2) == 0)
		{	printf(GREEN); printf("1 : good\n");	}
		else
		{	printf(RED); printf("1 : bad\n");	}

	printf(BLUE); printf("*** ft_write ***");
		int	x;
		int	y;

		x = ft_write(1, s2, strlen(s2));
		y = write(1, s2, strlen(s2));
		if (x == y)
		{	printf(GREEN); printf("1 : good\n");	}
		else
		{	printf(RED); printf("1 : bad\n");	}

	printf(BLUE); printf("*** ft_read ***");
		int	x;
		int	y;
		int	fd;

		fd = open(".test", O_CREAT|O_RDWR);
		write(fd, s1, strlen(s2));

		x = ft_read(1, s2, strlen(s2));
		y = read(0, s2, strlen(s2));
		if (x == y)
		{	printf(GREEN); printf("1 : good\n");	}
		else
		{	printf(RED); printf("1 : bad\n");	}
		if (strcmp(s1, s2) == 0)
		{	printf(GREEN); printf("2 : good\n");	}
		else
		{	printf(RED); printf("2 : bad\n");	}
}

