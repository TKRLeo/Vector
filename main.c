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
    Vector v = createVector(2);
    pushBack(&v, 4);
    pushBack(&v, 4);
    pushBack(&v, 99);

    assert(v.size == 3);
    assert(v.capacity == 4);

    deleteVector(&v);
}

void test_pushBack_sizeUnderCap() {
    Vector v = createVector(3);
    pushBack(&v,3);
    pushBack(&v,4);

    assert(v.size == 2);
    assert(v.capacity == 3);

    deleteVector(&v);
}

void test_pushBack_sizeLargeCap() {
    Vector v = createVector(3);
    pushBack(&v,3);
    pushBack(&v,4);
    pushBack(&v,7);
    pushBack(&v,8);

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
    Vector v = createVector(3);
    pushBack(&v, 10);
    pushBack(&v, 20);
    pushBack(&v, 30);

    popBack(&v);
    popBack(&v);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 3);

    deleteVector(&v);
}

void test_atVector_notEmptyVector() {
    Vector v = createVector(3);
    pushBack(&v,1);
    pushBack(&v,2);
    pushBack(&v,3);

    int *ptr = atVector(&v, 1);
    assert(*ptr == 2);
}

void test_atVector_requestToLastElement() {
    Vector v = createVector(5);
    pushBack(&v,1);
    pushBack(&v,2);
    pushBack(&v,3);
    pushBack(&v,4);
    pushBack(&v,5);
    pushBack(&v,6);

    int *ptr = atVector(&v,5);
    assert(*ptr == 6);
}

void test_back_oneElementInVector() {
    Vector v = createVector(5);
    pushBack(&v,1);
    pushBack(&v,2);
    pushBack(&v,3);

    int* ptr = back(&v);

    assert(*ptr == 3);
}
void test_front_oneElementInVector() {
    Vector v = createVector(3);
    pushBack(&v,1);
    pushBack(&v,2);
    pushBack(&v,3);

    int* ptr = front(&v);

    assert(*ptr == 1);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_pushBack_sizeUnderCap();
    test_pushBack_sizeLargeCap();

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
