#include "gobjfun.h"

void obj_funs_init(t_obj_funs *F)
{
    F->create = NULL;
    F->print = NULL;
    F->compare = NULL;
    F->equal = NULL;
    F->destroy = NULL;
    F->clone = NULL;
    F->copy = NULL;
    F->move = NULL;
    F->swap = NULL;
    F->zero = NULL;
    F->init = NULL;
    F->free = NULL;
}

void obj_funs_copy(t_obj_funs *src, t_obj_funs *dst)
{
    dst->create = src->create;
    dst->print = src->print;
    dst->compare = src->compare;
    dst->equal = src->equal;
    dst->destroy = src->destroy;
    dst->clone = src->clone;
    dst->copy = src->copy;
    dst->move = src->move;
    dst->swap = src->swap;
    dst->zero = src->zero;
    dst->init = src->init;
    dst->free = src->free;
}

t_obj_funs *zero_obj_funs_create (void)
{
    t_obj_funs *F;

    F =  ((t_obj_funs *)malloc (sizeof(struct s_obj_funs)));
    if (F == NULL)
        return (NULL);
    obj_funs_init(F);
    return (F);
}

void obj_funs_destroy (t_obj_funs** F)
{
    free(*F);
    *F = NULL;
}
