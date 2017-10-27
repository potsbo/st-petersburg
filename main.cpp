#include <iostream>
#include <math.h>
using namespace std;

const int rand_max_bit = log2(RAND_MAX);

int trial(int base = 0) {
	int bits = rand();
	for(int i = 0; i < rand_max_bit; i++)
		if(bits & (1 << i))
			return 1 << (i + base);
	return trial(base + rand_max_bit);
}

double run(double power) {
	unsigned long long max = pow(2, power);

	unsigned long long sum = 0;
	for(int i = 0; i < max; i++)
		sum += trial();
	
	return sum / (double) max;
}

int main(void) {
	srand((unsigned) time(NULL));

	const int max_bit = 30;
	const double step = 0.1;
	const int size = max_bit / step;

	for(int i = 0; i < size; i++){
		double power = i * step;
		cout << power << "," << run(power) << endl;
	}
	return 0;
}
