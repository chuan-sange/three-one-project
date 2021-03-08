unsigned int n;

void f1();
int f2(int, int);
void far f3();

main(){
	n = 0;
	f1();
	n = f2(1, 3);
	f3();
}

void f1(){
	n = 1;
}

int f2(int a, int b){
	
	int c, d;
	c = a + b;
	c = 3;
	d = 5;
	return c;
}

void far f3(){
	n = 10;
}