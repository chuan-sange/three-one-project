main(){
	
	unsigned char *p = (unsigned char*)0x2000;
	printf("%x\n", p);
	/*p = (int *)0xffff;
	printf("%x\n", p);*/
	/*for(p; p!=(char*)0xffff; p++){
		printf("%x -> %d \n", p, *p);
		if(getch() == 'q'){
			break;
		}
	}*/
	
	while(p != 0xffff){
		printf("%x -> %x \n", p, *p);
		p = *p;
		/*sleep(2000);*/
		if(kbhit()){
			if(getch() == 'q'){
				break;
			}
		}
		/*if(getch() == 'q'){
			break;
		}*/
	}
	
	
}

