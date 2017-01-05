#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <map.h>

#define MAX_PATH_LENGTH 256

struct s_obj
{
    unsigned int path_len;
    char path[MAX_PATH_LENGTH];
    int nb_sprites;
    int attr;
} __attribute__((packed));

typedef struct s_obj t_obj;

t_obj* alloc_obj(void)
{
    t_obj* new_obj = malloc(sizeof(*new_obj));
    return new_obj;
}

void free_obj(t_obj* obj)
{
    if (obj != NULL)
        free(obj);
}

int read_obj(const int fd, t_obj* obj)
{
    int nb_read = 0;
    nb_read = read(fd, obj, sizeof(*obj));
    if (nb_read != sizeof(*obj))
        return -1;
    return nb_read;
}

int write_obj(int fd, const t_obj* obj)
{
    int nb_write = 0;
    nb_write = write(fd, obj, sizeof(*obj));
    return nb_write;
}

static unsigned int get_path_len(const t_obj* obj)
{
    return ((unsigned int) (*obj).path_len);
}

static void set_path_len(t_obj* obj, unsigned int len)
{
    (*obj).path_len = len;
}

char* get_path(t_obj* obj)
{
    return ((char*) (*obj).path);
}

void set_path(t_obj* obj, const char* path)
{
    set_path_len(obj, strlen(path));
    strcpy((*obj).path, path);
}

int get_nb_sprites(t_obj* obj)
{
    return ((int) (*obj).nb_sprites);
}
void set_nb_sprites(t_obj* obj, int nb_sprites)
{
    (*obj).nb_sprites = nb_sprites;
}

int get_attr(t_obj* obj)
{
    return ((int) (*obj).attr);
}

void set_attr(t_obj* obj, int attr)
{
    (*obj).attr = attr;
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
