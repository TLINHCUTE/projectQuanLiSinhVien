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
void searchStudent();
void saveToCSV();
void loadFromCsv();
void displaySortMenu();
void sortStudentsAscending();
void sortStudentsDescending();
void pressAnyKeyToExit();
int isDuplicateID();
int isValidEmail();
void toLowerCase();
void trimWhitespace();

int main(int argc, char *argv[]) {
	int choice;
	
    do {
        displayMenu();
        scanf("%d", &choice);
        getchar();
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
            	searchStudent();
            	break;
			case 6:
				displaySortMenu();
				break;
			case 7:
				saveToCSV();
				break;
			case 8:
				loadFromCsv();
				break; 
			case 9: 
                printf("Thoat chuong trinh.\n");
                exit(0);
            default:
                printf("Lua chon khong hop le, vui long nhap lai.\n");
        }
        printf("\n");
    }while(choice != 9);
	return 0;
}
