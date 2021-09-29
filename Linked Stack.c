#include "Linked Stack.h"
#include <stdlib.h>
#include <stdio.h>
#include<windows.h>
#include<math.h>
#include "Design.h"

Stack S;



void CreateStack(){
    Stack *ps=&S;
ps->top=NULL;
ps->size=1;
}

void ClearStack(){
        Stack *ps=&S;

    StackNode *pn=ps->top;
    while(pn){
        pn=pn->next;
        free(ps->top);
        ps->top=pn;
    }
}

void Push (){

    Stack *ps=&S;
    struct Entry entry;
    char another='y';
    while(another=='y'|| another=='Y'){

    title();
    printf("\n\n\t******************** Enter Student Details: ***********************\n\n");

    StackNode *pn=(StackNode*)malloc(sizeof(StackNode));
    pn->entry.id=ps->size;


    printf("\n\t Enter Student Name : ");
    fflush(stdin);
    scanf( "%[^\n]",&pn->entry.name);
    fflush(stdin);
    strcpy(entry.name,pn->entry.name);


    printf("\n\t Enter Student Phone Number : ");
    fflush(stdin);
    scanf( "%[^\n]",&pn->entry.phone);
    fflush(stdin);
    strcpy(entry.phone,pn->entry.phone);


    printf("\n\t Enter Address : ");
    fflush(stdin);
    scanf( "%[^\n]",&pn->entry.address);
    fflush(stdin);
    strcpy(entry.address,pn->entry.address);


    printf("\n\t Enter Date of Birth : ");
    printf("\n\tDay ");
    scanf("%d",&pn->entry.day_of_birth);
    printf("\n\tMonth ");
    scanf("%d",&pn->entry.month_of_birth);
    printf("\n\tYear ");
    scanf("%d",&pn->entry.year_of_birth);


 if(ps->top!=NULL){
    pn->next=ps->top;
    ps->top->prev=pn;
    pn->prev=NULL;
    ps->top=pn;
    }
    else{
        pn->next=ps->top;
        ps->top=pn;
        ps->top->prev=NULL;

    }ps->size++;

    printf("\n\n\t\tAdd another student?(Y/N)?");
    fflush(stdin);
    another=getchar();
    }
}

void Delete(){

  Stack *ps=&S;
  char another='y';
  while(another=='y'|| another=='Y'){
  StackNode *tmpp1=ps->top;

 title();
 printf("\n\n\t\t\t************* Delete Information Students **************\n");
 printf("\n\n\t\t\t\t Find students by :");
 printf("\n\n\t1.ID\t\t2.Name\t\t3.Phone Number\n\n");
 printChar('*',64);
 printf("\n\n\t\t\t\t Enter Your Option ---> ");

int choise_option;
scanf("%d",&choise_option);
fflush(stdin);

switch(choise_option){

    case 1:{

     printf("\n\n\n\tEnter the student ID to be deleted :");
     int key;
     scanf("%d",&key);

     while(tmpp1!=NULL){

		if(tmpp1->entry.id==key){

			printf("\n\nStudent with ID number %d Found !!!\n", key);
			if(tmpp1->next==NULL&&tmpp1->prev==NULL){
                free(tmpp1);
                printf("\n\n\t\t\t\t No elements\n\n");
			}
            else
                {
			tmpp1->prev->next=tmpp1->next;
			tmpp1->next->prev=tmpp1->prev;
			free(tmpp1);
            }
			printf("\n\nStudent Successfully Deleted !!!\n");
			  break;

		}

		tmpp1 = tmpp1->next;

	}printf("\n\n\t\t\t\t No elements\n\n");

break;
}

case 2:{
printf("\n\n\n\tEnter the student Name to be deleted :");
char Name[50];
fflush(stdin);
scanf("%[^\n]",&Name);
fflush(stdin);


  while(tmpp1!=NULL){

		if(strcmp(tmpp1->entry.name,Name)==0){

			printf("\n\nStudent with Name %s Found !!!\n", Name);
			if(tmpp1->next==NULL&&tmpp1->prev==NULL){
                free(tmpp1);
               printf("\n\n\t\t\t\t No elements\n\n");
                }
            else{

		tmpp1->prev->next=tmpp1->next;
			tmpp1->next->prev=tmpp1->prev;
			free(tmpp1);
            }

			printf("\n\nStudent Successfully Deleted !!!\n");
			break;
		}

		tmpp1 = tmpp1->next;



	}
printf("\n\nStudent with Name %s is not found !!!\n", Name);


break;
}

case 3:{

printf("\n\n\n\tEnter the student Phone Number to be deleted :");
char Phone_number[11];
fflush(stdin);
scanf("%[^\n]",&Phone_number);
fflush(stdin);


  while(tmpp1!=NULL){

		if(strcmp(tmpp1->entry.phone,Phone_number)==0){

			printf("\n\nStudent with Phone Number %s Found !!!\n", Phone_number);
			if(tmpp1->next==NULL&&tmpp1->prev==NULL)
                free(tmpp1);
               // printf("\n\n\t\t\t\t No elements\n\n");

            else{

		tmpp1->prev->next=tmpp1->next;
			tmpp1->next->prev=tmpp1->prev;
			free(tmpp1);
            }

			printf("\n\nStudent Successfully Deleted !!!\n");
			break;
		}
		tmpp1 = tmpp1->next;



	}
printf("\n\nStudent with Phone Number %s is not found !!!\n", Phone_number);


break;
}


}
printf("\n\n\t\tDelete another student?(Y/N)?");
    fflush(stdin);
    another=getchar();
}

   }



