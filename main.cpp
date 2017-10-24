#include <iostream>
#include <math.h>
using namespace std;

int trial(void) {
	for(int i = 0;; i++)
		if (rand()%2)
			return pow(2, i-1);
}

void run(double n) {
	long long max = pow(2, n);

	long long sum = 0;
	for(int i = 0; i < max; i++)
		sum += trial();
	
	cout << sum / (double) max  << "," << n << endl;
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
