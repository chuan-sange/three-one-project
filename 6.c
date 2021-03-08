#include "6.h"

typedef int MyElementType;
typedef struct s {
    int a;
    int b;
}stu;

MyElementType sa[4] = { 1,2,4,5 };
void showlist(List*);
int putelement(stu*);

main() {
    List* lp;
    int n;
    MyElementType a = 0;
    char b = 'c';
    stu c = { 7,8 };

    lp = CreatList(sizeof(MyElementType));
    if (!lp) {
        printf("Creat?\n");
        return;
    }

    for (n = 0; n < 4; n++) {
        ListAppend(lp, &(sa[n]), sizeof(MyElementType));
    }
    showlist(lp);

    ListInsert(lp, 1, &a, sizeof(a));/* int */
    showlist(lp);
    ListInsert(lp, 4, &b, sizeof(b));/* char */
    showlist(lp);

    ListInsert(lp, 7, &c, sizeof(stu));/* stu */
    showlist(lp);

    ListDelet(lp, 1);
    showlist(lp);
    ListDelet(lp, 3);
    showlist(lp);
}

void showlist(List* lp) {
    TraverseList(lp, (int (*)(void*))putelement);
    printf("\n");
}

int putelement(stu* element) {/* 自定义数据类型输出 */
    printf("%d %d", element->a, element->b);
    return 1;
}

