
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#ifndef PROJECT_VECTOR_H
#define PROJECT_VECTOR_H

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

vector createVector(size_t n);
void reserve(vector *v, size_t newCapacity);
void clear(vector *v);
void shrinkToFit(vector *v);
void deleteVector(vector *v);
bool isEmpty(vector *v);
bool isFull(vector *v);
int getVectorValue(vector *v, size_t i);
void pushBack(vector *v, int x);
void popBack(vector *v);
#endif //PROJECT_VECTOR_H