void DisplayList(){

  Stack *ps=&S;
  title();
  StackNode *pn;
  pn=ps->top;


     if(pn == NULL){
        printf("\n\n\n\t\t\t\tList is empty\n\n\n");

    }else

    {
    Sort();
    printf("\n\n\t\t************* Details of Students: **************\n");
    printf("\n__________________________________________________________________________________________________\n");
    while(pn != NULL) {
        //Prints each node by incrementing pointer
        printf("\n\tID = %d\n\n\tName = %s\n\n\tPhone = %s\n\n\tAddress = %s\n\n\tDate Of Birth = %d / %d / %d",
        pn->entry.id,pn->entry.name,pn->entry.phone,pn->entry.address,pn->entry.day_of_birth,pn->entry.month_of_birth,pn->entry.year_of_birth);
        printf("\n__________________________________________________________________________________________________\n");

        pn=pn->next;
    }


    }
    printf("\n\n\t Press any key to go to the main menu: ");
    getch();
}



void change(){
    Stack *ps=&S;
    StackNode * pn=ps->top;
    char another='y';
    while(another=='y'|| another=='Y'){
    title();
 printf("\n\n\t\t************* Edit Students Information **************\n");
 printf("\n\n\t\t\t\t Find students by :");
 printf("\n\n\t1.ID\t\t2.Name\t\t3.Phone Number\n\n");

 printChar('*',64);
 printf("\n\n\t\t\t\t Enter Your Option ---> ");
 int n;
 scanf("%d",&n);
 fflush(stdin);
 switch(n){

  case 1:{
 printf ("\n\n\tPlease Enter Student ID:");
 int key;
 scanf("%d",&key);

 while(pn!=NULL){
 if(pn->entry.id==key){
    printf ("\n\nEnter Student new Name : ");
//char new_name[50];
  fflush(stdin);
  scanf("%[^\n]",&pn->entry.name);
  strcpy(pn->entry.name,pn->entry.name);

  printf ("\n\nEnter Student new phone : ");
  //char phone[11];
  fflush(stdin);
  scanf("%[^\n]",&pn->entry.phone);
  strcpy(pn->entry.phone,pn->entry.phone);

   printf ("\n\nEnter Student new Address : ");
//char new_name[50];
  fflush(stdin);
  scanf("%[^\n]",&pn->entry.address);
  strcpy(pn->entry.address,pn->entry.address);

  printf ("\n\nEnter Student new Date of Birth : ");
  //char phone[11];
  fflush(stdin);
  printf("\n\tDay ");
  scanf("%d",&pn->entry.day_of_birth);
   printf("\n\tMonth ");
  scanf("%d",&pn->entry.month_of_birth);
   printf("\n\tYear ");
  scanf("%d",&pn->entry.year_of_birth);


  printf ("\n\n\t\tSuccessful modification\n\n");

  break;
 }
 pn=pn->next;
 }
//printf ("\n\n\t\tStudent not Found !!\n\n");

 break;
 }


  case 2:{
 printf ("\n\n\tPlease Enter Student Name:");
 char nam[50];
   fflush(stdin);

 scanf("%[^\n]",&nam);
    fflush(stdin);

 while(pn!=NULL){
 if(strcmp(pn->entry.name,nam)==0){
   printf ("\n\nEnter Student new Name : ");
//char new_name[50];
  fflush(stdin);
  scanf("%[^\n]",&pn->entry.name);
  strcpy(pn->entry.name,pn->entry.name);

  printf ("\n\nEnter Student new phone : ");
  //char phone[11];
  fflush(stdin);
  scanf("%[^\n]",&pn->entry.phone);
  strcpy(pn->entry.phone,pn->entry.phone);

   printf ("\n\nEnter Student new Address : ");
//char new_name[50];
  fflush(stdin);
  scanf("%[^\n]",&pn->entry.address);
  strcpy(pn->entry.address,pn->entry.address);

  printf ("\n\nEnter Student new Date of Birth : ");
  //char phone[11];
  fflush(stdin);
  printf("\n\tDay ");
  scanf("%d",&pn->entry.day_of_birth);
   printf("\n\tMonth ");
  scanf("%d",&pn->entry.month_of_birth);
   printf("\n\tYear ");
  scanf("%d",&pn->entry.year_of_birth);


  printf ("\n\n\t\tSuccessful modification\n\n");

  break;
 }
 pn=pn->next;
 }
//printf ("\n\n\t\tStudent not Found !!\n\n");

 break;
 }


 case 3:{
 printf ("\n\n\tPlease Enter Student Phone Number:");
 char Phone_Number[11];
   fflush(stdin);

 scanf("%[^\n]",&Phone_Number);

 while(pn!=NULL){
 if(strcmp(pn->entry.phone,Phone_Number)==0){
   printf ("\n\nEnter Student new Name : ");
//char new_name[50];
  fflush(stdin);
  scanf("%[^\n]",&pn->entry.name);
  strcpy(pn->entry.name,pn->entry.name);

  printf ("\n\nEnter Student new phone : ");
  //char phone[11];
  fflush(stdin);
  scanf("%[^\n]",&pn->entry.phone);
  strcpy(pn->entry.phone,pn->entry.phone);

   printf ("\n\nEnter Student new Address : ");
//char new_name[50];
  fflush(stdin);
  scanf("%[^\n]",&pn->entry.address);
  strcpy(pn->entry.address,pn->entry.address);

  printf ("\n\nEnter Student new Date of Birth : ");
  //char phone[11];
  fflush(stdin);
  printf("\n\tDay ");
  scanf("%d",&pn->entry.day_of_birth);
   printf("\n\tMonth ");
  scanf("%d",&pn->entry.month_of_birth);
   printf("\n\tYear ");
  scanf("%d",&pn->entry.year_of_birth);


  printf ("\n\n\t\tSuccessful modification\n\n");

  break;
 }
 pn=pn->next;
 }
//printf ("\n\n\t\tStudent not Found !!\n\n");

 break;
 }
 }
fflush(stdin);
 printf("\n\n\t\tUpdate another student?(Y/N)?");
fflush(stdin);
another=getchar();
}
}




