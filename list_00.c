#include"list_00.h"

char a[20] = "perfect world";

void showList(List* lp);

int putEle(EleType* data);


void main(){
	List* lp;
	int i;
	int n;
	char temp;
	
	lp = CreateList(20);
	if(!lp){
		printf("create list error!\n");
		return;
	}
	
	for(i = 0; a[i]; i++){
		ListAppend(lp, a[i]);
	}
	showList(lp);
	
	n = 0;
	ListInsert(lp, 1, 'I');
	ListInsert(lp, 2, ' ');
	ListInsert(lp, 16, '!');
	ListInsert(lp, 3, ' ');
	ListInsert(lp, 3, 'a');
	ListInsert(lp, 2, 'n');
	n = ListInsert(lp, 0, '0');
	n = n + ListInsert(lp, 21, '0');
	n = n + ListInsert(lp, -1, '0');
	if(n){
		printf("insert list error!\n");
	} else {
		showList(lp);
	}
	
	n = 0;
	n = GetElement(lp, 1, &temp);
	if(n){
		printf("%c", temp);
		n = 0;
	}else{
		printf("get ele error!\n");
	}
	n = GetElement(lp, 19, &temp);
	if(n){
		printf("%c", temp);
		n = 0;
	}else{
		printf("get ele error!\n");
	}
	n = GetElement(lp, 21, &temp);
	if(n){
		printf("%c", temp);
		n = 0;
	}else{
		printf("get ele test sucess!\n");
	}
	
	n = 0;
	ListDelete(lp, 11);
	ListDelete(lp, 5);
	ListDelete(lp, 10);
	ListDelete(lp, 6);
	ListDelete(lp, 8);
	ListDelete(lp, 5);
	ListDelete(lp, 13);
	ListDelete(lp, 6);
	ListDelete(lp, 5);
	
	n = ListDelete(lp, 0);
	n = n + ListDelete(lp, -1);
	n = n + ListDelete(lp, 21);
	if(n){
		printf("list delete error!\n");
	}else{
		showList(lp);
	}
	
	ClearList(lp);
	if(IsEmpty(lp)){
		printf("clear list success!\n");
	} else {
		printf("clear list error!\n");
	}
	
}

void showList(List* lp){
	TraverseList(lp, putEle);
	printf("\n");
}

int putEle(EleType* data){
	printf("%c", *data);
	return 1;
}


