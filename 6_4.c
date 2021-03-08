main(){
	int a = 5;int b = 6;
	printf("%x\n", (int)&a);   
	printf("%x\n", (char)&a);
	printf("%x\n", *a);
	
	
	printf("%x\n", *((int)&b));  
	printf("%x\n", *((char)&b));
	printf("%x\n", *(&b));   
	
}