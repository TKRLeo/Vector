#include "vector.h"
vector createVector(size_t n) {
    vector vec;
    vec.data = malloc(sizeof(int) * n );
    if (!vec.data) {
        fprintf(stderr,"bad alloc");
        exit(1);
    }

    vec.capacity = n;
    vec.size = 0;

    return vec;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
        return;
    }

    v->data = realloc(v->data, newCapacity * sizeof(int));
    if (!v->data) {
        fprintf(stderr,"bad alloc");
        exit(1);
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->data = realloc(v->data, v->size * sizeof(int));
}

void deleteVector(vector *v) {
    free(v->data);
}