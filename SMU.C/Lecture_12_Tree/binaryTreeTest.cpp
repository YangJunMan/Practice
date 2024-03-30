#include <stdio.h>

#include <stdlib.h>

#include <string>


/// <summary>
/// 트리 구조체와 포인터를 이용해 이진트리 생성
/// </summary>
typedef struct node

{

    char Name[100];



    node* LChild;

    node* RChild;



} node;



typedef node* Nptr;



int main() {



    Nptr t, p;

    //루트 생성

    p = (Nptr)malloc(sizeof(node));

    //카피!
    strcpy_s(p->Name, 100, "Park");



    p->LChild = NULL;

    p->RChild = NULL;



    t = p;



    //좌.에 생성

    p = (Nptr)malloc(sizeof(node));

    strcpy_s(p->Name, 100, "Kim");



    p->LChild = NULL;

    p->RChild = NULL;



    t->LChild = p;



    //우.에 생성

    p = (Nptr)malloc(sizeof(node));

    strcpy_s(p->Name, 100, "Seo");

    p->LChild = NULL;

    p->RChild = NULL;



    t->RChild = p;





    //좌. 좌. 에 생성

    p = (Nptr)malloc(sizeof(node));

    strcpy_s(p->Name, 100, "Ko");



    p->LChild = NULL;

    p->RChild = NULL;



    t->LChild->LChild = p;





    //좌. 우. 에 생성

    p = (Nptr)malloc(sizeof(node));

    strcpy_s(p->Name, 100, "Lee");



    p->LChild = NULL;

    p->RChild = NULL;



    t->LChild->RChild = p;





    //우. 좌. 에 생성

    p = (Nptr)malloc(sizeof(node));

    strcpy_s(p->Name, 100, "Min");



    p->LChild = NULL;

    p->RChild = NULL;



    t->RChild->LChild = p;





    //우. 우. 에 생성

    p = (Nptr)malloc(sizeof(node));

    strcpy_s(p->Name, 100, "Cho");



    p->LChild = NULL;

    p->RChild = NULL;



    t->RChild->RChild = p;






    
    printf("좌좌 : %s \n", t->LChild->LChild->Name);

    printf("좌우 : %s \n", t->LChild->RChild->Name);

    printf("우좌 : %s \n", t->RChild->LChild->Name);

    printf("우우 : %s \n", t->RChild->RChild->Name);













    return 0;







}