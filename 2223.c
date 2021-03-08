#include "2222.h"

typedef char myEleType;

myEleType a[20] = "hello world!";


void showList(List* lp);

int putEle(EleType* data);


void main() {

    List* lp;
    int n;
    char ch;
	int b;

    lp = CreatList(sizeof(myEleType));
    if (!lp) {
        printf("Create?\n");
        return;
    }

    for (n = 0; a[n]; n++) {
        ListAppend(lp, &a[n]);
    }
    showList(lp);

    ch = 'u';
    ListInsert(lp, 1, &ch);
	showList(lp);
	
	ch = 'i';
    ListInsert(lp, 8, &ch);
	showList(lp);
	
	
	puts("---------");
	
	ch = 'g';
    ListInsert(lp, 1, &ch);
	showList(lp);
	
	b = 2;
	ListInsert(lp, 6, &b);
	showList(lp);

} /* 011a */


void showList(List* lp) {
    TraverseList(lp, (int (*)(void *))putEle);
    printf("\n");
}


int putEle(EleType* data) {
    printf("%c", *data);
    return 1;
}

