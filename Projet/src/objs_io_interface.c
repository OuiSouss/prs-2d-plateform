#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <metadata_io_interface.h>
#include <obj_io_interface.h>

struct s_objs_md
{
    unsigned int nb_objs;
    t_obj** objs;
} __attribute__((packed));

typedef struct s_objs_md t_objs_md;

t_objs_md* alloc_objs_md(unsigned int nb_objs)
{
    t_objs_md* new_objs_md = malloc(sizeof(*new_objs_md));
    (*new_objs_md).nb_objs = nb_objs;
    (*new_objs_md).objs = malloc(sizeof(*((*new_objs_md).objs)) * nb_objs);
    return new_objs_md;
}

void free_objs_md(t_objs_md* objs_md)
{
    for (int i = 0; i < (*objs_md).nb_objs; ++i)
    {
      free_obj(((*objs_md).objs[i]));
    }
    free(objs_md);
}

void read_objs_md(const int fd, t_objs_md* objs_md)
{
    int nb_read = 0;
    for (int i = 0; i < (*objs_md).nb_objs; ++i)
    {
        t_obj* obj = alloc_obj();
        nb_read = read_obj(fd, obj);
	(*objs_md).objs[i] = obj;
    }
}

void write_objs_md(int fd, t_objs_md* objs_md)
{
    int nb_write = 0;
    for (int i = 0; i < (*objs_md).nb_objs; ++i)
    {
        nb_write = write_obj(fd, (*objs_md).objs[i]);
    }
}

t_objs_md* pack_objs_md(t_metadata* md)
{
    t_objs_md* objs_md = alloc_objs_md(get_nb_objs(md));
    for (int i = 0; i < (*objs_md).nb_objs; ++i)
    {
        (*objs_md).objs[i] = pack_obj(i);
    }
    return objs_md;
}

void unpack_objs_md(t_objs_md* objs_md)
{
    map_object_begin((*objs_md).nb_objs);
    for (unsigned int i = 0; i < (*objs_md).nb_objs; ++i)
    {
        unpack_obj((*objs_md).objs[i]);
    }
    map_object_end();
}