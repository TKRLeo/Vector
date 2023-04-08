#include "libs/data_structures/vector/vector.h"
#include <stdint.h>
#include <assert.h>

void test_pushBack_emptyVector() {
    vector v = createVector(10);
    pushBack(&v,99);

    assert(v.size == 1);
    assert(v.capacity == 10);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(2);
    pushBack(&v, 4);
    pushBack(&v, 4);
    pushBack(&v, 99);

    assert(v.size == 3);
    assert(v.capacity == 4);

    deleteVector(&v);
}

void test_pushBack_sizeUnderCap() {
    vector v = createVector(3);
    pushBack(&v,3);
    pushBack(&v,4);

    assert(v.size == 2);
    assert(v.capacity == 3);

    deleteVector(&v);
}

void test_pushBack_sizeLargeCap() {
    vector v = createVector(3);
    pushBack(&v,3);
    pushBack(&v,4);
    pushBack(&v,7);
    pushBack(&v,8);

    assert(v.size == 4);
    assert(v.capacity == 6);

    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVector(&v);
}

void test_popBack_fullVector() {
    vector v = createVector(3);
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

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_pushBack_sizeUnderCap();
    test_pushBack_sizeLargeCap();

    test_popBack_notEmptyVector();
    test_popBack_fullVector();

}

int main() {
    test();
    return 0;
}
