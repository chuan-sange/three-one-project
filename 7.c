#include "7.h"

char a[20] = "hello world!";


void showList(List* lp);

int putEle(EleType* data);


void main() {

    List* lp;
    int n;
    char ch;
	int b;

    lp = CreateList();
    if (!lp) {
        printf("Create?\n");
        return;
    }

    for (n = 0; a[n]; n++) {
        ListAppend(lp, &a[n], sizeof(a));
    }
    showList(lp);

    ch = 'u';
    ListInsert(lp, 1, &ch, sizeof(ch));
	showList(lp);
	
	ch = 'i';
    ListInsert(lp, 8, &ch, sizeof(ch));
	showList(lp);
	
	
	puts("---------");
	printf("%d\n", sizeof(EleType));
	
	ch = 'g';
    ListInsert(lp, 1, &ch, sizeof(ch));
	showList(lp);
	
	b = 5;
	ListInsert(lp, 1, &b, sizeof(b));
	showList(lp);
	

} /* 011a */


void showList(List* lp) {
    TraverseList(lp, (int (*)(void*))putEle);
    printf("\n");
}

int putEle(EleType* data) {
    printf("%c", (char *)*data);
    return 1;
}

