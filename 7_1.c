main(){
	
	char *p = (char*)0x2000;
	printf("%x\n", p);
	/*p = (int *)0xffff;
	printf("%x\n", p);*/
	for(p; p!=(char*)0xffff; p++){
		printf("%x -> %d \n", p, *p);
		/*if(getch() == 'q'){
			break;
		}*/
	}
	/*do{
		printf("%x -> %d \n", p, *p);
		p++;
		if(getch() == 'q'){
			break;
		}
	}while(p!=(char*)0xffff);*/
	
}



