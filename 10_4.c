
void f(){
	printf("hello world!");
}

int main(){
	
	printf("f = %lx\n", f);
	printf("&f = %lx\n", &f);
	printf("*f = %lx\n", *f);
	printf("&(&f) = %lx\n", &(&f));
	printf("**f = %lx\	n", **f);

}