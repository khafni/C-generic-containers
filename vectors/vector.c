#include "vector.h"

t_vector *vector(int alloc, int cell_size, t_obj_funs funs)
{
    t_vector *v;

    v = malloc(sizeof(struct s_vector));
    v->data = malloc(alloc * cell_size);
    v->len = 0;
    v->alloc = alloc;
    v->cell_size = cell_size;
    v->funs = funs;
    return (v);
}

t_vector *empty_vector(int cell_size, t_obj_funs funs)
{
    return (vector(VECTOR_DEFAULT_ALLOC, cell_size, funs));
}

void vector_print(t_vector *v, char *sep)
{
    int i;
    char *ptr;

    if (!v->funs.print)
    {
        printf("vector.c > vector_print : no print function pointer found\n");
        return;
    }
    printf("[");
    while (i < v->len)
    {
        ptr = (char *)v->data + i * v->cell_size;
        (*v->funs.print)(ptr);
        if ((i < v->len - 1) && (sep != NULL))
            printf("%s", sep);
        i++;
    }
    printf("]\n");
}
void vector_grow_size(t_vector *v, int newalloc)
{
    void *tmp;

    if ((tmp = malloc(newalloc * v->cell_size)) == NULL)
        return;
    memcpy(tmp, v->data, v->alloc * v->cell_size);
    free(v->data);
    v->data = tmp;
    v->alloc = newalloc;
}

void vector_set(t_vector *v, int index, void *obj)
{
    char *target_ptr;

    if (index >= v->alloc)
        vector_grow_size(v, 1 + 2 * index);
    if (index >= v->len)
        v->len = index + 1;
    target_ptr = ((char *)v->data) + index * v->cell_size;
    (*v->funs.copy)(obj, target_ptr);
}

void vector_push_back(t_vector *v, void *obj)
{
    vector_set(v, v->len, obj);
}

void vector_destroy(t_vector **v_ptr)
{
    t_vector *v;
    int i;
    char *target_ptr;

    v = *v_ptr;
    i = 0;
    if (v->funs.free != NULL)
    {
        while (i < v->len)
        {
            target_ptr = ((char *)v->data) + i * (v->cell_size);
            (*v->funs.free)(target_ptr);
            i++;
        }
    }
    free(v->data);
    free(v);
    *v_ptr = NULL;
}
