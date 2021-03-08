#include"list_2.h"

#define MAX 20

char a[20] = "hello world!";

void showlist(List* lp);

int putEle(EleType* data);

int main(){
	List* lp;
	int i;
	
	lp = CreateList(MAX);
	
	for(i = 0; a[i]; i++){
		ListAppend(lp, a[i]);
	}
	/*
	TraverseList(lp);
	*/
	
	showlist(lp);
	
	
}

void showlist(List* lp){
	TraverseList(lp, putEle);
	printf("\n");
}

int putEle(EleType* data){
	printf("%c", *data);
}