#include "list2.h"

typedef int myElemType;

myElemType a[8] = {11, 22, 33, 44, 55, 66, 77, 88};


void showList(List* );
 
int putElement(myElemType *);


main(){
	
	List *lp;
	int n;
	
	lp = CreateList(sizeof(myElemType));
	if(!lp){
		printf("Create?\n");
		return;
	}
	
	for(n = 0; n < 8; n++){
		ListAppend(lp, a[n]);
	}
	showList(lp);
	
	
}



void showList(List* lp) {
	if(!lp){
		return;
	}
	TraverseList(lp, (int(*)(void *))putElement); 
	printf("\n");
}


int putElement(myElemType *data) {
	if(!(data)){
		return 0;
	}
	printf("%d ",*data);
	return 1;
}


















