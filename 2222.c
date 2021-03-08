#include "2222.h"
typedef struct student {
    int number;
    int math;
    int c;
    int java;
} stu;
typedef stu MyElementType;
MyElementType sa[4] = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4};
void showlist(List *);
int putelement(MyElementType *);

main() {
    List *lp;
    int n;
    stu a = {5, 5, 5, 5};
    stu b = {8, 8, 8, 8};

    lp = CreatList(sizeof(MyElementType));
    if (!lp) {
        printf("Creat?\n");
        return;
    }

    for (n = 0; n < 4; n++) {
        ListAppend(lp, &(sa[n]));
    }
    showlist(lp);

    ListInsert(lp, 1, &a);
    showlist(lp);
    ListInsert(lp, 4, &b);
    showlist(lp);

    ListDelet(lp, 1);
    showlist(lp);
    ListDelet(lp, 3);
    showlist(lp);
}

void showlist(List *lp) {
    TraverseList(lp, (int (*)(void *))putelement);
    printf("\n");
}

int putelement(MyElementType *element) {
    printf("%d %d %d %d -- ", element->number, element->math, element->c,
           element->java);
    return 1;
}