#include <stdio.h>

void print16(void *p) {
	unsigned short *p1 = reinterpret_cast<unsigned short *>(p);
	short *p2 = reinterpret_cast<short *>(p);
	printf("h:     %04hx,\tud: %10u,\tsd: %11d\n", *p1, *p1, *p2);
}

void print32(void *p) {
	unsigned int *p1 = reinterpret_cast<unsigned int *>(p);
	int *p2 = reinterpret_cast<int *>(p);
	float *p3 = reinterpret_cast<float *>(p);
	printf("h: %08x,\tud: %10u,\tsd: %11d,\tff: %14.2f,\tfs: %13e\n", *p1, *p1, *p2, *p3, *p3);
}


void testing_operations(short n)
{
    short x;
    printf("Число до операций:\n");
    print16(&n);
    printf("\n1) Знаковое умножение на 2:\n");
    x = *reinterpret_cast<signed short *>(&n) * 2;
    print16(&x);
    printf("\n2) Безнаковое умножение на 2:\n");
    x = *reinterpret_cast<unsigned short *>(&n) * 2;
    print16(&x);
    printf("\n3) Знаковое деление на 2:\n");
    x = *reinterpret_cast<signed short *>(&n) / 2;
    print16(&x);
    printf("\n4) Беззнаковое деление на 2:\n");
    x = *reinterpret_cast<unsigned short *>(&n) / 2;
    print16(&x);
    printf("\n5) Остаток от беззнакового деления на 16:\n");
    x = *reinterpret_cast<unsigned short *>(&n) - (*reinterpret_cast<unsigned short *>(&n) / 16) * 16;
    print16(&x);
    printf("\n6) Округление вниз до числа, кратного 16 (беззнаковое):\n");
    x = (*reinterpret_cast<unsigned short *>(&n) / 16) * 16;
    print16(&x);
    printf("\n7) Знаковый сдвиг влево на 1 бит:\n");
    x = *reinterpret_cast<signed short *>(&n) << 1;
    print16(&x);
    printf("\n8) Беззнаковый сдвиг влево на 1 бит:\n");
    x = *reinterpret_cast<unsigned short *>(&n) << 1;
    print16(&x);
    printf("\n9) Знаковый сдвиг вправо на 1 бит:\n");
    x = *reinterpret_cast<signed short *>(&n) >> 1;
    print16(&x);
    printf("\n10) Беззнаковый сдвиг вправо на 1 бит:\n");
    x = *reinterpret_cast<unsigned short *>(&n) >> 1;
    print16(&x);
    printf("\n11) x & 15:\n");
    x = *reinterpret_cast<signed short *>(&n) & 15;
    print16(&x);
    printf("\n12) x & -16:\n");
    x = *reinterpret_cast<signed short *>(&n) & -16;
    print16(&x);
}

unsigned int round64(unsigned int num, bool up = 0)
{
    int answer;
    if (up) answer = ((num + 255) >> 8) << 8;
    else answer = (num >> 8) << 8;
    return answer;
}

void increment(int *num)
{
    printf("Before increment:\n");
    print32(num);
    *num += 1;
    printf("After increment:\n");
    print32(num);
    printf("\n");
}

float abs_for_float(void *num)
{
    unsigned int tmp = (*static_cast<unsigned int*>(num) << 1) >> 1;
    return *static_cast<float*>(static_cast<void*>(&tmp));
}

float funny_sum(int N, bool reverse = 0)
{
    float sum = 0;
    if (reverse) for (int i = N; i > 0; i--) sum += (float) 1 / i;
    else for (int i = 1; i <= N; i++) sum += (float) 1 / i;
    return sum;
}

double funny_sum(int N, bool reverse = 0)
{
    double sum = 0;
    if (reverse) for (int i = N; i > 0; i--) sum += (double) 1 / i;
    else for (int i = 1; i <= N; i++) sum += (double) 1 / i;
    return sum;
}

void print64(void *p) {
    long long *p1 = reinterpret_cast<long long *>(p);
    double *p2 = reinterpret_cast<double *>(p);
	printf("h: %016llx,\tff: %f\n", *p1, *p2);
}

