// noi trien khai cac ham
#include <stdio.h>   // Thu vien nhap xuat co ban (printf, scanf, fgets,...)
#include <stdlib.h>  // Thu vien chua cac ham quan ly bo nho, chuyen doi kieu,...
#include <stdbool.h> // Thu vien ho tro kieu du lieu boolean (true/false)
#include <string.h>  // Thu vien ho tro xu ly chuoi (fgets, strcspn,...)
#define MAX_STUDENTS 100 // Dinh nghia so luong sinh vien toi da trong danh sach
#include "datatype.h"  // Gom dinh nghia struct `Student` (gia su la nhu vay)
#include "function.h"   // Gom khai bao cac ham nhu `displayMenu`, `displayStudents`, `addStudent`,...

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

Student students[MAX_STUDENTS];  // Mang luu danh sach sinh vien
int studentCount = 0;            // Bien dem so luong sinh vien hien co trong danh sach

void addStudent() {
	system("cls");
    if (studentCount >= MAX_STUDENTS) {  // Kiem tra neu danh sach da day
        printf("Khong the them sinh vien, danh sach da day.\n");
        return;
    }
    Student newStudent;  // Tao mot sinh vien moi de nhap thong tin
    printf("Nhap ID: ");
    scanf("%d", &newStudent.id);
    printf("Nhap ten: ");
    getchar();  // Loai bo ky tu '\n' con sot lai trong bo dem nhap
    fgets(newStudent.name, sizeof(newStudent.name), stdin);  
    newStudent.name[strcspn(newStudent.name, "\n")] = 0; // Xoa ky tu xuong dong '\n'

    printf("Nhap tuoi: ");
    scanf("%d", &newStudent.age);  

    printf("Nhap nganh hoc: ");
    getchar();  
    fgets(newStudent.major, sizeof(newStudent.major), stdin); 
    newStudent.major[strcspn(newStudent.major, "\n")] = 0; 
    
    students[studentCount++] = newStudent;  
    printf("Them sinh vien thanh cong!\n");
    pressAnyKeyToExit();
}

void displayMenu() {
	system("cls");
    printf("===============================\n");
    printf("%5sQUAN LY SINH VIEN\n", "");  
    printf("===============================\n");
    printf("1. Hien thi danh sach sinh vien\n");
    printf("2. Them sinh vien\n");
    printf("3. Sua thong tin sinh vien\n");
    printf("4. Xoa sinh vien\n");
    printf("5. Tim kiem sinh vien\n"); 
    printf("6. Sap xep danh sach sinh vien\n");
    printf("7. Luu danh sach vao file CSV\n"); 
    printf("8. Thoat\n");
    printf("Nhap lua chon: ");
}

void displayStudents() {
	system("cls");
    if (studentCount == 0) {
        printf("Danh sach sinh vien trong!\n");
        return;
    }
	printf("-------------------------------------------------------------\n");
    printf("| %-7s | %-20s | %-5s | %-16s |\n", "ID", "Ten", "Tuoi", "Nganh hoc");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        printf("| %-7d | %-20s | %-5d | %-16s |\n", 
               students[i].id, students[i].name, students[i].age, students[i].major);
    }
    pressAnyKeyToExit();
}

void EditStudents() {
	system("cls");
    int id, found = 0;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &id);
    
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = 1;
            
            printf("Sua ten sinh vien: ");
            scanf(" %[^\n]", students[i].name);
    
            printf("Sua tuoi sinh vien: ");
            scanf("%d", &students[i].age); // Added '&' for correct input
    
            printf("Sua khoa hoc: ");
            scanf(" %[^\n]", students[i].major);
            
            printf("Cap nhat thong tin thanh cong!\n");
            break;  // Exit the loop after updating
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien voi ID nay!\n");
    }
    pressAnyKeyToExit();
}

void deleteStudent() {
	system("cls");
    int id;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Xoa sinh vien thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID nay!\n");
    pressAnyKeyToExit();
}

void searchStudentByName() {
    system("cls");
    char searchName[50];
    printf("Nhap ten sinh vien can tim: ");
    getchar();
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0;
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strstr(students[i].name, searchName)) {
            printf("%-7d %-20s %-5d %-20s\n", students[i].id, students[i].name, students[i].age, students[i].major);
            found = 1;
        }
    }
    if (!found) printf("Khong tim thay sinh vien!\n");
    pressAnyKeyToExit();
}

void displaySortMenu() {
	system("cls");
    printf("===== SAP XEP SINH VIEN =====\n");
    printf("1. Sap xep tang dan theo ten\n");
    printf("2. Sap xep giam dan theo ten\n");
    printf("3. Nhan B de quay lai menu chinh\n"); 
    printf("Nhap lua chon: ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            sortStudentsAscending();
            break;
        case 2:
            sortStudentsDescending();
            break;
        case 3:
			pressAnyKeyToExit();
			break;
		case 4: 
        default:
            printf("Lua chon khong hop le!\n");
	}
}

void sortStudentsAscending() {
	system("cls");
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach sinh vien tang dan theo ten!\n");
    pressAnyKeyToExit();
}

void sortStudentsDescending() {
	system("cls");
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (strcmp(students[i].name, students[j].name) < 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach sinh vien giam dan theo ten!\n");
    pressAnyKeyToExit();
}

void saveToCSV() {
	system("cls");
	system(CLEAR_SCREEN);
    FILE *file = fopen("students.csv", "w");
    if (!file) {
        printf("Loi khi mo tep CSV!\n");
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%d,%s,%d,%s\n", students[i].id, students[i].name, students[i].age, students[i].major);
    }
    fclose(file);
    printf("Da luu danh sach sinh vien vao CSV!\n");
    pressAnyKeyToExit();
}

void loadFromCsv() {
	system("cls");
	system(CLEAR_SCREEN);
    FILE *file = fopen("students.csv", "r");
    if (file == NULL) {
        printf("Khong tim thay tep du lieu. Khoi dong danh sach moi.\n");
        return;
    }

    studentCount = 0;
    while (fscanf(file, "%d,%s,%d,%s\n", &students[studentCount].id, students[studentCount].name, students[studentCount].age, students[studentCount].major) == 3) {
        studentCount++;
    }

    fclose(file);
    printf("Tai du lieu thanh cong!\n");
    pressAnyKeyToExit();
}

void pressAnyKeyToExit() { //*********************ham thoat khi xog 1 chuc nang*******************8 
    printf("\nNhan phim bat ky de quay lai...");
    getchar(); // nhan phim bat ky
}


