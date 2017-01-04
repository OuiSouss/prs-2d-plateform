#ifndef _OBJ_FILE_IO_H
# define _OBJ_FILE_IO_H

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

#endif /* _OBJ_FILE_IO_H */