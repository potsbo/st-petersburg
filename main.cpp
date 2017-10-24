#include <iostream>
#include <math.h>
using namespace std;

const int rand_max_bit = log2(RAND_MAX);

int trial(int base) {
	int bits = rand();
	for(int i = 0; i < rand_max_bit; i++)
		if(bits & (1 << i))
			return 1 << (i + base);
	return trial(base + rand_max_bit);
}

void run(double n) {
	unsigned long long max = pow(2, n);

	unsigned long long sum = 0;
	for(int i = 0; i < max; i++)
		sum += trial(0);
	
	cout << n << "," << sum / (double) max << endl;
}

int main(void) {
	srand((unsigned) time(NULL));

	const int max_bit = 30;
	const double step = 0.1;
	const int max_count = max_bit / step;

	for(int n = 0; n < max_count; n++){
		run(n * step);
	}
	return 0;
}
