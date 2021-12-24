#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#define BLUE	"\e[34m"
#define GREEN	"\e[32;1;1m"
#define RED		"\e[31;1;1m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define MAGENTA	"\e[35m"
#define NORMAL	"\e[0m"

unsigned	ft_strlen(char *str);
char		*ft_strcpy(char *dst, char *src);
char		*ft_strdup(const char *s);
int			ft_strcmp(char *str1, char *str2);
size_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);

int	main(void)
{
	char	*s1;
	char	*s2;

	printf(BLUE); printf("*** ft_strlen ***\n"); printf(NORMAL); //! FT_STRLEN

	# define STRING "Time is a flat circle"

		s1 = malloc(sizeof(char) * strlen(STRING) + 1);
		s2 = malloc(sizeof(char) * strlen(STRING) + 1);
		strcpy(s1, STRING);
		strcpy(s2, s1);

		if (ft_strlen(s1) == strlen(s1))
		{	printf(GREEN); printf("1 : good\n");	}
		else
		{	printf(RED); printf("1: bad\n");		}
		free(s1); free(s2);

	# undef STRING

	printf(BLUE); printf("*** ft_strcpy ***\n"); printf(NORMAL); //! FT_STRCPY

	# define STRING "Why do we fall?"

		s1 = malloc(sizeof(char*));
		s2 = NULL;

		if (ft_strcpy(s1, s2) == 0)
		{ printf(GREEN); printf("1 : good\n");		}
		else
		{ printf(RED); printf("1 : bad\n");			}

		s1 = malloc(sizeof(char) * strlen(STRING));
		s2 = calloc(strlen(STRING), sizeof(char));

		strcpy(s1, STRING);
		ft_strcpy(s2, s1);

		if (strcmp(s1, s2) == 0)
		{	printf(GREEN); printf("2 : good\n");	}
		else
		{	printf(RED); printf("2 : bad\n");		}
		free(s1); free(s2);

	# undef STRING

	printf(BLUE); printf("*** ft_strdup ***\n"); printf(NORMAL); //! FT_STRDUP
	
	# define STRING "The Algerian dey has a bump under his very nose"

	s1 = ft_strdup(STRING);
	s2 = strdup(STRING);

	if (!strcmp(s1, s2))
	{	printf(GREEN); printf("1 : good\n");	}
	else
	{	printf(RED); printf("1 : bad\n");		}
	free(s1); free(s2);

	# undef STRING

	printf(BLUE); printf("*** ft_strcmp ***\n"); printf(NORMAL); //! FT_STRCMP

	# define STRING "It's impossible... or necessary?"

		s1 = malloc(sizeof(char) * strlen(STRING) + 1);
		s2 = malloc(sizeof(char) * strlen(STRING) + 1);
		strcpy(s1, STRING);
		strcpy(s2, s1);

		if (ft_strcmp(s1, s2) == strcmp(s1, s2))
		{	printf(GREEN); printf("1 : good\n");	}
		else
		{	printf(RED); printf("1 : bad\n");		}

		strcpy(s2, "It's impossible.. or necessary?");
		
		if (ft_strcmp(s1, s2) == strcmp(s1, s2))
		{	printf(GREEN); printf("2 : good\n");	}
		else
		{	printf(RED); printf("2 : bad\n");		}
		free(s1); free(s2);

	# undef STRING

	printf(BLUE); printf("*** ft_write ***\n"); printf(NORMAL); //! FT_WRITE

	# define STRING "Everybody wants to be my enemyyyeeeee\n"

		int	x;
		int	y;

		x = ft_write(1, STRING, strlen(STRING));
		y = write(1, STRING, strlen(STRING));
		if (x == y)
		{	printf(GREEN); printf("1 : good\n");	}
		else
		{	printf(RED); printf("1 : bad\n");		}

	# undef STRING

	printf(BLUE); printf("*** ft_read ***\n"); printf(NORMAL); //! FT_READ

	# define STRING "I wanna be the very best. Like no one ever waaaass..."

		int	fd;

		s1 = calloc(100, sizeof(char));
		s2 = calloc(100, sizeof(char));

		fd = open("test_file.txt", O_RDWR, 0666);

		errno = 0;
		y = read(fd, s2, 10);
		x = ft_read(fd, s1, 10);

		if (errno == 9)
		{	printf(GREEN); printf("1 : good\n");	}
		else
		{	printf(RED); printf("1 : bad\n");		}
		if (!strcmp(s1, s2) && x == y)
		{	printf(GREEN); printf("2 : good\n");	}
		else
		{	printf(RED); printf("2 : bad\n");		}

		write(fd, STRING, strlen(STRING));

		x = ft_read(fd, s1, 10);
		y = read(fd, s2, 10);

		if (!strcmp(s1, s2) && x == y)
		{	printf(GREEN); printf("3 : good\n");	}
		else
		{	printf(RED); printf("3 : bad\n");		}

		unlink("test_file.txt");

	# undef STRING

		return (0);
}

