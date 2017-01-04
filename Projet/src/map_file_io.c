#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct s_map_md
{
    int width;
    int height;
    int* map;
} __attribute__((packed));

typedef struct s_map_md t_map_md;

t_map_md* alloc_map_md(int width, int height)
{
    t_map_md* new_map_md = malloc(sizeof(*new_map_md));
    (*new_map_md).width = width;
    (*new_map_md).height = height;
    (*new_map_md).map = malloc(sizeof(int) * (width * height));
    return new_map_md;
}

void free_map_md(t_map_md* map_md)
{
    if (map_md != NULL)
    {
        if ((*map_md).map != NULL)
        {
            free((*map_md).map);
        }
        free(map_md);
    }
}

int read_map_md(const int fd, t_map_md* map_md)
{
    int nb_read = 0;
    int size = (*map_md).width * (*map_md).height;
    nb_read = read(fd, (*map_md).map, sizeof(int) * size);
    if (nb_read != sizeof(int) * size)
        return -1;
    return nb_read;
}

int write_map_md(int fd, const t_map_md* map_md)
{
    int nb_write = 0;
    int size = (*map_md).width * (*map_md).height;
    nb_write = write(fd, (*map_md).map, sizeof(int) * size);
    return nb_write;
}

int get_pos(t_map_md* map_md, int x, int y)
{
    return ((*map_md).map[y * (*map_md).width + x]);
}

void set_pos(t_map_md* map_md, int x, int y, int val)
{
    (*map_md).map[y * (*map_md).width + x] = val;
}
