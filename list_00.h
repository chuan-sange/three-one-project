typedef char EleType;

typedef struct {
	EleType* buf;
	unsigned int n;
	unsigned int max;
}List;


List* CreateList(int max);

void DestroyList(List* lp);

void ClearList(List* lp);

int ListAppend(List* lp, EleType data);

int ListInsert(List* lp, int pos, EleType data);

int ListDelete(List* lp, int pos);

int GetElement(List* lp, int pos, EleType* data);

int IsEmpty(List* lp);

int IsFull(List* lp);

int TraverseList(List* lp, int(*f)(EleType*));



List* CreateList(int max){
	List* lp;
	
	lp = (List*)malloc(sizeof(List));
	if(!lp){
		return 0;
	}
	
	lp->n = 0;
	lp->max = max;
	lp->buf = (EleType*)malloc(sizeof(EleType)*lp->max);
	if(!lp->buf){
		free(lp);
		return 0;
	}
	
	return lp;
}

void DestroyList(List* lp){
	if(lp->buf){
		free(lp->buf);
	}
	free(lp);
}

void ClearList(List* lp){
	lp->n = 0;
}

int ListAppend(List* lp, EleType data){
	if(lp->n >= lp->max){
		EleType* newbuf = (EleType*)malloc(sizeof(EleType)*lp->max*2);
		if(!newbuf){
			return 0;
		}
		
		memcpy(newbuf, lp->buf, sizeof(EleType)*lp->max);
		free(lp->buf);
		
		lp->buf = newbuf;
		lp->max= lp->max*2;
	}
	
	lp->buf[lp->n] = data;
	lp->n++;
	return 1;
}

int ListInsert(List* lp, int pos, EleType data){
	int i;
	
	if(pos <= 0 || pos > lp->max){
		return 0;
	}
	
	if(lp->n >= lp->max){
		EleType* newbuf = (EleType*)malloc(sizeof(EleType)*lp->max*2);
		if(!newbuf){
			return 0;
		}
		
		memcpy(newbuf, lp->buf, sizeof(EleType)*lp->max);
		free(lp->buf);
		
		lp->buf = newbuf;
		lp->max= lp->max*2;
	}
	
	for(i = lp->n; i >= pos; i--){
		lp->buf[i] = lp->buf[i - 1];
	}
	lp->buf[pos - 1] = data;
	lp->n++;
	return 1;
}

int ListDelete(List* lp, int pos){
	int i;
	
	if(pos <= 0 || pos > lp->max){
		return 0;
	}	
	
	for(i = pos - 1; i < lp->n; i++){
		lp->buf[i] = lp->buf[i + 1];
	}
	lp->n--;
	return 1;
}

int GetElement(List* lp, int pos, EleType* data){
	if(pos <= 0 || pos > lp->max){
		return 0;
	}
	*data = lp->buf[pos - 1];
	return 1;
}

int IsEmpty(List* lp){
	return lp->n == 0 ? 1 : 0;
}

int IsFull(List* lp){
	return lp->n == lp->max ? 1 : 0;
}

int TraverseList(List* lp, int(*f)(EleType*)){
	int i;
	
	for(i = 0; i < lp->n; i++){
		if(!f(&(lp->buf[i]))){
			return i + 1;
		}
	}	
	
	return 0;
}



























