char a[20];
char b[20];

char* code = "+-*/";

char ch;

int n;

float add(float, float);
float sub(float, float);
float mul(float, float);
float divide(float, float);

float (*func[4])(float, float) = {add, sub, mul, divide};

void showProgress() {
	gets(a);
	
	printf("%c\n", ch = getch());
	
	gets(b);
	
	for(n = 0; code[n] && code[n] != ch; n++);
	
	if(!code[n]) {
		printf("error!");
		return;
	}
	
	printf("--------------------\n");
	printf("%5.5f", func[n](atof(a), atof(b)));
}


