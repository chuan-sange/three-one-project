main(){
	
	/*char* a = (char *)malloc(20);
	char* b = (char *)malloc(20);*/
	char a[20];
	char b[20];
	char ch;
	
	char* temp = &a;
	a = &b;
	b = &a;
	
	
	
	
	
	
	gets(a);
	
	
	printf("%c\n", ch = getch());
	
	gets(b);
	
	if(ch != '+' && ch != '-'){
		printf("error!");
		return;
	}
	
	printf("-------------\n");
	
	if(ch == '+'){
		printf("%d", atoi(*a) + atoi(*b));
	}
	if(ch == '-'){
		printf("%d", atoi(*a) - atoi(*b));
	}
	
	free(a);
	free(b);
}