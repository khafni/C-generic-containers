#ifndef GOBJFUN_H
# define GOBJFUN_H
# include <stdio.h>
# include <stdlib.h>

/*
** different function pointers to help with generic containers
*/

typedef char bool;
typedef void (*fun_print) (void* obj);
typedef int (*fun_compare) (void* obj1, void* obj2);
typedef bool (*fun_equal) (void* obj1, void* obj2);
typedef void (*destructor) (void** objptr);
typedef void* (*fun_clone) (void* obj);
typedef void (*fun_copy) (void* src, void* tar);
typedef void (*fun_move) (void* src, void* tar);
typedef void (*fun_swap) (void* obj1, void* obj2);

typedef void (*fun_zero) (void* obj); 
typedef void (*fun_init) (void* obj); 
typedef void (*fun_free) (void* obj); 
typedef void* (*fun_make_new) (void);



typedef struct s_obj_funs t_obj_funs;

struct s_obj_funs {
  fun_make_new create;
  fun_print print;
  fun_compare compare; /* retourne -1, 0 ou +1   */
  fun_equal equal;     /* retourne TRUE ou FALSE */
  destructor destroy;
  fun_clone clone;
  fun_copy copy;
  fun_move move;
  fun_swap swap;
  fun_zero zero;
  fun_init init;
  fun_free free;
};

void obj_funs_init (t_obj_funs* F);
/* on copie enti�rement un obj_funs... cela peut servir pour cloner un conteneur g�n�rique */
void obj_funs_copy (t_obj_funs* src, t_obj_funs* tar);
t_obj_funs* zero_obj_funs_create (void);
void obj_funs_destroy (t_obj_funs** F);

#endif