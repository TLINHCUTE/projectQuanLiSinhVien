#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"
#include "function.h"
 
void displayMenu();
void displayStudents();
void addStudent();
void EditStudents() ;
void deleteStudent();
void saveToFile();
void loadFromFile();
void displayAddStudentMenu();
void displayEditStudentMenu();
void displayDeleteStudentMenu();
int main(int argc, char *argv[]) {
	int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayStudents();
                break;
            case 2:
                addStudent();
                break;
            case 3:
            	EditStudents();
            	break;
            case 4:
            	deleteStudent();
            	break;
            case 5:
                printf("Thoat chuong trinh.\n");
                exit(0);
            default:
                printf("Lua chon khong hop le, vui long nhap lai.\n");
        }
        printf("\n");
    }while(choice != 5);
	return 0;
}
