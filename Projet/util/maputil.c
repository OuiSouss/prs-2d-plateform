
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <metadata_io_interface.h>

#define WIDTH_OPT 1
#define HEIGHT_OPT 2
#define OBJECTS_OPT 4
#define INFO_OPT 7

int parse_opt(const char* arg)
{
  if (strcmp(arg, "--getwidth") == 0)
        return WIDTH_OPT;
  if (strcmp(arg, "--getheight") == 0)
        return HEIGHT_OPT;
  if (strcmp(arg, "--getobjects") == 0)
        return OBJECTS_OPT;
  if (strcmp(arg, "--getinfo") == 0)
        return INFO_OPT;
    return -1;
}

void do_opt(int opt, t_metadata* md)
{
    if (opt & WIDTH_OPT)
    {
        fprintf(stdout, "map width : '%u.\n", get_width(md));
    }
    if (opt & HEIGHT_OPT)
    {
        fprintf(stdout, "map height : %u.\n", get_height(md));
    }
    if (opt & OBJECTS_OPT)
    {
        fprintf(stdout, "map objects number : %u.\n", get_nb_objs(md));
    }
}

int main(int ac, char** av)
{
    if (ac == 3)
    {
        int opt = 0;
        opt = parse_opt(av[2]);
        if (opt > 0)
        {
            int fd = open(*(av + 1), O_RDONLY);
            if (fd != -1)
            {
                t_metadata* md = alloc_md();
                int nb_read = 0;
                nb_read = read_md(fd, md);
                do_opt(opt, md);
                free_md(md);
                close(fd);
            }
            else
            {
                fprintf(stderr, "error : invalid input file or invalid input file format.\n");
            }
        }
        else
        {
            fprintf(stderr, "error : invalid option(s) specified.\n");
        }
    }
    else
    {
        fprintf(stderr, "error : invalid number of arguments.\nUsage : maputil <file> <option>.\n");
    }
    return 0;
}
