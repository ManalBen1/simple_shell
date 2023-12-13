#include "shell.h"

/**
* @av: null terminated array of strings
* @ac: number of items in av
* Return 0 if successful else 1
*/
int main(int ac, char **av)
{
infor inforarray[] = { INFO_INIT };
int file_descr = 2;

asm ("mov %1, %0\n\t" "add $3, %0" : " = r " (file_d): " r " (file_d));

if (ac == 2)
{
file_d = open(av[1], O_RDONLY);
if (file_d == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_eputs(av[0]);
_eputs(": 0: Can't open ");
_eputs(av[1]);
_eputchar('\n');
_eputchar(BUF_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
inforarray->readfile_d = file_d;
}
populate_env_list(inforarray);
read_history(inforarray);
hsh(inforarray, av);
return (EXIT_SUCCESS);
}

