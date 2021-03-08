int *p;
int f1(int a);
int f2(int a);
main(){
	int b = 5;
	f1(b);
	f2(100);
	printf("f1 and f2 done : %x\n", *p);
}

int f1(int a){
	p = &a;
	printf("f1..: %x\n", *p);
	return 1;
}

int f2(int a){
	printf("f2 done\n");
	return 1;
}
