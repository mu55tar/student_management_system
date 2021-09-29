#include "Design.h"
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include "Linked Stack.h"

void printChar(char ch,int n){
    while(n--)
    {
        putchar(ch);
    }
}

void title(){
    system("cls");
       system("color 6");
    printf("\n\n\t");
    printChar('=',30);
    printf(" Student Management System ");

    printChar('=',30);
    printf("\n");
}

void Wellcom(){

    system("color 6");
    system("cls");//Clear screen
    SetConsoleTitle("Student Management System | DIU");
   printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * ");
		printf("\n\n\t\t\t\t\t     *                     *");
		printf("\n\n\t\t\t\t\t     *       Welcome       *");
		printf("\n\n\t\t\t\t\t     *                     *");
		printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * ");
		printf("\n\n\n\n\n\t\t\t\t\tPress any key to continue...... ");
		getch();

		}

void Menu(){
int number_for_option;
 CreateStack();
system("cls");//Clear screen
    while(1){
        title();
        printf("\n\t");
        printChar('*',64);
        printf("\n\n\t\t\t\t1. Add Student");
        printf("\n\n\t\t\t\t2. Modify Student");
        printf("\n\n\t\t\t\t3. Show All Student");
        printf("\n\n\t\t\t\t4. Search for a student");
        printf("\n\n\t\t\t\t5. Remove Student");
        printf("\n\n\t\t\t\t6. Student Score");
        printf("\n\n\t\t\t\t7. Rank Student");
        printf("\n\n\t\t\t\t8. Logout\n\t");
        printChar('*',64);
        printf("\n\n\t\t\t\tEnter Your Option :--> ");
        scanf("%d",&number_for_option);


        switch(number_for_option)
        {
            case 1:
                Push();

                break;
            case 2:
               change();


                break;
            case 3:
                 DisplayList();

                break;
            case 4:
                SearchList();

                break;
            case 5:
                Delete();

                break;
            case 6:
                Stud_Score();

                break;

                break;
            case 7:
                Rank_Student();

                break;
            case 8:
                return ;
                break;
            default:
                printf("\n\t\tNo Action Detected");
                printf("\n\t\tPress Any Key\n\n\n");
                getch();
                system("pause");
        }

    }
		}
