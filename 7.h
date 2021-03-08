typedef void* EleType;

typedef struct node {
    EleType data;
    struct node* next;
	int size;
}ChainNode;


typedef struct {
    ChainNode* head;
}List;



List* CreateList();

void ClearList(List* lp);

void DestroyList(List* lp);

int ListAppend(List* lp, EleType data, int size);

int ListInsert(List* lp, int n, EleType data, int size);

int ListDelete(List* lp, int n);

ChainNode* GetAddr(List* lp, int n);

int GetElement(List* lp, int n, EleType* data);

/*int TraverseList(List* lp, int(*f)(EleType*));*/
int TraverseList(List *, int (*)(EleType));

ChainNode* NewChainNode(EleType data, int size);



List* CreateList() {
    List* lp;
    EleType* data = 0;

    lp = (List*)malloc(sizeof(List));
    if (!lp) {
        return 0;
    }

    lp->head = NewChainNode(*data, 0);
    if (!lp->head) {
        free(lp);
        return 0;
    }

    return lp;
}

void ClearList(List* lp) {
    while (ListDelete(lp, 1));
}

void DestroyList(List* lp) {
    ClearList(lp);
    free(lp->head);
    free(lp);
}

int ListAppend(List* lp, EleType data, int size) {
    ChainNode* p;
    ChainNode* newp;
	EleType ele;

	ele = (void*)malloc(sizeof(EleType));
	if(!ele){
		return 0;
	}
	memcpy(ele, data, sizeof(EleType));
	
    newp = NewChainNode(ele, size);
    if (!newp) {
        return 0;
    }
	
    for (p = lp->head; p->next; p = p->next);

    p->next = newp;

    return 1;
}

int ListInsert(List* lp, int n, EleType data, int size) {
    ChainNode* p;
    ChainNode* newp;
	EleType ele;
	
    p = GetAddr(lp, n - 1);
    if (!p) {
        return 0;
    }
	
	ele = (void*)malloc(sizeof(EleType));
	
	if(!ele){
		return 0;
	}
	memcpy(ele, data, sizeof(EleType));
	
    newp = NewChainNode(ele, size);
    if (!newp) {
        return 0;
    }

    newp->next = p->next;
    p->next = newp;

    return 1;
}

int ListDelete(List* lp, int n) {
    ChainNode* p;
    ChainNode* p1;

    if (!lp->head->next) {
        return 0;
    }

    p = GetAddr(lp, n - 1);
    if (!(p && p->next)) {
        return 0;
    }

    p1 = p->next;
    p->next = p->next->next;
    free(p1);

    return 1;
}

ChainNode* GetAddr(List* lp, int n) {
    ChainNode* p;
    int i;

    if (n < 0) {
        return 0;
    }

    p = lp->head;
    i = 0;

    while (i < n && p->next) {
        p = p->next;
        i++;
    }

    return p;
}

int GetElement(List* lp, int n, EleType* data) {
    ChainNode* p;

    p = GetAddr(lp, n);
    if (!p) {
        return 0;
    }

	memcpy(data, p->data, sizeof(EleType));

    return 1;
}

/*
int TraverseList(List* lp, int(*f)(EleType*)) {
    ChainNode* p;
    int i = 0;

    for (p = lp->head->next; p; p = p->next) {
        if (!f(&(p->data))) {
            return i + 1;
        }
		i++;
    }

    return 0;
}
*/

int TraverseList(List *lp, int (*f)(EleType)) {
    ChainNode *p;

    int a = 0;
    for (p = lp->head->next; p; p = p->next) {
        /* 通用数据类型 */
        if(p->size == sizeof(int)) {
            printf("%d", *(int *)(p->data));
        } else if (p->size == sizeof(char)){
            printf("%c", *(char*)(p->data));
        } else {
            if(!f(p->data)) /* 自定义数据类型 */
            return a + 1;
        }
        a++;
    }
    return 0;
}


ChainNode* NewChainNode(EleType data, int size) {
    ChainNode* p;

    p = (ChainNode*)malloc(sizeof(ChainNode));
    if (!p) {
        return 0;
    }
	
    p->data = data;
	p->size = size;
	p->next = 0;

    return p;
}


