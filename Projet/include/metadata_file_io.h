#ifndef _METADATA_FILE_IO_H
# define _METADATA_FILE_IO_H

typedef struct s_metadata t_metadata;

t_metadata* alloc_md(void);
void free_md(t_metadata* md);

int read_md(const int fd, t_metadata* md);
int write_md(int fd, const t_metadata* md);

unsigned int get_width(t_metadata* md);
void set_width(t_metadata* md, unsigned int width);

unsigned int get_height(t_metadata* md);
void set_height(t_metadata* md, unsigned int height);

unsigned int get_nb_objs(t_metadata* md);
void set_nb_objs(t_metadata* md, unsigned int nb_objs);

#endif /* _METADATA_FILE_IO_H */
