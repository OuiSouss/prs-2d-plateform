#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <map.h>

#include <map_io_interface.h>
#include <metadata_io_interface.h>
#include <objs_io_interface.h>

void do_save(char* filename)
{
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd != -1)
    {
        t_metadata* md = pack_metadata();
        t_map_md* map_md = pack_map_md(md);
        t_objs_md* objs_md = pack_objs_md(md);
        write_md(fd, md);
        write_map_md(fd, map_md);
        write_objs_md(fd, objs_md);
        free_md(md);
        free_map_md(map_md);
        free_objs_md(objs_md);
        close(fd);
    }
}

void do_load(char* filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd != -1)
    {
        t_metadata* md = alloc_md();
        int nb_read = 0;
        nb_read = read_md(fd, md);
        t_map_md* map_md = alloc_map_md((int)get_width(md), (int)get_height(md));
        nb_read = read_map_md(fd, map_md);
        t_objs_md* objs_md = alloc_objs_md(get_nb_objs(md));
        read_objs_md(fd, objs_md);
        unpack_metadata(md);
        unpack_map_md(map_md);
        unpack_objs_md(objs_md);
        free_md(md);
        free_map_md(map_md);
        free_objs_md(objs_md);
    }
}
