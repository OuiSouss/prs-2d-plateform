#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <map.h>

#include <metadata_file_io.h>
#include <map_file_io.h>
#include <obj_file_io.h>

t_metadata* pack_metadata()
{
    t_metadata* md = alloc_md();
    set_width(md, map_width());
    set_height(md, map_height());
    set_nb_objs(md, map_objects());
    return md;
}

t_map_md* pack_map_md(t_metadata* md)
{
    t_map_md* map_md = alloc_map_md(get_width(md), get_height(md));
    for (unsigned int j = 0; j < get_height(md); ++j)
    {
        for (unsigned int i = 0; i < get_width(md); ++i)
        {
            set_pos(map_md, i, j, map_get(i, j));
        }
    }
    return map_md;
}

t_obj* pack_obj(int i)
{
    t_obj* obj = alloc_obj();
    set_path(obj, map_get_name(i));
    set_nb_sprites(obj, map_get_frames(i));
    int attr = map_get_solidity(i);
    attr |= map_is_destructible(i);
    attr |= map_is_collectible(i);
    attr |= map_is_generator(i);
    set_attr(obj, attr);
    return obj;
}

t_obj** pack_objs_md(t_metadata* md)
{
    t_obj** objs = malloc(sizeof(*objs) * get_nb_objs(md));
    for (int i = 0; i < get_nb_objs(md); ++i)
    {
        objs[i] = pack_obj(i);
    }
    return objs;
}

void write_objs_md(int fd, t_obj** objs)
{
    for (int i = 0; i < map_objects(); ++i)
    {
        write_obj(fd, objs[i]);
    }
}

void free_objs_md(t_obj** objs)
{
    for (int i = 0; i < map_objects(); ++i)
    {
        free_obj(objs[i]);
    }
    free(objs);
}

void do_save (char *filename)
{
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    printf("onche '%d' '%s'\n", fd, filename);
    if (fd != -1)
    {
        t_metadata* md = pack_metadata();
        t_map_md* map_md = pack_map_md(md);
        t_obj** objs = pack_objs_md(md);
        write_md(fd, md);
        write_map_md(fd, map_md);
        write_objs_md(fd, objs);
        free_md(md);
        free_map_md(map_md);
        free_objs_md(objs);
        close(fd);
    }
}
