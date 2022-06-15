#ifndef S_VECTOR_H
#define S_VECTOR_H


typedef struct sVector
{
    char *data;
    unsigned int length;
} sVector;


typedef struct sMatrix
{
    sVector **svector;
    unsigned int size;
} sMatrix;

int getNumberFromUser();


sVector *freeSVector(sVector *vector);


sVector *createSVector(unsigned int length, char value);


void printSVector(sVector *vector);


sMatrix *freeSMatrix(sMatrix *smatrix);


sMatrix *createSMatrix(unsigned int size, unsigned int length, char value);


void printSMatrix(sMatrix *smatrix);


#endif // S_VECTOR_H
