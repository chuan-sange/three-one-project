struct stu {
  unsigned char c;
  unsigned char os;
  unsigned char masm;
  unsigned char java;

  struct stu far* next;
};

struct stu a[375];
int scoreSum[375];
int index[375];

main(){
	
	int i;
	int count = 0; 
	int step = 0;  
	int id = 0;   /* for index array*/
	
	/*copy for init*/
	for(i = 0; i < 375; i++){
		a[i].c = *(unsigned char far*)(0x0 + step + 0);
		a[i].os = *(unsigned char far*)(0x0 + step + 1);
		a[i].masm = *(unsigned char far*)(0x0 + step + 2);
		a[i].java = *(unsigned char far*)(0x0 + step + 3); 

		step += 8;
	}
	
	/* select the corresponding data by the condition */
	for(i = 0; i < 375; i++){
		scoreSum[i] = a[i].c + a[i].os + a[i].masm + a[i].java;
		if(200 < scoreSum[i] && scoreSum[i] < 400) {
			index[count] = i;
			count++;
		}
	}
	
	/* connect*/
	for(i = 0; i < count; i++){
		a[index[i]].next = (struct stu far*)(&a[index[i + 1]]);
	}
	
	/*print the data*/
	printf("The contend of index array : \n");
	id = index[0]; 
	
	for(i = 0; i < count; i++){
		printf("id = %d \n", id);
		printf("current --> %lx\n", (char far *)(a[index[i]].next));
		printf("id.c = %u  id.os = %u  id.masm = %u  id.java = %u \n", a[id].c, a[id].os, a[id].masm, a[id].java);
		printf("next --> %lx\n", (char far *)(a[index[i + 1]].next));
		printf("----------------------\n");
		id = index[i + 1];
	}

	/*for(i = 0; i < count; i++){
		printf("%d ", id);
		if(i != (count - 1)) {
			printf("--> ");
		}
		id = index[i + 1];
	}
	printf("\n\n");
	printf("%d\n", scoreSum[0]);
	*/
}
