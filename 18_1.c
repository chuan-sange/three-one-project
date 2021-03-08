#include "2.h"

char a[20] = "hello world!";

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
	
	for(n = 0; a[n]; n++){
		ListAppend(lp, a[n]);
	}
	showList(lp);
	
	/* "hello world!" */
	ListInsert(lp, 1, 'o');
	showList(lp);
	
	/* "ohello world!" */
	ListInsert(lp, 8, 'a');
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
	printf("%c", *data);
	return 1;
}





















