#include "list2.h"

typedef struct {
	char name[20];
	char stuId[15];
	int age;
} myElemType;

myElemType a[5] = {{"zhangsan", "201702801111", 21},
					{"lisi", "201702802222", 22}, 
					{"wangwu", "201702803333", 23}, 
					{"zhaoliu", "201702804444", 24},
					{"songqi", "201702805555", 25}};

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
	
	for(n = 0; n < 5; n++){
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
	printf("%s %s %d \n", data->name, data->stuId, data->age);
	return 1;
}


