void Stud_Score(){
    struct Entry entry;

Stack *ps=&S;
    StackNode * pn=ps->top;
    char another='y';
    while(another=='y'|| another=='Y'){
    title();
 printf("\n\n\t\t************* Record score Students  **************\n");
 printf("\n\n\t\t\t\t Find students by :");
 printf("\n\n\t1.ID\t\t2.Name\t\t3.Phone Number\n\n");

 printChar('*',64);
 printf("\n\n\t\t\t\t Enter Your Option ---> ");
 int n;
 scanf("%d",&n);
 fflush(stdin);
 switch(n){

  case 1:{
 printf ("\n\n\tPlease Enter Student ID:");
 int key;
 scanf("%d",&key);
 fflush(stdin);

 while(pn!=NULL){
 if(pn->entry.id==key){
   printf ("\n\nEnter Name Of Course : ");
  fflush(stdin);
  scanf("%[^\n]",&pn->entry._Course.course_Name);
  strcpy(entry._Course.course_Name,pn->entry._Course.course_Name);

  printf ("\n\nEnter Student Score : ");
  scanf("%f",&pn->entry._Course.course_Score);
  printf ("\n\n\t\tSuccessful Record\n\n");

  break;
 }//else{printf ("\n\n\t\tStudent not Found !!\n\n");}
 pn=pn->next;
 }
//printf ("\n\n\t\tStudent not Found !!\n\n");

 break;
 }


  case 2:{
 printf ("\n\n\tEnter Student Name : ");
 char nam[50];
fflush(stdin);
scanf("%[^\n]",&nam);
strcpy(entry.name,nam);

fflush(stdin);

 while(pn!=NULL){

 if(strcmp(pn->entry.name,nam)==0){

  printf ("\n\nEnter Name Of Course : ");
  fflush(stdin);
  scanf("%[^\n]",&pn->entry._Course.course_Name);
  strcpy(entry._Course.course_Name,pn->entry._Course.course_Name);

  printf ("\n\nEnter Student Score : ");
  scanf("%f",&pn->entry._Course.course_Score);
  printf ("\n\n\t\tSuccessful Record\n\n");

  break;
 }
 pn=pn->next;
  }

 break;
 }


 case 3:{
 printf ("\n\n\tEnter Student Phone Number:");
 char Phone_Number[11];
fflush(stdin);
scanf("%[^\n]",&Phone_Number);
fflush(stdin);
strcpy(entry.phone,Phone_Number);

 while(pn!=NULL){
 if(strcmp(pn->entry.phone,Phone_Number)==0){

  printf ("\n\nEnter Name Of Course : ");
  fflush(stdin);
  scanf("%[^\n]",&pn->entry._Course.course_Name);
  strcpy(entry._Course.course_Name,pn->entry._Course.course_Name);

  printf ("\n\nEnter Student Score : ");
  scanf("%f",&pn->entry._Course.course_Score);
  printf ("\n\n\t\tSuccessful Record\n\n");

  break;
 }
 pn=pn->next;
 }
//printf ("\n\n\t\tStudent not Found !!\n\n");

 break;
 }
 }
fflush(stdin);
 printf("\n\n\t\tRegister another student?(Y/N)?");
fflush(stdin);
another=getchar();
}

}



