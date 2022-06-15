#ifndef VECTOR_H
#define VECTOR_H


typedef struct Vector
{
    int *data;
    unsigned int length;
} Vector;


Vector *createVector(unsigned int length, int value);


Vector *freeVector(Vector *vector);


float meanVector(Vector *vector);


int minVector(Vector *vector);


int maxVector(Vector *vector);


void printVector(Vector *vector);


#endif // VECTOR_H
