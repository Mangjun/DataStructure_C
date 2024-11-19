#include <stdio.h>

typedef struct {
	int real;
	int imag;
} Complex;

Complex complex_add(Complex a, Complex b);
void print(Complex c);

int main() {
	Complex a = {1, 2};
	Complex b = {3, 4};

	Complex c;
	c = complex_add(a, b);

	print(a);
	print(b);
	printf("-----------------------\n");
	print(c);

	return 0;
}

Complex complex_add(Complex a, Complex b) {
	Complex c;

	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;

	return c;
}

void print(Complex c) {
	printf("%d + %di\n", c.real, c.imag);
}
