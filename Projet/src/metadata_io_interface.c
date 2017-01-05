#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <map.h>

struct s_metadata
{
    unsigned int width;
    unsigned int height;
    unsigned int nb_objs;
} __attribute__((packed));

typedef struct s_metadata t_metadata;

t_metadata* alloc_md(void)
{
    t_metadata* new_md = malloc(sizeof(*new_md));
    return new_md;
}

void free_md(t_metadata* md)
{
    if (md != NULL)
    {
        free(md);
    }
}

int read_md(const int fd, t_metadata* md)
{
    int nb_read = 0;
    nb_read = read(fd, md, sizeof(*md));
    if (nb_read != sizeof(*md))
        return -1;
    return nb_read;
}

int write_md(int fd, const t_metadata* md)
{
    int nb_write = 0;
    nb_write = write(fd, md, sizeof(*md));
    return nb_write;
}

unsigned int get_width(t_metadata* md)
{
    return ((*md).width);
}

void set_width(t_metadata* md, unsigned int width)
{
    (*md).width = width;
}

unsigned int get_height(t_metadata* md)
{
    return ((unsigned int) (*md).height);
}

void set_height(t_metadata* md, unsigned int height)
{
    (*md).height = height;
}

unsigned int get_nb_objs(t_metadata* md)
{
    return ((unsigned int) (*md).nb_objs);
}


void set_nb_objs(t_metadata* md, unsigned int nb_objs)
{
    (*md).nb_objs = nb_objs;
}

t_metadata* pack_metadata()
{
    t_metadata* md = alloc_md();
    set_width(md, map_width());
    set_height(md, map_height());
    set_nb_objs(md, map_objects());
    return md;
}