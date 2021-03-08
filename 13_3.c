#include<stdlib.h>
#include "13_3.h"


float add(float a, float b) {
	return a + b;
}

float sub(float a, float b) {
	return a - b;
}

float mul(float a, float b) {
	return a * b;
}

float divide(float a, float b) {
	if(b == 0) {
		printf("the divide cannot be zero!\n");
		return -1;
	}
	
	return a / b;
}


int main() {
	showProgress();
}















