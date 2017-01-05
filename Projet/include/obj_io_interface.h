#ifndef _OBJ_IO_INTERFACE_H
# define _OBJ_IO_INTERFACE_H

typedef struct s_obj t_obj;

t_obj* alloc_obj(void);
void free_obj(t_obj* obj);

int read_obj(const int fd, t_obj* obj);
int write_obj(int fd, const t_obj* obj);

char* get_path(t_obj* obj);
void set_path(t_obj* obj, const char* path);

int get_nb_sprites(t_obj* obj);
void set_nb_sprites(t_obj* obj, int nb_sprites);

int get_attr(t_obj* obj);
void set_attr(t_obj* obj, int attr);

t_obj* pack_obj(int i);

#endif /* _OBJ_IO_INTERFACE_H */