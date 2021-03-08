main(){
	int i;
	unsigned char *p;
	float a = 6.625;
	int aSize = sizeof(a);
	printf("aSize : %d\n", aSize);
	
	for(i = 0; i < aSize; i++){
		p = (char *)(int)&a + i;
		printf("%x : ", (char)&a + i);
		printf("%x \n", *p);
	}
	printf("c = %f\n", a);
	
	
}