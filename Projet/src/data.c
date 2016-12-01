#include <data.h>

typedef struct s_map_data
{
  unsigned int width;
  unsigned int height;
  unsigned int objects;
} t_map_data;

int unmap_data(t_map_data* data)
{
  return free(data);
}

const t_map_data* read_map_data(const int fd)
{
  t_map_data* p_data = malloc(sizeof(*p_data));
  int nb_read = read(fd, p_data, sizeof(*p_data));
  return p_data;
}

void write_map_data(int fd, const t_map_data* data)
{
  int nb_write = write(fd, data, sizeof(*data));
}

const unsigned int get_width(const t_map_data* data)
{
  return (*data).width;
}

void set_width(t_map_data* data, const unsigned int width)
{
  (*data).width = width;
}

typedef struct s_map_obj
{
  unsigned int path_size;
  unsigned int nb_sprites;
  unsigned int attr;
} t_map_obj;

typedef struct s_obj
{
  t_map_obj* obj;
  char* path;
} t_obj;

