// noi trien khai cac ham
#include <stdio.h>   // Thu vien nhap xuat co ban (printf, scanf, fgets,...)
#include <stdlib.h>  // Thu vien chua cac ham quan ly bo nho, chuyen doi kieu,...
#include <stdbool.h> // Thu vien ho tro kieu du lieu boolean (true/false)
#include <string.h>// Thu vien ho tro xu ly chuoi (fgets, strcspn,...)
#include <ctype.h>  // Thu vien chua hàm tolower()
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

int isDuplicateID(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            return 1; // ID b? trùng
        }
    }
    return 0;
}

// Kiem tra dinh dang email có hop le không
int isValidEmail(char *email) {
    int atPos = -1, dotPos = -1, len = strlen(email);
    for (int i = 0; i < len; i++) {
        if (email[i] == '@') atPos = i;
        if (email[i] == '.') dotPos = i;
    }
    return (atPos > 0 && dotPos > atPos + 1 && dotPos < len - 1);
}

void addStudent() {
    system("cls");
    if (studentCount >= MAX_STUDENTS) {
        printf("Khong the them sinh vien, danh sach da day.\n");
        return;
    }

    Student newStudent;

    // Nhap ID và kiem tra trùng lap
    do {
        printf("Nhap ID: ");
        scanf("%d", &newStudent.id);
        if (isDuplicateID(newStudent.id)) {
            printf("ID da ton tai. Vui long nhap ID khac.\n");
        }
    } while (isDuplicateID(newStudent.id));

    printf("Nhap ten: ");
    getchar();  
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0;  

    printf("Nhap tuoi: ");
    scanf("%d", &newStudent.age);

    printf("Nhap nganh hoc: ");
    getchar();  
    fgets(newStudent.major, sizeof(newStudent.major), stdin);
    newStudent.major[strcspn(newStudent.major, "\n")] = 0;  

    printf("Nhap so dien thoai: ");
    fgets(newStudent.sdt, sizeof(newStudent.sdt), stdin);
    newStudent.sdt[strcspn(newStudent.sdt, "\n")] = 0;

    // Nh?p email và ki?m tra d?nh d?ng
    do {
        printf("Nhap email: ");
        fgets(newStudent.email, sizeof(newStudent.email), stdin);
        newStudent.email[strcspn(newStudent.email, "\n")] = 0;
        if (!isValidEmail(newStudent.email)) {
            printf("Email khong hop le. Vui long nhap lai.\n");
        }
    } while (!isValidEmail(newStudent.email));

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
	printf("8. Doc du lieu tu file CSV\n"); 
    printf("9. Thoat\n");
    printf("Nhap lua chon: ");
}

void displayStudents() {
    if (studentCount == 0) {
        printf("Danh sach sinh vien trong!\n");
        pressAnyKeyToExit();
        return;
    }

    system("cls");  // Xóa màn h?nh sau khi ki?m tra danh sách không r?ng

    printf("---------------------------------------------------------------------------------------------------------------\n");
    printf("| %-7s | %-20s | %-5s | %-16s | %-15s | %-30s |\n", 
           "ID", "Ten", "Tuoi", "Nganh hoc", "SDT", "Email");
    printf("---------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        printf("| %-7d | %-20s | %-5d | %-16s | %-15s | %-30s |\n", 
               students[i].id, students[i].name, students[i].age, 
               students[i].major, students[i].sdt, students[i].email);
    }

    printf("---------------------------------------------------------------------------------------------------------------\n");
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

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {// Lap qua tung ki tu trong chuoi
        str[i] = tolower(str[i]);// Chuyen ki tu dó thành chu thuong
    }
}

void trimWhitespace(char *str) {
    char *end;
    
    // Lo?i b? kho?ng tr?ng ð?u chu?i
    while (isspace((unsigned char)*str)) str++;

    // N?u chu?i r?ng sau khi xóa kho?ng tr?ng ð?u
    if (*str == 0) return;

    // Lo?i b? kho?ng tr?ng cu?i chu?i
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = '\0';  // C?t chu?i t?i v? trí m?i
}

void searchStudent() {
    system("cls");
    char input[50], tempName[50], tempSearch[50];

    printf("Nhap ten sinh vien can tim: ");
    getchar();  
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;  // Xóa k? t? xu?ng d?ng
    trimWhitespace(input);  // Xóa kho?ng tr?ng 2 ð?u

    int found = 0;
    printf("\n%-7s %-20s %-5s %-20s %-15s %-25s\n", "ID", "Ten", "Tuoi", "Nganh", "SDT", "Email");
    printf("--------------------------------------------------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        strcpy(tempName, students[i].name);
        strcpy(tempSearch, input);
        toLowerCase(tempName);
        toLowerCase(tempSearch);

        if (strstr(tempName, tempSearch)) {  // So sánh không phân bi?t hoa/thý?ng
            printf("%-7d %-20s %-5d %-20s %-15s %-25s\n", 
                   students[i].id, students[i].name, students[i].age, 
                   students[i].major, students[i].sdt, students[i].email);
            found = 1;
        }
    }

    if (!found) 
        printf("Khong tim thay sinh vien!\n");

    pressAnyKeyToExit();
}



void displaySortMenu() {
	system("cls");
    printf("===== SAP XEP SINH VIEN =====\n");
    printf("1. Sap xep tang dan theo ten\n");
    printf("2. Sap xep giam dan theo ten\n");
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
    FILE *file = fopen("students.csv", "w");
    if (!file) {
        printf("Loi khi mo tep CSV!\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%d,%s,%d,%s,%s,%s\n", 
                students[i].id, students[i].name, students[i].age, 
                students[i].major, students[i].sdt, students[i].email);
    }

    fclose(file);
    printf("Da luu danh sach sinh vien vao CSV!\n");
    pressAnyKeyToExit();
}

void loadFromCsv() {
    system("cls");
    FILE *file = fopen("students.csv", "r");
    if (!file) {
        printf("Khong tim thay tep du lieu. Khoi dong danh sach moi.\n");
        return;
    }

    studentCount = 0;
    char line[200];

    while (fgets(line, sizeof(line), file)) {
        Student temp;
        if (sscanf(line, "%d,%49[^,],%d,%49[^,],%14[^,],%49[^\n]", 
                   &temp.id, temp.name, &temp.age, temp.major, temp.sdt, temp.email) == 6) {
            students[studentCount++] = temp;
        }
    }

    fclose(file);
    printf("Tai du lieu thanh cong!\n");
    pressAnyKeyToExit();
}

void pressAnyKeyToExit() { //ham thoat khi xog 1 chuc nang
    printf("\nNhan phim bat ky de quay lai...");
    getchar(); // nhan phim bat ky
}


