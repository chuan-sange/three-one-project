typedef char EleType;

typedef struct {
	EleType* buf;
	unsigned int n;
	unsigned int max;
}List;

#define RIGHT 0
#define WRONG 1
#define CREATELIST 0
#define LISTAPPEND 1
#define LISTINSERT 2
#define LISTDELETE 3
#define GETELEMENT 4
#define CLEARLIST  5

extern List* CreateList(int max);

extern void DestroyList(List* lp);

extern void ClearList(List* lp);

extern int ListAppend(List* lp, EleType data);

extern int ListInsert(List* lp, int pos, EleType data);

extern int ListDelete(List* lp, int pos);

extern int GetElement(List* lp, int pos, EleType* data);

extern int IsEmpty(List* lp);

extern int IsFull(List* lp);

extern int TraverseList(List* lp, int(*f)(EleType*));


#define titleTest printf("your:");
#define titleSystem printf("\nsyst:");

void showList(List*);

int putE(EleType*);

void showResult(List*, int no, char* answer);


char* strArr[] = {
	"----------CreateList Test-----------",
	"----------ListAppend Test-----------",
	"----------ListInsert Test-----------",
	"----------ListDelete Test-----------",
	"----------GetElement Test-----------",
	"----------ClearList Test-----------",
}


main(){
	char* arr = "perfect world";
	
	int n = 0;
	List* list;
	char chArr[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char ch;
	
	list = CreateList(20);
	puts(strArr[CREATELIST]);
	if(!list){
		puts("createList wrong!");
		return;
	}else {
		puts("createList no nullpointer");
	}
	puts(""); getch();
	
	for(n = 0; arr[n]; n++){
		ListAppend(list, arr[n]);
	}
	
	showResult(list, LISTAPPEND, "perfect world");
	
	ListInsert(list, 1, 'I');
    ListInsert(list, 2, ' ');
    ListInsert(list, 16, '!');
    ListInsert(list, 3, ' ');
    ListInsert(list, 3, 'a');
    ListInsert(list, 2, 'n');
	n = ListInsert(list, 0, '0');
	n = n + ListInsert(list, 25, '0');
	n = n + ListInsert(list, -1, '0');
	
	showResult(list, LISTINSERT, "In a perfect world");
	if(n){
		puts("insert error!");
	}
	
	n = 0;
	
	GetElement(List, 1, &ch); chArr[0] = ch;
	GetElement(List, 19, &ch); chArr[1] = ch;
	n = GetElement(list, 21, &ch);
	
	puts(strArr[GETELEMENT]);
	titleTest printf("%s", chArr);
	titleSystem puts("I!");
	if(n){
		puts("getelement error!");
	}
	puts(""); getch();
	
	
	n = 0;
	ListDelete(list, 11);
	ListDelete(list, 5);
	ListDelete(list, 10);
	ListDelete(list, 6);
	ListDelete(list, 8);
	ListDelete(list, 5);
	ListDelete(list, 13);
	ListDelete(list, 6);
	ListDelete(list, 5);
	
	n = ListDelete(list,0);
    n = n + ListDelete(list, 13);
    n = n + ListDelete(list, -1);
    showResult(list, LISTDELETE, "In a world");
    if(n) puts("list delete error!");
	
	
	ClearList(list);
    showResult(list, CLEARLIST, "");
	
}

void showResult(List* list, int no, char* answer){
	puts(strArr[no]);
	titleTest ShowList(list);
	titleSystem puts(answer);
	puts(""); getch();
}

void ShowList(List* list){
	TraverseList(list, putE);
}

int putE(EleType* e){
	printf("%c", *e);
	return 1;
}























