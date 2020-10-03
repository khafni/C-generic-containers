#ifndef VECTOR_H
# define VECTOR_H
# include "../gobjfun.h"
# include <string.h>

#define VECTOR_DEFAULT_ALLOC 64

typedef struct  s_vector t_vector;

struct s_vector {
    void *data;
    int len;
    int alloc;
    int cell_size;
    t_obj_funs funs;
};

/*
** constructor
*/
t_vector *vector(int alloc, int cell_size, t_obj_funs funs);
t_vector *empty_vector (int cell_size, t_obj_funs funs);
void vector_print (t_vector *v, char *sep);
void vector_set (t_vector *v, int index, void *obj);
void vector_push_back (t_vector *v, void *obj);
void vector_destroy (t_vector **v_ptr);

#endif