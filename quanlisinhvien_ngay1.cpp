#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[50];
    char phone[15];
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Danh sach sinh vien da day!\n");
        return;
    }
    
    printf("Nhap ID: ");
    scanf("%d", &students[studentCount].id);
    printf("Nhap ten: ");
    getchar(); // Clear newline character
    fgets(students[studentCount].name, sizeof(students[studentCount].name), stdin);
    strtok(students[studentCount].name, "\n"); // Remove newline character
    printf("Nhap so dien thoai: ");
    scanf("%s", students[studentCount].phone);
    
    studentCount++;
    printf("Them sinh vien thanh cong!\n");
}

void displayStudents() {
    printf("\nDanh sach sinh vien:\n");
    if (studentCount == 0) {
        printf("Danh sach trong.\n");
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Ten: %s, SDT: %s\n", students[i].id, students[i].name, students[i].phone);
    }
}

void searchStudent() {
    char name[50];
    printf("Nhap ten sinh vien can tim: ");
    getchar();
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n");
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strstr(students[i].name, name)) {
            printf("Tim thay: ID: %d, Ten: %s, SDT: %s\n", students[i].id, students[i].name, students[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien voi ten do.\n");
    }
}

void deleteStudent() {
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
}

void saveToFile() {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Loi khi mo tep de luu du lieu!\n");
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%d %s %s\n", students[i].id, students[i].name, students[i].phone);
    }
    fclose(file);
    printf("Luu du lieu thanh cong!\n");
}

void loadFromFile() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Khong tim thay tep du lieu. Khoi dong danh sach moi.\n");
        return;
    }

    studentCount = 0;
    while (fscanf(file, "%d %49s %14s", &students[studentCount].id, 
                  students[studentCount].name, students[studentCount].phone) == 3) {
        studentCount++;
    }

    fclose(file);
    printf("Tai du lieu thanh cong!\n");
}

int main() {
    int choice;
    loadFromFile();
    do {
        printf("\n1. Them sinh vien\n2. Hien thi danh sach\n3. Tim kiem sinh vien\n4. Xoa sinh vien\n5. Luu du lieu\n6. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: saveToFile(); break;
            case 6: printf("Thoat chuong trinh!\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 6);
    return 0;
}

