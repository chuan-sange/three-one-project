main(){
	int i = 3;
	char c = 'a';
	int *p = &i;
	char *q = &c;
	int n = (char)&i;
	
	
	printf("%x\n", p);
	p++;
	printf("%x\n\n", p);

	printf("%x\n", q);
	q++;
	printf("%x\n\n", q);
	
	printf("%x\n", n);
	n++;
	printf("%x\n\n", n);

	
	
}
