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
void searchStudentByName();
void saveToCSV();
void displaySortMenu();
void sortStudentsAscending();
void sortStudentsDescending();
void pressAnyKeyToExit();

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
            	searchStudentByName();
            	break;
			case 6:
				displaySortMenu();
				break;
			case 7:
				saveToCSV();
				break;
			case 8: 
                printf("Thoat chuong trinh.\n");
                exit(0);
            default:
                printf("Lua chon khong hop le, vui long nhap lai.\n");
        }
        printf("\n");
    }while(choice != 8);
	return 0;
}
