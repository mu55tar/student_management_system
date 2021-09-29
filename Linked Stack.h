#ifndef LINKED_STACK_H_INCLUDED
#define LINKED_STACK_H_INCLUDED
//#define STACKEntry struct
typedef struct Courses{
int course_ID;
char course_Name[20];
float course_Score;
}courses;

typedef struct stacknode{
  struct Entry{
  int id;
  char name[100];
  char phone[20];
  char address[100];
  int day_of_birth;
  int month_of_birth;
  int year_of_birth;
  courses _Course;
  }entry;
  struct stacknode *next;
  struct stacknode *prev;

}StackNode;

typedef struct stack{
StackNode *top;
int size;
}Stack;

void CreateStack();
void ClearStack();
void Push ();
void change();
void Delete();
void DisplayList();
void Stud_Score();
void Rank_Student();

void Sort_score();
void SearchList();
void Sort();





/*
void Pop (struct Entry *,Stack *);
void StackTop (struct Entry,Stack *);
int StackEmpty();
int StackFull();
int StackSize();
void Insert(int , struct Entry , Stack *);

void sortlist();
void swapNodes();
*/









#endif // LINKED_STACK_H_INCLUDED
