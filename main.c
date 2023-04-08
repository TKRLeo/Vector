#include "libs/data_structures/vector/Vector.h"
#include <stdint.h>
#include <assert.h>

void test_pushBack_emptyVector() {
    Vector v = createVector(10);
    pushBack(&v,99);

    assert(v.size == 1);
    assert(v.capacity == 10);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
    int a[3] = {1,2,3};
    Vector v = createVecFromArr(a,3);
    pushBack(&v, 99);

    assert(v.size == 4);
    assert(v.capacity == 6);

    deleteVector(&v);
}

void test_pushBack_sizeUnderCap() {
    int a[5] = {1,2,3};
    Vector v = createVecFromArr(a,3);
    pushBack(&v,4);

    assert(v.size == 4);
    assert(v.capacity == 6);

    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    Vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVector(&v);
}

void test_popBack_fullVector() {
    int a[5] = {1,2,3};
    Vector v = createVecFromArr(a,3);

    popBack(&v);
    popBack(&v);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 3);

    deleteVector(&v);
}

void test_atVector_notEmptyVector() {
    int a[3] = {1,2,3};
    Vector v = createVecFromArr(a,3);

    int *ptr = atVector(&v, 1);
    assert(*ptr == 2);
}

void test_atVector_requestToLastElement() {
    int a[5] = {1,2,3,4,5};
    Vector v = createVecFromArr(a,5);

    int *ptr = atVector(&v,4);
    assert(*ptr == 5);
}

void test_back_oneElementInVector() {
    int a[5] = {1,2,3};
    Vector v = createVecFromArr(a,3);

    int* ptr = back(&v);

    assert(*ptr == 3);
}
void test_front_oneElementInVector() {
    int a[5] = {1,2,3};
    Vector v = createVecFromArr(a,3);

    int* ptr = front(&v);

    assert(*ptr == 1);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_pushBack_sizeUnderCap();

    test_popBack_notEmptyVector();
    test_popBack_fullVector();

    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();
    return 0;
}
