#include <stdio.h>

#include <stdlib.h>

#include <string>





/// <summary>
/// 이진트리 생성 후 
/// </summary>
typedef struct node

{

    char Name[100];

    node* LChild;

    node* RChild;

} node;

typedef node* Nptr;



#define MAX 100

//스택에 트리의 값을 쌓음
class Stack {

public:

    int Top = -1;

    Nptr Item[MAX];

    void Init() { Top = -1; }

    bool IsEmpty() { return (Top == -1); }

    bool IsFULL() { return (Top == MAX - 1); }

    void Push(Nptr item) { Item[++Top] = item; }

    Nptr Pop() { return Item[Top--]; }



};


//큐에 트리의 값을 추가함
class Queue {

public:

    int front = 0;

    int rear = -1;

    int count = 0;



    Nptr Item[MAX];

    bool IsEmpty() { return (count == 0); }

    bool IsFULL() { return (count == MAX); }

    void Add(Nptr item) { Item[(++rear) % MAX] = item; count++; }

    Nptr Removal() { return Item[(front++) % MAX]; count--; }



};


//전위순회. 뿌리 노드 > 왼쪽 노드> 왼쪽노드.. 막혔을 시 부모노드로 간 후 오른쪽노드
void PreOrder(Nptr T)
{

    if (T != NULL)

    {

        printf("%s\n", T->Name);

        PreOrder(T->LChild);

        PreOrder(T->RChild);

    }

}


//중위순회. (가장 하위의) 왼쪽 노드> 막혔을 시 부모노드 > 오른쪽 자식노드 > 왼쪽노드.. 막혔을 시 다시 부모 노드 후 반복
void InOrder(Nptr T)

{

    if (T != NULL)

    {



        InOrder(T->LChild);

        printf("%s\n", T->Name);

        InOrder(T->RChild);

    }

}


//후위순회. (가장 하위의) 왼쪽 노드> (가장 하위의) 오른쪽 노드 > 부모 > 하위의 노드.... 맨 마지막에 뿌리.
void PostOrder(Nptr T)

{

    if (T != NULL)

    {



        PostOrder(T->LChild);

        PostOrder(T->RChild);

        printf("%s\n", T->Name);

    }

}


//스택을 이용한 전위순회
void IterativePreorder(Nptr p)

{

    Stack S;

    if (p != NULL) {

        S.Push(p);

        while (!S.IsEmpty()) {

            p = S.Pop();

            printf("%s\n", p->Name);

            if (p->RChild != NULL)

                S.Push(p->RChild);

            if (p->LChild != NULL)

                S.Push(p->LChild);

        }

    }



}


//큐를 이용한 전위순회(레벨 순회)
void LevelOrder(Nptr T)

{

    Queue Q;

    Q.Add(T);

    while (!Q.IsEmpty()) {

        Nptr p = Q.Removal();

        printf("%s\n", p->Name);

        if (p->LChild != NULL)

            Q.Add(p->LChild);

        if (p->RChild != NULL)

            Q.Add(p->RChild);

    }

}





int main() {

    Nptr t, p;

    p = (Nptr)malloc(sizeof(node));

    strcpy_s(p->Name, 100, "Park");

    p->LChild = NULL;

    p->RChild = NULL;

    t = p;



    p = (Nptr)malloc(sizeof(node));

    strcpy_s(p->Name, 100, "Kim");

    p->LChild = NULL;

    p->RChild = NULL;

    t->LChild = p;



    p = (Nptr)malloc(sizeof(node));

    strcpy_s(p->Name, 100, "Seo");

    p->LChild = NULL;

    p->RChild = NULL;

    t->RChild = p;



    p = (Nptr)malloc(sizeof(node));

    strcpy_s(p->Name, 100, "Lee");

    p->LChild = NULL;

    p->RChild = NULL;

    t->LChild->RChild = p;



    p = (Nptr)malloc(sizeof(node));

    strcpy_s(p->Name, 100, "Cho");

    p->LChild = NULL;

    p->RChild = NULL;

    t->RChild->RChild = p;





    PreOrder(t);

    printf("\n");



    IterativePreorder(t);

    printf("\n");



    InOrder(t);

    printf("\n");



    PostOrder(t);

    printf("\n");





    LevelOrder(t);

    printf("\n");

    return 0;

}