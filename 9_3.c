char *p1 = "This is a c program";
char *p2 = "welcome to c!";
char *p3 = "Hello world!";
char *p4 = "good!";
void showstr(char *, ...);

void showstr(char *pp, ...){
	char* *p = &pp;
	while(1){
		if(*p == 0){
			return;
		}else{
			printf("%s\n", *p);
		}
		p++;
	}
}


main(){
	showstr(p2, p1, p3, p4, 0);
}