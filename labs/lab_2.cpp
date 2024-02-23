#include <stdio.h>

void viewPointer(void *p) {
	char *p1 = reinterpret_cast<char *>(p);
	unsigned short *p2 = reinterpret_cast<unsigned short *>(p);
	double *p3 = reinterpret_cast<double *>(p);

	printf("p: %p\n", p);
	printf("p1: %p\n", p1);
	printf("p2: %p\n", p2);
	printf("p3: %p\n\n", p3);

    //printf("p+1: %p\n", p+1); //ошибка
	printf("p1+1: %p\n", p1+1); //разница между адресами = 1 байт
	printf("p2+1: %p\n", p2+1); //разница между адресами = 2 байта
	printf("p3+1: %p\n\n", p3+1); //разница между адресами = 8 байтов
}

void printPointer(void *p) {
	char *p1 = reinterpret_cast<char *>(p);
	unsigned short *p2 = reinterpret_cast<unsigned short *>(p);
	double *p3 = reinterpret_cast<double *>(p);

	//printf("*p: %d\n", *p); //ошибка
	printf("*p1: %c\n", *p1);
	printf("*p2: %x\n", *p2);
	printf("*p3: %e\n\n", *p3);

	printf("*(p1+1): %c\n", *(p1+1));
	printf("*(p2+1): %x\n", *(p2+1));
	printf("*(p3+1): %e\n\n", *(p3+1));
}

void printDump(void *p, size_t N) {
	unsigned char *p1 = reinterpret_cast<unsigned char *>(p);
	for (int i = 0; i < N; ++i) {
		printf("%02hhX ", *(p1+i));
	}
	printf("\n");
}

void print16(void *p) {
	unsigned short *p1 = reinterpret_cast<unsigned short *>(p);
	short *p2 = reinterpret_cast<short *>(p);
	//printf("uh: %04hx,\tud: %5u,\tsh: %04hx,\tsd: %6d\n", *p1, *p1, *p2, *p2);
	printf("h: %04hx,\tud: %5u,\tsd: %6d\n", *p1, *p1, *p2);
}

void print32(void *p) {
	unsigned int *p1 = reinterpret_cast<unsigned int *>(p);
	int *p2 = reinterpret_cast<int *>(p);
	float *p3 = reinterpret_cast<float *>(p);
	printf("h: %08x,\tud: %10u,\tsd: %11d,\tff: %14.2f,\tfs: %13e\n", *p1, *p1, *p2, *p3, *p3);
}

int main() {
	//int a = 42;
	//viewPointer(&a);

	//long long a = 0x1122334455667788;
	//printPointer(&a);

	//char a[] = "0123456789abcdef";
	//printPointer(&a);

	//int x = 9;
	//printDump(&x, 4); //младший байт по младшему адресу

	//int a[3] = {9, -9, 0x88776155};
	//printDump(a, 12);

	//double y = -9;
	//printDump(&y, 8);

	/*
	unsigned short a = 0;
	unsigned short b = 65535;
	short c = -32768;
	short d = 32767;
	unsigned short x = 9;
	short y = -9;
	print16(&a);
	print16(&b);
	print16(&c);
	print16(&d);
	print16(&x);
	print16(&y);
	*/

	/*
	unsigned int a = 0;
	unsigned int b = 4294967295;
	int c = -2147483648;
	int d = 2147483647;
	unsigned int x = 9;
	int y = -9;
	unsigned int z = 0x88776155;
	float fx = x;
	float fy = y;
	float fz = z;
	print32(&a);
	print32(&b);
	print32(&c);
	print32(&d);
	print32(&x);
	print32(&y);
	print32(&z);
	print32(&fx);
	print32(&fy);
	print32(&fz);
	*/

	return 0;

}
