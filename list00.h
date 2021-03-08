typedef char EleType;

typedef struct node {
   EleType data;
   struct node * next;
}ChainNode;

typedef struct {
   ChainNode * head;
}List;

List* CreateList(void);

void DestroyList(List*);

void ClearList(List*);

int ListInsert(List*, int, EleType); 

int ListDelete(List*, int);

int ListAppend(List*, EleType);

int TraverseList(List*, int (*)(EleType *));

int GetElement(List*, int, EleType*);

ChainNode* newChainNode(EleType);

ChainNode* GetAddr(List*, int);


List* CreateList(void){
	List* lp;
	EleType* data = 0;
	
	lp = (List*)malloc(sizeof(List));
	if(!lp){
		return 0;
	}
	
	lp->head = newChainNode(*data);
	if(!lp->head){
		free(lp);
		return 0;
	}
	
	return lp;
}

void DestroyList(List* lp){
	ClearList(lp);
	free(lp->head);
	free(lp);
}

void ClearList(List* lp){
	while(ListDelete(lp, 1));
}

int ListInsert(List* lp, int n, EleType data);{
	ChainNode* p;
	ChainNode* newp;
	
	p = GetAddr(lp, n-1);
	if(!p){
		return 0;
	}
	
	newp = newChainNode(data);
	if(!newp){
		return 0;
	}
	
	newp->next = p->next;
	p->next = newp;
	
	return 1;
}

int ListDelete(List* lp, int n){
	ChainNode* p;
	ChainNode* p1;
	
	p = GetAddr(lp, n-1);
	if(!(p && p->next)){
		return 0;
	}
	
	p1 = p->next;
	p->next = p->next->next;
	free(p1);
	
	return 1;
}

int ListAppend(List* lp, EleType data){
	ChainNode* p;
	ChainNode* newp;
	
	newp = newChainNode(data);
	if(!newp){
		return 0;
	}
	
	for(p = lp->head; p->next; p = p->next);
	
	p->next = newp;
	
	return 1;
}

int TraverseList(List* lp, int (*f)(EleType *)){
	ChainNode* p;
	int i;
	
	i = 0;
	for(p = lp->head->next; p; p = p->next){
		if(!f(&(p->data))){
			return i + 1;
		}
		i++;
	}
	
	return 0;
}

int GetElement(List* lp, int n, EleType* data){
	ChainNode* p;
	
	p = GetAddr(lp, n);
	if(!p){
		return 0;
	}
	
	*data = p->data;
	
	return 1;
}

ChainNode* newChainNode(EleType data){
	ChainNode* p;
	
	p = (ChainNode*)malloc(sizeof(ChainNode));
	if(!p){
		return 0;
	}
	
	p->data = data;
	p->next = 0;
	
	return p;
}

ChainNode* GetAddr(List* lp, int n){
	ChainNode* p;
	int i;
	
	i = 0;
	p = lp->head;
	while(i < n && p){
		p = p->next;
		i++;
	}
	
	return p;
}






























