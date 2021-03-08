int ask(char *, void (*)() );


int ask(char *str, void (*func)() ){
	int n;
	int a;
	int row;
	int col;
	char far *scr = (char far *)0xb8000000;
	char *buf;
	char ch;
	
	n = strlen(str);
	
	if(n / 80){
		row = (25 - (n / 80 + 1)) / 2;
		col = 3;
	} else {
		row = 12;
		col = (80 - (n % 80)) / 2;
	}
	
	buf = (char *)malloc(n * 2);  
	
	for(a = 0; a < n * 2; a++){
		buf[a] = scr[(row - 1) * 160 + (col - 1) * 2 + a];
	}
	
	
	for(a = 0; a < n; a++){
		scr[(row - 1) * 160 + (col - 1 + a) * 2] = str[a];
		scr[(row - 1) * 160 + (col - 1 + a) * 2 + 1] = 2;
	}
	
	while(8){
		ch = getch();
		if(ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N'){
			break;
		}
	}
	
	for(a = 0; a < n * 2; a++){
		scr[(row - 1) * 160 + (col - 1) * 2 + a] = buf[a];
	}
	
	if(ch == 'y' || ch == 'Y'){
		func();
		return 0;
	} 
	
	if(ch == 'n' || ch == 'N'){
		return 0;
	}
}

