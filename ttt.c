main(){
	int n;
	int a = 5;
	int *b;

	b = &a;
	printf("b = %x\n", b);
	printf("*b = %d\n", *b);
	b++;
	printf("b + 1 = %x\n", b);
	
	
}