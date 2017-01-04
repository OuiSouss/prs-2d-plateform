#ifndef _MAP_FILE_IO_H
# define _MAP_FILE_IO_H

typedef struct s_map_md t_map_md;

t_map_md* alloc_map_md(int width, int height);
void free_map_md(t_map_md* map_md);

int read_map_md(const int fd, t_map_md* map_md);
int write_map_md(int fd, const t_map_md* map_md);

int get_pos(t_map_md* map_md, int x, int y);
void set_pos(t_map_md* map_md, int x, int y, int val);

#endif /* _MAP_FILE_IO_H */
