#include <stdio.h>
#include <cstddef>
#include <iostream>

#define N 5

#define CHECK_TYPE(TYPE)\
printf("Type: %s\nSize: %d byte\n\n", #TYPE, sizeof(TYPE))

#define PRINT_ARRAY(ARRAY, TYPE)\
    printf("Array name: %s\n", #ARRAY); \
    printf("Array type: %s\n", #TYPE); \
    if (#TYPE == "short") { \
        printf("Decimal:\n"); \
        for (int i = 0; i < N; i++) printf("%d ", ARRAY[i]); \
        printf("\nHexadecimal:\n"); \
        for (int i = 0; i < N; i++) { printf("%04hX ", ARRAY[i]); } \
    } \
    else if (#TYPE == "int") { \
        printf("Decimal:\n"); \
        for (int i = 0; i < N; i++) printf("%d ", ARRAY[i]); \
        printf("\nHexadecimal:\n"); \
        for (int i = 0; i < N; i++) { printf("%08X ", ARRAY[i]); } \
    } \
    else if (#TYPE == "long long") { \
        printf("Decimal:\n"); \
        for (int i = 0; i < N; i++) printf("%d ", ARRAY[i]); \
        printf("\nHexadecimal:\n"); \
        for (int i = 0; i < N; i++) { printf("%016llX ", ARRAY[i]); } \
    } \
    else if (#TYPE == "float") { \
        printf("Decimal:\n"); \
        for (int i = 0; i < N; i++) printf("%.2f ", ARRAY[i]); \
        printf("\nExponential:\n"); \
        for (int i = 0; i < N; i++) { printf("%e ", ARRAY[i]); } \
    } \
    else if (#TYPE == "double") { \
        printf("Decimal:\n"); \
        for (int i = 0; i < N; i++) printf("%.2lf ", ARRAY[i]); \
        printf("\nExponential:\n"); \
        for (int i = 0; i < N; i++) { printf("%le ", ARRAY[i]); } \
    } \
    if (#TYPE == "int8_t") { \
        printf("Decimal:\n"); \
        for (int i = 0; i < N; i++) printf("%d ", ARRAY[i]); \
        printf("\nHexadecimal:\n"); \
        for (int i = 0; i < N; i++) { printf("%hhX ", ARRAY[i]); } \
    } \
    printf("\n\n"); 

int main()
{
    printf("Ex. 1:\n");
    puts("Группа: ПМ-31");
    puts("Номер бригады: 5");
    puts("Состав бригады:\n\t1) Лежнин Максим\n\t2) Хвощевский Дмитрий");

    printf("\n\n\n");

    printf("Ex. 2:\n");
    CHECK_TYPE(char);
    CHECK_TYPE(signed char);
    CHECK_TYPE(unsigned char);
    CHECK_TYPE(char*);
    CHECK_TYPE(bool);
    CHECK_TYPE(wchar_t);
    CHECK_TYPE(short);
    CHECK_TYPE(int);
    CHECK_TYPE(long);
    CHECK_TYPE(long long);
    CHECK_TYPE(float);
    CHECK_TYPE(double);
    CHECK_TYPE(long double);
    CHECK_TYPE(size_t);
    CHECK_TYPE(ptrdiff_t);
    CHECK_TYPE(void*);

    printf("Ex. 4:\n");

    short Ms[N];
    int Ml[N];
    long long Mq[N];
    float Mfs[N];
    double Mfl[N];

    for (int i = 0; i < N; i++)
    {
        Ms[i] = 0xFADE;
        Ml[i] = 0xADE1A1DA;
        Mq[i] = 0xC1A551F1AB1E;
        Mfs[i] = 5 / 3.0;
        Mfl[i] = 5 / 3.0;
    }

    PRINT_ARRAY(Ms, short);
    PRINT_ARRAY(Ml, int);
    PRINT_ARRAY(Mq, long long);
    PRINT_ARRAY(Mfs, float);
    PRINT_ARRAY(Mfl, double);

    printf("\n\n\n");

    printf("Ex. 5:\n");
    printf("Address of Mfl array: %p\n", Mfl);
    printf("Address of first element in Mfl: %p\n", &(Mfl[0]));
    printf("Address of next element in Mfl: %p\n", &(Mfl[1]));

    printf("\n\n\n");

    printf("Ex. 6:\n");
    printf("BEFORE GETTING NEW VALUES\n");
    printf("-------------------------------------------------------------------------------------\n");
    PRINT_ARRAY(Ms, short);
    PRINT_ARRAY(Ml, int);
    PRINT_ARRAY(Mq, long long);
    PRINT_ARRAY(Mfs, float);
    PRINT_ARRAY(Mfl, double);

    if (scanf("%hd",  &Ms[2])  <= 0) puts("Error! Something went wrong with scanf for Ms[2]!\n");
    if (scanf("%d",   &Ml[2])  <= 0) puts("Error! Something went wrong with scanf for Ml[2]!\n");
    if (scanf("%lld", &Mq[2])  <= 0) puts("Error! Something went wrong with scanf for Mq[2]!\n");
    if (scanf("%f",   &Mfs[2]) <= 0) puts("Error! Something went wrong with scanf for Mfs[2]!\n");
    if (scanf("%lf",  &Mfl[2]) <= 0) puts("Error! Something went wrong with scanf for Mfl[2]!\n");

    printf("AFTER GETTING NEW VALUES\n");
    printf("-------------------------------------------------------------------------------------\n");
    PRINT_ARRAY(Ms, short);
    PRINT_ARRAY(Ml, int);
    PRINT_ARRAY(Mq, long long);
    PRINT_ARRAY(Mfs, float);
    PRINT_ARRAY(Mfl, double);

    printf("\n\n\n");

    printf("Ex. 7:\n");
    int8_t Mb[N];
    for (int i = 0; i < N; i++) Mb[i] = 0xED;
    printf("BEFORE GETTING NEW VALUE\n");
    PRINT_ARRAY(Mb, int8_t);
    if (scanf("%hhd",  &Mb[2]) <= 0) puts("Error! Something went wrong with scanf for Mb[2]!\n");
    printf("AFTER GETTING NEW VALUE\n");
    PRINT_ARRAY(Mb, int8_t);

    printf("\n\n\n");

    printf("Ex. 8:\n");
    printf("BEFORE GETTING NEW VALUES\n");
    PRINT_ARRAY(Mfl, double);
    if (scanf("%lf %lf %lf %lf %lf",  &Mfl[0], &Mfl[1], &Mfl[2], &Mfl[3], &Mfl[4]) < 5) 
        puts("Error! Something went wrong with scanf for Mfl!\n");
    printf("AFTER GETTING NEW VALUES\n");
    PRINT_ARRAY(Mfl, double);
    
    return 0;
}
