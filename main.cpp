#include <iostream>
#include <math.h>
using namespace std;


int trial(int base) {
	int bits = rand();
	for(int i = 0; i < 15; i++)
		if(bits & (1 << i))
			return pow(2, i + base);
	return trial(base + 15);
}

void run(double n) {
	long long max = pow(2, n);

	long long sum = 0;
	for(int i = 0; i < max; i++)
		sum += trial(0);
	
	cout << n << "," << sum / (double) max << endl;
}

int main(void) {
	srand((unsigned) time(NULL));

	int max = 30;
	double step = 0.5;

	for(int n = 0; n < max / step; n++){
		run(n * step);
	}
	return 0;
}
