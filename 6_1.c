main(){
	int a = 11;
	long b = 80;
	double c = 333.3;
	
	
	char *p;
	int i;
	
	int aSize = sizeof(a);
	int bSize = sizeof(b);
	int cSize = sizeof(c);
	
	printf("aSize = %d\n", aSize);
	for(i = 0; i < aSize; i++){
		p = (char *)(int)&a + i;
		printf("%x : ", (int)&a + i);
		printf("%d \n", *p);
	}
	printf("a = %d\n", a);
	printf("----------\n");
	
	printf("bSize = %d\n", bSize);
	for(i = 0; i < bSize; i++){
		p = (char *)(int)&b + i;
		printf("%x : ", (int)&b + i);
		printf("%d \n", *p);
	}
	printf("b = %d\n", b);
	printf("----------\n");

	printf("cSize = %d\n", cSize);
	for(i = 0; i < cSize; i++){
		p = (char *)(int)&c + i;
		printf("%x : ", (int)&c + i);
		printf("%x \n", *p);
	}
	printf("c = %f\n", c);
	printf("----------\n");
	
}
