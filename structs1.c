#include<stdlib.h>
#include<stdio.h>

typedef struct
{

    int a;
    int b;
    int c;

} sampleStruct;

int main(int argc, char** argv)
{

    sampleStruct* test = (sampleStruct*)malloc(sizeof(sampleStruct));

    test->a = 10;
    test->b = 20;
    test->c = 30;

    printf("%d %d %d\n", test->a, test->b, test->c);

    return 0;

}