int fa(char *);

int fa(char *str){
	int n;
	int a;
	int row;
	int col;
	char far *scr = (char far *)0xb8000000;
	char *buf;
	char ch;
	
	/* strlen 函数的功能是求字符串的长度 */
	n = strlen(str);
	
	/* 根据字符串的长度计算显示字符串的行列位置 */
	if(n / 80){
		/* 字符长度超过一行，计算屏幕中间的位置 */
		row = (25 - (n / 80 + 1)) / 2;
		col = 3;
	} else {
		row = 12;
		col = (80 - (n % 80)) / 2;
	}
	
	/* 保存原显存中相应空间中的内容。在屏幕中间显示提示字符串，有可能覆盖屏幕上原有的信息，
	   所以，在显示提示字符串之前，将原来显存中相应空间里的内容保存起来，在函数返回之前可以进行恢复。*/
	buf = (char *)malloc(n * 2);  /* ｎ*２　屏幕上的一个字符用两个字节保存(字符内容和颜色) */
	
	for(a = 0; a < n * 2; a++){
		/* 找到将要覆盖的显存位置，将其内容保存到buf区 */
		buf[a] = scr[(row - 1) * 160 + (col - 1) * 2 + a];
	}
	
	/* 显示提示字符串 */
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
	
	/* 接收用户的按键后，恢复原来显存位置的内容。颜色绿色 */
	for(a = 0; a < n * 2; a++){
		scr[(row - 1) * 160 + (col - 1) * 2 + a] = buf[a];
	}
	
	/* 根据用户的按键，返回相应的状态信息 */
	/* 用户输入 y或Y 程序返回1。其他为0 */
	return (ch == 'y' || ch == 'Y');
}


/* 调用fa，提问用户是否将屏幕上的字符变成绿色，提示用户是否清屏，
	然后根据用户的回答进行相关的处理 */
main(){
	int a;
	char far * p = (char far *)0xb8000000;
	
	printf("hello world!\n");
	printf("hello\n");
	printf("world\n");
	
	a = fa("use green paint?(y/n)");
	
	/* 满屏绿色，操作显存所有高位 */
	if(a){
		for(a = 0; a < 2000; a++){
			p[a * 2 + 1] = 2;
		}
	}
	
	a = fa("clear scr?(y/n)");
	
	if(a){
		system("cls");
	}
	
}



















