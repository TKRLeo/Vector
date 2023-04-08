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
    v->capacity = newCapacity;
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

bool isEmpty(vector *v) {
    return v->size == 0 ? 1 : 0;
}

bool isFull(vector *v) {
    return (v->size != 0) && (v->size == v->capacity) ? 1 : 0;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (isFull(v))
        reserve(v, 2 * v->capacity);

    if (v->size == 0 && v->capacity == 0)
        v->capacity++;

    v->data[v->size++] = x;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "vector is Empty");
        exit(1);
    }

    v->size--;
}
