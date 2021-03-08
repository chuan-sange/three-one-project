char * code = "+-*/";

float add(float a, float b){
	return a + b;
}

float sub(float a, float b){
	return a - b;
}

float mul(float a, float b){
	return a * b;
}

float divide(float a, float b){
	if(b == 0){
		printf("Error! The divide cannot be zero!\n");
		return -1;
	}
	return a / b;
}

float (*func[4])(float, float) = {add, sub, mul, divide };


main(){
	char a[20];
	char b[20];
	char ch;
	
	int n;
	
	gets(a);
	
	printf("%c\n", ch = getch());
	
	gets(b);
	
	for(n = 0; code[n] && code[n] != ch; n++);
	
	if(!code[n]){
		printf("error!");
		return;
	}
	
	printf("-----------\n");
	
	printf("%f", func[n](atof(a), atof(b)));
	
}