struct stu{
	int number;
	char c;
	char os;
	char masm;
};


struct stu a;


main(){
	struct stu b;
	
	a.number = 1;
	a.c = 80;
	a.os = 82;
	a.masm = 88;
	
	b.number = 2;
	b.c = 90;
	b.os = 92;
	b.masm = 98;
	
	printf("number  c   os  masm\n");
	printf("-------------------\n");
	printf("%d      %d   %d  %d\n", a.number, a.c, a.os, a.masm);
	printf("%d      %d   %d  %d\n", b.number, b.c, b.os, b.masm);
	
}


