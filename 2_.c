int a;
void f1(void){
	a = 1;
}

void f2(void){
	a = 2;
}

void f3(void){
	a = 3;
}

main(){
	
	printf("CS: %x\n", _CS);
	printf("--main: %lx\n", (long)main);
	printf("--f1: %lx\n", (long)f1);
	printf("--f2: %lx\n", (long)f2);
	printf("--f3: %lx\n", (long)f3);
	
	printf("main address: %x\n", &main);
	printf("f1 address: %x\n", &f1);
	printf("f2 address: %x\n", &f2);
	printf("f3 address: %x\n", &f3);
	
}