void Rank_Student(){
     Stack *ps=&S;
  title();
  StackNode *pn=ps->top;



     if(pn == NULL){
        printf("\n\n\n\t\t\t\tList is empty\n\n\n");

    }else

    {
    Sort_score();
    printf("\n\n\t\t************* Students' Ranking: **************\n");
    printf("\n__________________________________________________________________________________________________\n");
    while(pn!=NULL) {
        //Prints each node by incrementing pointer
        printf("\n\tID = %d\t\tName = %s\t\tCourse = %s\t\tGPA= %f ",
        pn->entry.id,pn->entry.name,pn->entry._Course.course_Name,pn->entry._Course.course_Score);
        printf("\n__________________________________________________________________________________________________\n");

        pn=pn->next;
    }


    }
    printf("\n\n\t Press any key to go to the main menu: ");
    getch();
}







void Sort_score(){

    Stack *ps=&S;
    StackNode *ptr, *ptr2;
    struct Entry entry;

    for (ptr= ps->top; ptr->next!= NULL; ptr= ptr->next)
    {

        for (ptr2= ptr->next; ptr2!= NULL; ptr2= ptr2->next)
        {

            if (ptr->entry._Course.course_Score > ptr2->entry._Course.course_Score )
            {
                entry=ptr2->entry;
                ptr2->entry=ptr->entry;
                ptr->entry=entry;
            }//else
            //printf("\n\n\t list is sorted ");
}
}
  printf("\n\n\t list is sorted ");

}
void SearchList(){
    title();
    Stack*ps=&S;
    int key;
    printf("\n\n\t\tEnter ID:");
    scanf("%d",&key);
    fflush(stdin);
    StackNode *pn;
    pn=ps->top;


  // Iterate till last element until key is not found
    while(pn!= NULL && pn->entry.id!=key){

        pn = pn->next;
    }
     if(pn != NULL) {
            printf("\n\tID = %d\n\n\tName = %s\n\n\tPhone = %s\n\n\tAddress = %s\n\n\tDate Of Birth = %d / %d / %d",
        pn->entry.id,pn->entry.name,pn->entry.phone,pn->entry.address,pn->entry.day_of_birth,pn->entry.month_of_birth,pn->entry.year_of_birth);}
     else printf("This key is not found");
      printf("\n\n\t Press any key to go to the main menu: ");
    getch();
}
void Sort(){

    Stack *ps=&S;
    StackNode *ptr, *ptr2;
    struct Entry entry;

    for (ptr= ps->top; ptr->next!= NULL; ptr= ptr->next)
    {

        for (ptr2= ptr->next; ptr2!= NULL; ptr2= ptr2->next)
        {

            if (strcmp(ptr->entry.name, ptr2->entry.name) > 0)
            {
                entry=ptr2->entry;
                ptr2->entry=ptr->entry;
                ptr->entry=entry;
            }//else
            //printf("\n\n\t list is sorted ");
}
}
  printf("\n\n\t list is sorted ");

}






/* ******************* Modify Student Information**********************************************************************/
