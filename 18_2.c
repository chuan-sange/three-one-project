#include "list1.h"

int a[8] = {11, 22, 33, 44, 55, 66, 77, 88};

void showList(List *);

int putElement(EleType *);

main(){
	
	List *lp;
	int n;
	
	lp = CreateList();
	if(!lp){
		printf("Create?\n");
		return;
	}
	
	for(n = 0; n < 8; n++){
		ListAppend(lp, a[n]);
	}
	showList(lp);
	
	ListInsert(lp, 1, 8);
	showList(lp);
	
	ListInsert(lp, 8, 18);
	showList(lp);
	
	ListDelete(lp, 1);
	showList(lp);
	
	ListDelete(lp, 7);
	showList(lp);
	
}


void showList(List *lp){
	TraverseList(lp, putElement);
	printf("\n");
}

int putElement(EleType *data){
	printf("%d ", *data);
	return 1;
}





















