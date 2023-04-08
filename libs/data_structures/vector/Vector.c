#include "Vector.h"
Vector createVector(size_t n) {
    Vector vec;
    vec.data = malloc(sizeof(int) * n );
    if (!vec.data) {
        fprintf(stderr,"bad alloc");
        exit(1);
    }

    vec.capacity = n;
    vec.size = 0;

    return vec;
}

void reserve(Vector *v, size_t newCapacity) {
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

void clear(Vector *v) {
    v->size = 0;
}

void shrinkToFit(Vector *v) {
    v->data = realloc(v->data, v->size * sizeof(int));
}

void deleteVector(Vector *v) {
    free(v->data);
}

bool isEmpty(Vector *v) {
    return v->size == 0 ? 1 : 0;
}

bool isFull(Vector *v) {
    return (v->size != 0) && (v->size == v->capacity) ? 1 : 0;
}

int getVectorValue(Vector *v, size_t i) {
    return v->data[i];
}

void pushBack(Vector *v, int x) {
    if (isFull(v))
        reserve(v, 2 * v->capacity);

    if (v->size == 0 && v->capacity == 0)
        v->capacity++;

    v->data[v->size++] = x;
}

void popBack(Vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector is Empty");
        exit(1);
    }

    v->size--;
}

int* atVector(Vector *v, size_t index) {
    if (index > v->size)
        fprintf(stderr, "IndexError: a[%d] is not exists", index);

    return v->data + index;
}

int* back(Vector *v) {
    return v->data + v->size - 1;
}

int* front(Vector *v) {
    return v->data;
}
