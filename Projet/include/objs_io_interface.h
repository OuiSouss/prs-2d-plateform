#ifndef _OBJS_IO_INTERFACE_H
# define _OBJS_IO_INTERFACE_H

# include <metadata_io_interface.h>

typedef struct s_objs_md t_objs_md;

t_objs_md* alloc_objs_md(unsigned int nb_objs);
void free_objs_md(t_objs_md* objs_md);

void read_objs_md(const int fd, t_objs_md* objs_md);
void write_objs_md(int fd, t_objs_md* objs_md);

t_objs_md* pack_objs_md(t_metadata* md);

#endif /* _OBJS_IO_INTERFACE_H */
