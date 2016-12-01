#pragma once
#ifndef _DATA_H
#define _DATA_H

typedef struct s_map_data t_map_data;

int unmap_data(t_map_data* data);

const t_map_data* read_map_data(const int fd);
void write_map_data(int fd, const t_map_data* data);

const unsigned int get_width(const t_map_data* data);
void set_width(t_map_data* data, const unsigned int width);

const unsigned int get_height(const t_map_data* data);
void set_height(t_map_data* data, const unsigned int height);

const unsigned int get_objets(const t_map_data* data);
void set_objects(t_map_data* data, const unsigned int objects);


// int* map

// OBJ
// unsigned int path_size
// unsigned int nb_sprites
// unsigned int attr
// char* path


typedef struct s_obj t_obj;

int unmap_obj(t_obj* obj);

const t_obj* read_map_obj(const int fd);
void write_map_obj(int fd, const t_obj* obj);

const unsigned int get_path_size(const t_obj* obj);
void set_path_size(t_obj* obj, const unsigned int path_size);

const unsigned int get_nb_sprites(const t_obj* obj);
void set_nb_sprites(t_obj* obj, const unsigned int nb_sprites);

const unsigned int get_attr(const t_obj* obj);
void set_attr(t_obj* obj, const unsigned int attr);

const char* get_path(const t_obj* obj);
void set_path(t_obj* obj, const char* path);

#endif /* _DATA_H */