int main()
{
    printf("Ex. 1:\n");
    short m = 33, n = -101;
    unsigned int unsign_ext_of_m = static_cast<unsigned int>(*reinterpret_cast<unsigned short *>(&m));
    signed int sign_ext_of_m = static_cast<signed int>(m);
    unsigned int unsign_ext_of_n = static_cast<unsigned int>(*reinterpret_cast<unsigned short *>(&n));
    signed int sign_ext_of_n = static_cast<signed int>(n);

    printf("BEFORE CAST\n");
    printf("short int m:\n");
    print16(&m);
    printf("short int n:\n");
    print16(&n);
    printf("\n");
    printf("AFTER CAST\n");
    printf("unsigned int m:\n");
    print32(&unsign_ext_of_m);
    printf("signed int m:\n");
    print32(&sign_ext_of_m);
    printf("unsigned int n:\n");
    print32(&unsign_ext_of_n);
    printf("signed int n:\n");
    print32(&sign_ext_of_n);

    printf("\n\n\n");

    printf("Ex. 2:\n");
    testing_operations(m);
    printf("\n\n\n");
    testing_operations(n);

    printf("\n\n\n");

    printf("Ex. 3:\n");
    printf("Examples:\n");
    unsigned int D = 300, ans;
    printf("Number before round:\n");
    print32(&D);
    printf("Number after round down:\n");
    ans = round64(D, 0);
    print32(&ans);
    printf("Number after round up:\n");
    ans = round64(D, 1);
    print32(&ans);
    printf("\n");
    D = 1024;
    printf("Number before round:\n");
    print32(&D);
    printf("Number after round down:\n");
    ans = round64(D, 0);
    print32(&ans);
    printf("Number after round up:\n");
    ans = round64(D, 1);
    print32(&ans);

    printf("\n\n\n");

    printf("Ex. 4:\n");
    int a = 0, b = 1, c = 12345678, d = 123456789;
    int imin = INT_MIN, imax = INT_MAX; 
    int uimax = UINT_MAX;

    increment(&sign_ext_of_m);
    increment(&sign_ext_of_n);
    increment(&a);
    increment(&b);
    increment(&c);
    increment(&d);
    increment(&imin);
    increment(&imax);
    increment(&uimax);

    printf("\n\n\n");

    printf("Ex. 5:\n");
    float v_1 = 2.456, v_2 = -4.684;

    printf("Number before abs:\n");
    print32(&v_1);
    v_1 = abs_for_float(&v_1);
    printf("Number after abs:\n");
    print32(&v_1);
    printf("\n");

    printf("Number before abs:\n");
    print32(&v_2);
    v_2 = abs_for_float(&v_2);
    printf("Number after abs:\n");
    print32(&v_2);

    printf("\n\n\n");

    printf("Ex. 6:\n");
    float S_1 = funny_sum(pow(10, 9)), S_2 = funny_sum(pow(10, 6)), S_3 = funny_sum(pow(10, 9));
    float S_1_r = funny_sum(pow(10, 9), 1), S_2_r = funny_sum(pow(10, 6), 1), S_3_r = funny_sum(pow(10, 9), 1);

    printf("Float, direct, 10^3:\n");
    print32(&S_1);
    printf("Float, reversal, 10^3:\n");
    print32(&S_1_r);
    printf("Float, direct, 10^6:\n");
    print32(&S_2);
    printf("Float, reversal, 10^6:\n");
    print32(&S_2_r);
    printf("Float, direct, 10^9:\n");
    print32(&S_3);
    printf("Float, reversal, 10^9:\n");
    print32(&S_3_r);

    double SS_1 = funny_sum(pow(10, 3)), SS_2 = funny_sum(pow(10, 6)), SS_3 = funny_sum(pow(10, 9));
    double SS_1_r = funny_sum(pow(10, 3), 1), SS_2_r = funny_sum(pow(10, 6), 1), SS_3_r = funny_sum(pow(10, 9), 1);

    printf("Double, direct, 10^3:\n");
    print64(&SS_1);
    printf("Double, reversal, 10^3:\n");
    print64(&SS_1_r);
    printf("Double, direct, 10^6:\n");
    print64(&SS_2);
    printf("Double, reversal, 10^6:\n");
    print64(&SS_2_r);
    printf("Double, direct, 10^9:\n");
    print64(&SS_3);
    printf("Double, reversal, 10^9:\n");
    print64(&SS_3_r);
	
    return 0;
}
