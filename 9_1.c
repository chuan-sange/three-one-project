char *p1 = "This is a c program.";
char *p2 = "welcome to c!";
char *p3 = "Hello world!";
char *p4 = "good!";
void showstr(char *, ...);


main(){
	
	showstr(p1, p2, p3, p4, 0);
}

void showstr(char *str, ...){
	int i = 0;
	while(*(int *)(_BP + 4 + i + i)){
		printf("%s\n", *(int *)(_BP + 4 + i + i));
		i++;
	}
}