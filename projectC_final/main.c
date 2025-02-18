#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"


// Khai bao cac ham quan ly sinh vien
void displayMenu();
void displayStudents();
void addStudent();
void EditStudents();
void deleteStudent();
void searchStudent();
void saveToCSV();
void loadFromCsv();
void displaySortMenu();
void sortStudentsAscending();
void sortStudentsDescending();

// Khai bao cac ham quan ly giao vien
void addTeacher();
void displayMenuTeachers();
void displayTeachers();
void deleteTeacher();
void EditTeachers();
void searchTeacher();
void saveToTeacherCSV();
void loadFromTeacherCsv();
void displaySortMenuTeachers();
void sortTeachersAscending();
void sortTeachersDescending();

// Cac ham tien ich
void pressAnyKeyToExit();
int isDuplicateID();
int isValidEmail();
void toLowerCase();
void trimWhitespace();

int main(int argc, char *argv[]) {
    int choice;
    
    do {
        // Hien thi menu chinh
        printf("\n========== MENU ==========");
        printf("\n1. Quan ly sinh vien");
        printf("\n2. Quan ly giao vien");
        printf("\n3. Thoat");
        printf("\nLua chon: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                do {
                    // Hien thi menu quan ly sinh vien
                    displayMenu();
                    scanf("%d", &choice);
                    getchar();
                    switch (choice) {
                        case 1:
                            displayStudents(); // Hien thi danh sach sinh vien
                            break;
                        case 2:
                            addStudent(); // Them sinh vien moi
                            break;
                        case 3:
                            EditStudents(); // Chinh sua thong tin sinh vien
                            break;
                        case 4:
                            deleteStudent(); // Xoa sinh vien
                            break;
                        case 5:
                            searchStudent(); // Tim kiem sinh vien
                            break;
                        case 6:
                            displaySortMenu(); // Hien thi menu sap xep sinh vien
                            break;
                        case 7:
                            saveToCSV(); // Luu danh sach sinh vien vao CSV
                            break;
                        case 8:
                            loadFromCsv(); // Tai danh sach sinh vien tu CSV
                            break;
                        case 9:
                            printf("Tro ve menu chinh.\n"); // Quay lai menu chinh
                            break;
                        default:
                            printf("Lua chon khong hop le, vui long nhap lai.\n");
                    }
                } while (choice != 9);
                break;
            
            case 2:
                do {
                    // Hien thi menu quan ly giao vien
                    displayMenuTeachers();
                    scanf("%d", &choice);
                    getchar();
                    switch (choice) {
                        case 1:
                            displayTeachers(); // Hien thi danh sach giao vien
                            break;
                        case 2:
                            addTeacher(); // Them giao vien moi
                            break;
                        case 3:
                            EditTeachers(); // Chinh sua thong tin giao vien
                            break;
                        case 4:
                            deleteTeacher(); // Xoa giao vien
                            break;
                        case 5:
                            searchTeacher(); // Tim kiem giao vien
                            break;
                        case 6:
                            displaySortMenuTeachers(); // Hien thi menu sap xep giao vien
                            break;
                        case 7:
                            saveToTeacherCSV(); // Luu danh sach giao vien vao CSV
                            break;
                        case 8:
                            loadFromTeacherCsv(); // Tai danh sach giao vien tu CSV
                            break;
                        case 9:
                            printf("Tro ve menu chinh.\n"); // Quay lai menu chinh
                            break;
                        default:
                            printf("Lua chon khong hop le, vui long nhap lai.\n");
                    }
                } while (choice != 9);
                break;
            
            case 3:
                printf("Thoat chuong trinh.\n"); // Ket thuc chuong trinh
                exit(0);
                break;
            
            default:
                printf("Lua chon khong hop le, vui long nhap lai.\n");
        }
    } while (choice != 3);
    
    return 0;
}

