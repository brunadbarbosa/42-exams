#include "bsq.c"

int min3(int a, int b, int c) {
	int m = a;
	if (b < m)
		m = b;
	if (c < m)
		m = c;
	return m;
}

void 