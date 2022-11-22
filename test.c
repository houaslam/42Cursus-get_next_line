#include "get_next_line.h"

int main()
{
	int a = open("test.txt", O_RDONLY);
	//int s = open("tes.txt", O_RDONLY);
	//int b = open("te.txt", O_RDONLY);

	printf("%s", get_next_line(a));
	printf("%s", get_next_line(a));
	printf("%s", get_next_line(a));
	printf("%s", get_next_line(a));
	printf("%s", get_next_line(a));
	printf("%s", get_next_line(a));
	printf("%s", get_next_line(a));
	//printf("%s", get_next_line(s));
	//printf("%s", get_next_line(b));
	//printf("%s", get_next_line(a));
}