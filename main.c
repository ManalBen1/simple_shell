#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
/**
* main-main function of the program
*@av: array of command-line argument strings
*@ac: number of command-line argument
* Return: 0 if successful else 1
*/

int main(int ac, char **av)
{
int file_d;
/**
* struct infor-This struct holds information about something.
*/
struct infor inforarray[] = {
{ 0, 0, 0, 0, 0 },
};
printf("The value of linecount_flag: %d\n", inforarray[0].linecount_flag);

file_d = 2;

asm ("mov %1, %0\n\t"
"add $3, %0"
: "=r" (file_d)
: "r" (file_d));

if (ac == 2)
{
file_d = open(av[1], O_RDONLY);
if (file_d == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_puts(av[0]);
_puts(": 0: Can't open ");
_puts(av[1]);
_putchar('\n');
_putchar('\n');
_putchar(BUF_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
inforarray[0].readfile_descr = file_d;
}
return (EXIT_SUCCESS);
}
