typedef struct {
	int num;
	unsigned char c;
	unsigned char os;
	unsigned char masm;
	char name[20];
}stu;

main(){
	char *p;
	int i;
	stu s = {100, 'q', 'w', 'e',"kjkjkj"};
	
	printf("stuSize: %d\n", sizeof(s));
	for(i = 0; i < sizeof(s); i++){
		printf("%x ", (char)&s + i);
		if(i%10 == 9){
			printf("\n");
		}
	}
	printf("\n---------\n");
	
	printf("s.num : %d\n", s.num);
	for(i = 0; i < sizeof(s.num); i++){
		printf("%x ", (int)&s.num + i);
		p = (char *)((int)&s.num + i);
		printf(": %d \n", *p);
	}
	printf("\n---------\n");
	
	printf("s.c : %c\n", s.c);
	for(i = 0; i < sizeof(s.c); i++){
		printf("%x ", (int)&s.c + i);
		p = (char *)((int)&s.c + i);
		printf(": %c \n", *p);
	}
	printf("\n---------\n");
	
	printf("s.masm : %c\n", s.masm);
	for(i = 0; i < sizeof(s.masm); i++){
		printf("%x ", (int)&s.masm + i);
		p = (char *)((int)&s.masm + i);
		printf(": %c \n", *p);
	}
	printf("\n---------\n");
	
	
	printf("s.name : %s\n", s.name);
	for(i = 0; i < sizeof(s.name); i++){
		printf("%x ", (unsigned char)&s.name + i);
		p = (char *)((int)&s.name + i);
		printf(": %c \n", *p);
	}
	printf("\n---------\n");
	
	
	
}