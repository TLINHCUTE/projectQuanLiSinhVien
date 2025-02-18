#include <stdio.h>   // Thu vien nhap xuat co ban (printf, scanf, fgets,...)
#include <stdlib.h>  // Thu vien chua cac ham quan ly bo nho, chuyen doi kieu,...
#include <stdbool.h> // Thu vien ho tro kieu du lieu boolean (true/false)
#include <string.h>// Thu vien ho tro xu ly chuoi (fgets, strcspn,...)
#include <ctype.h>  // Thu vien chua hàm tolower()
#include "function.h" 
#ifdef _WIN32  // Kiem tra neu he dieu hanh la Windows
    #define CLEAR_SCREEN "cls"  // Dinh nghia lenh xoa man hinh cho Windows
#else  // Neu he dieu hanh khong phai Windows
    #define CLEAR_SCREEN "clear"  // Dinh nghia lenh xoa man hinh cho Linux/macOS
#endif
//sinh vien
Student students[MAX_STUDENTS];  // Mang luu danh sach sinh vien
int studentCount = 0;            // Bien dem so luong sinh vien hien co trong danh sach

void addStudent() {
    system("cls");  // Xoa man hinh
    if (studentCount >= MAX_STUDENTS) {  // Kiem tra neu danh sach sinh vien da day
        printf("Khong the them sinh vien, danh sach da day.\n");  // Thong bao neu danh sach day
        return;  // Dung ham neu khong the them sinh vien
    }

    Student newStudent;

    // Nhap ID va kiem tra trung lap
    do {
        printf("Nhap ID: ");  // Yeu cau nhap ID sinh vien
        scanf("%d", &newStudent.id);  // Doc ID sinh vien
        if (isDuplicateID(newStudent.id)) {  // Kiem tra ID co trung khong
            printf("ID da ton tai. Vui long nhap ID khac.\n");  // Thong bao neu ID da ton tai
        }
    } while (isDuplicateID(newStudent.id));  // Lap lai cho den khi nhap duoc ID khong trung

    printf("Nhap ten: ");  // Yeu cau nhap ten sinh vien
    getchar();  // Loai bo ky tu '\n' con lai tu lan nhap truoc
    fgets(newStudent.name, sizeof(newStudent.name), stdin);  // Doc ten sinh vien
    newStudent.name[strcspn(newStudent.name, "\n")] = 0;  // Loai bo ky tu '\n' cuoi chuoi ten

    printf("Nhap tuoi: ");  // Yeu cau nhap tuoi sinh vien
    scanf("%d", &newStudent.age);  // Doc tuoi sinh vien

    printf("Nhap nganh hoc: ");  // Yeu cau nhap nganh hoc
    getchar();  // Loai bo ky tu '\n' con lai tu lan nhap truoc
    fgets(newStudent.major, sizeof(newStudent.major), stdin);  // Doc nganh hoc
    newStudent.major[strcspn(newStudent.major, "\n")] = 0;  // Loai bo ky tu '\n' cuoi chuoi nganh hoc

    printf("Nhap so dien thoai: ");  // Yeu cau nhap so dien thoai
    fgets(newStudent.sdt, sizeof(newStudent.sdt), stdin);  // Doc so dien thoai
    newStudent.sdt[strcspn(newStudent.sdt, "\n")] = 0;  // Loai bo ky tu '\n' cuoi chuoi so dien thoai

    // Nhap email va kiem tra dinh dang
    do {
        printf("Nhap email: ");  // Yeu cau nhap email
        fgets(newStudent.email, sizeof(newStudent.email), stdin);  // Doc email
        newStudent.email[strcspn(newStudent.email, "\n")] = 0;  // Loai bo ky tu '\n' cuoi chuoi email
        if (!isValidEmail(newStudent.email)) {  // Kiem tra email hop le
            printf("Email khong hop le. Vui long nhap lai.\n");  // Thong bao neu email khong hop le
        }
    } while (!isValidEmail(newStudent.email));  // Lap lai cho den khi nhap email hop le

    students[studentCount++] = newStudent;  // Them sinh vien moi vao danh sach
    printf("Them sinh vien thanh cong!\n");  // Thong bao them sinh vien thanh cong
    displayStudents();
    pressAnyKeyToExit();  // Yeu cau nguoi dung nhan phim de thoat
}


void displayMenu() {
    system("cls");  // Xoa man hinh
    printf("===============================\n");  // Hien thi tieu de menu
    printf("%5sQUAN LY SINH VIEN\n", "");  // Hien thi ten chuong trinh
    printf("===============================\n");  // Hien thi duong ke phan cach
    printf("1. Hien thi danh sach sinh vien\n");  // Lua chon 1: Hien thi danh sach sinh vien
    printf("2. Them sinh vien\n");  // Lua chon 2: Them sinh vien
    printf("3. Sua thong tin sinh vien\n");  // Lua chon 3: Sua thong tin sinh vien
    printf("4. Xoa sinh vien\n");  // Lua chon 4: Xoa sinh vien
    printf("5. Tim kiem sinh vien\n");  // Lua chon 5: Tim kiem sinh vien
    printf("6. Sap xep danh sach sinh vien\n");  // Lua chon 6: Sap xep danh sach sinh vien
    printf("7. Luu danh sach vao file CSV\n");  // Lua chon 7: Luu danh sach vao file CSV
    printf("8. Doc du lieu tu file CSV\n");  // Lua chon 8: Doc du lieu tu file CSV
    printf("9. Thoat\n");  // Lua chon 9: Thoat chuong trinh
    printf("Nhap lua chon: ");  // Yeu cau nguoi dung nhap lua chon
}

void displayStudents() {
    if (studentCount == 0) {  // Kiem tra neu danh sach sinh vien trong
        printf("Danh sach sinh vien trong!\n");  // Thong bao neu danh sach trong
        pressAnyKeyToExit();  // Yeu cau nguoi dung nhan phim de thoat
        return;  // Dung ham neu danh sach trong
    }

    system("cls");  // Xoa man hinh sau khi kiem tra danh sach khong rong

    printf("---------------------------------------------------------------------------------------------------------------\n");  // Hien thi duong ke phan cach
    printf("| %-7s | %-20s | %-5s | %-16s | %-15s | %-30s |\n",  // Hien thi tieu de cot
           "ID", "Ten", "Tuoi", "Nganh hoc", "SDT", "Email");
    printf("---------------------------------------------------------------------------------------------------------------\n");  // Hien thi duong ke phan cach

    for (int i = 0; i < studentCount; i++) {  // Vong lap qua danh sach sinh vien
        printf("| %-7d | %-20s | %-5d | %-16s | %-15s | %-30s |\n",  // Hien thi thong tin sinh vien
               students[i].id, students[i].name, students[i].age, 
               students[i].major, students[i].sdt, students[i].email);
    }

    printf("---------------------------------------------------------------------------------------------------------------\n");  // Hien thi duong ke phan cach
    pressAnyKeyToExit();  // Yeu cau nguoi dung nhan phim de thoat
}

void EditStudents() {
    system("cls");  // Xoa man hinh
    int id, found = 0;
    printf("Nhap ID sinh vien can sua: ");  // Yeu cau nguoi dung nhap ID sinh vien can sua
    scanf("%d", &id);  // Doc ID sinh vien nhap vao
    
    for (int i = 0; i < studentCount; i++) {  // Vong lap qua danh sach sinh vien
        if (students[i].id == id) {  // Ki?m tra n?u ID sinh viên kh?p v?i ID c?n s?a
            found = 1;  // Ðánh d?u là ð? t?m th?y sinh viên

            printf("Sua ten sinh vien: ");  // Yeu cau nguoi dung nhap ten moi
            scanf(" %[^\n]", students[i].name);  // Doc ten sinh vien moi

            printf("Sua tuoi sinh vien: ");  // Yeu cau nguoi dung nhap tuoi moi
            scanf("%d", &students[i].age);  // Doc tuoi sinh vien moi, chú ? d?u '&' ð? tham chi?u ðúng

            printf("Sua khoa hoc: ");  // Yeu cau nguoi dung nhap khoa hoc moi
            scanf(" %[^\n]", students[i].major);  // Doc khoa hoc sinh vien moi
            
            printf("Cap nhat thong tin thanh cong!\n");  // Thong bao cap nhat thanh cong
            displayStudents();  // G?i hàm ð? hi?n th? l?i danh sách sinh viên sau khi s?a
            break;  // Thoat khoi vong lap sau khi cap nhat xong
        }
    }

    if (!found) {  // Neu khong tim thay sinh vien voi ID da nhap
        printf("Khong tim thay sinh vien voi ID nay!\n");  // Thong bao khong tim thay sinh vien
        getchar(); 
    }
    pressAnyKeyToExit();  // Yeu cau nguoi dung nhan phim de thoat
}


void deleteStudent() {
    system("cls");  // Xoa man hinh
    int id;
    printf("Nhap ID sinh vien can xoa: ");  // Yeu cau nguoi dung nhap ID sinh vien can xoa
    scanf("%d", &id);  // Doc ID sinh vien nhap vao

    for (int i = 0; i < studentCount; i++) {  // Vong lap qua danh sach sinh vien
        if (students[i].id == id) {  // Ki?m tra xem ID sinh viên có kh?p v?i ID c?n xóa không
            for (int j = i; j < studentCount - 1; j++) {  // Vong lap di chuyen danh sach sinh vien de xoa
                students[j] = students[j + 1];  // Di chuyen moi sinh vien sau vi tri i sang truoc 1 vi tri
            }
            studentCount--;  // Giam so luong sinh vien
            displayStudents();  
            printf("\nDanh sach sinh vien sau khi xoa:\n");  // Thong bao danh sach sau khi xoa
            getchar(); 
            return;  // Dung ham khi tim thay sinh vien can xoa
        }
    }
    printf("Khong tim thay sinh vien voi ten nay!\n");  // Thong bao khong tim thay sinh vien voi ID da nhap
    getchar(); 
    pressAnyKeyToExit();  // Yeu cau nguoi dung nhan phim de thoat
}

void searchStudent() {
    system("cls");  // Xoa man hinh
    char input[50], tempName[50], tempSearch[50];

    printf("Nhap ten sinh vien can tim: ");  // Yeu cau nguoi dung nhap ten sinh vien
    getchar();  // Loai bo ky tu '\n' con lai sau khi nhap lua chon truoc
    fgets(input, sizeof(input), stdin);  // Doc input cua nguoi dung
    input[strcspn(input, "\n")] = 0;  // Xoa ky tu xuong dong
    trimWhitespace(input);  // Xoa khoang trang 2 dau cua chuoi nhap vao

    int found = 0;  // Bien danh dau ket qua tim kiem
    printf("\n%-7s %-20s %-5s %-20s %-15s %-25s\n", "ID", "Ten", "Tuoi", "Nganh", "SDT", "Email");  // Hien thi tieu de
    printf("--------------------------------------------------------------------------------------\n");  // Dong ngan cach

    for (int i = 0; i < studentCount; i++) {  // Vong lap de duyet qua danh sach sinh vien
        strcpy(tempName, students[i].name);  // Sao chep ten sinh vien vao tempName
        strcpy(tempSearch, input);  // Sao chep chuoi tim kiem vao tempSearch
        toLowerCase(tempName);  // Chuyen ten sinh vien ve chu thuong
        toLowerCase(tempSearch);  // Chuyen chuoi tim kiem ve chu thuong

        if (strstr(tempName, tempSearch)) {  // So sanh ten sinh vien voi chuoi tim kiem (khong phan biet hoa/thuong)
            printf("%-7d %-20s %-5d %-20s %-15s %-25s\n",  // Hien thi thong tin sinh vien
                   students[i].id, students[i].name, students[i].age, 
                   students[i].major, students[i].sdt, students[i].email);
            found = 1;  // Tim thay sinh vien, gan found = 1
        }
    }

    if (!found)  // Neu khong tim thay sinh vien
        printf("Khong tim thay sinh vien!\n");  // Thong bao khong tim thay sinh vien

    pressAnyKeyToExit();  // Yeu cau nguoi dung nhan phim de thoat
}

void displaySortMenu() {
    system("cls");  // Xoa man hinh
    printf("===== SAP XEP SINH VIEN =====\n");  // Hien thi tieu de menu
    printf("1. Sap xep tang dan theo ten\n");  // Lua chon sap xep tang dan theo ten
    printf("2. Sap xep giam dan theo ten\n");  // Lua chon sap xep giam dan theo ten
    printf("Nhap lua chon: ");  // Yeu cau nguoi dung nhap lua chon
    int choice;
    scanf("%d", &choice);  // Doc lua chon cua nguoi dung
    switch (choice) {  // Cau lenh switch de thuc hien lua chon
        case 1:  // Neu lua chon la 1, sap xep tang dan
            sortStudentsAscending();
            break;
        case 2:  // Neu lua chon la 2, sap xep giam dan
            sortStudentsDescending();
            break;
        case 3:  // Lua chon 3, neu duoc implement
        default:  // Truong hop lua chon khong hop le
            printf("Lua chon khong hop le!\n");  // Thong bao lua chon khong hop le
    }
}

void sortStudentsAscending() {
    system("cls");  // Xoa man hinh
    for (int i = 0; i < studentCount - 1; i++) {  // Vong lap ngoai de sap xep
        for (int j = i + 1; j < studentCount; j++) {  // Vong lap trong de so sanh
            if (strcmp(students[i].name, students[j].name) > 0) {  // So sanh ten theo thu tu tang dan
                Student temp = students[i];  // Hoan doi neu ten khong theo thu tu
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach sinh vien tang dan theo ten!\n");  // Thong bao thanh cong
    displayStudents(); 
    pressAnyKeyToExit();  // Yeu cau nguoi dung nhan phim de thoat
}

void sortStudentsDescending() {
    system("cls");  // Xoa man hinh
    for (int i = 0; i < studentCount - 1; i++) {  // Vong lap ngoai de sap xep
        for (int j = i + 1; j < studentCount; j++) {  // Vong lap trong de so sanh
            if (strcmp(students[i].name, students[j].name) < 0) {  // So sanh ten theo thu tu giam dan
                Student temp = students[i];  // Hoan doi neu ten khong theo thu tu
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach sinh vien giam dan theo ten!\n");  // Thong bao thanh cong
    displayStudents(); 
    pressAnyKeyToExit();  // Yeu cau nguoi dung nhan phim de thoat
}

void saveToCSV() {
    system("cls"); // Xoa man hinh console de hien thi sach se
    FILE *file = fopen("students.csv", "w"); // Mo file CSV o che do ghi (w: write)
    if (!file) { // Kiem tra neu mo file that bai
        printf("Loi khi mo tep CSV!\n"); // Thong bao loi
        return; // Thoat khoi ham
    }

    // Ghi tung sinh vien vao file CSV
    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%d,%s,%d,%s,%s,%s\n", 
                students[i].id, students[i].name, students[i].age, 
                students[i].major, students[i].sdt, students[i].email);
    }

    fclose(file); // Dong file sau khi ghi xong
    printf("Da luu danh sach sinh vien vao CSV!\n"); // Thong bao hoan thanh
    pressAnyKeyToExit(); // Yeu cau nhan phim de tiep tuc
}

void loadFromCsv() {
    system("cls"); // Xoa man hinh console truoc khi tai du lieu
    FILE *file = fopen("students.csv", "r"); // Mo file CSV o che do doc (r: read)
    if (!file) { // Kiem tra neu file khong ton tai
        printf("Khong tim thay tep du lieu. Khoi dong danh sach moi.\n"); // Thong bao khong co du lieu
        return; // Thoat khoi ham
    }

    studentCount = 0; // Dat lai so luong sinh vien ve 0 de nap du lieu moi
    char line[200]; // Bien luu tru tung dong trong file CSV

    // Doc tung dong cua file CSV
    while (fgets(line, sizeof(line), file)) {
        Student temp; // Tao mot bien tam de luu du lieu doc duoc
        // Doc du lieu tu chuoi va luu vao bien temp
        if (sscanf(line, "%d,%49[^,],%d,%49[^,],%14[^,],%49[^\n]", 
                   &temp.id, temp.name, &temp.age, temp.major, temp.sdt, temp.email) == 6) {
            students[studentCount++] = temp; // Luu sinh vien vao danh sach chinh
        }
    }

    fclose(file); // Dong file sau khi doc xong
    printf("Tai du lieu thanh cong!\n"); // Thong bao hoan thanh
    pressAnyKeyToExit(); // Yeu cau nhan phim de tiep tuc
}

//giao vien
Teacher teachers[MAX_TEACHERS];  // Mang luu danh sach giao vien
int teacherCount = 0;            // Bien dem so luong giao vien hien co trong danh sach

void addTeacher() {
    system("cls");  // Xoa man hinh
    if (teacherCount >= MAX_TEACHERS) {  // Kiem tra neu danh sach giao vien da day
        printf("Khong the them sinh vien, danh sach da day.\n");  // Thong bao neu danh sach day
        return;  // Dung ham neu khong the them giao vien
    }

    Teacher newTeacher;

    // Nhap ID va kiem tra trung lap
    do {
        printf("Nhap ID: ");  // Yeu cau nhap ID giao vien
        scanf("%d", &newTeacher.id);  // Doc ID giao vien
        if (isDuplicateID(newTeacher.id)) {  // Kiem tra ID co trung khong
            printf("ID da ton tai. Vui long nhap ID khac.\n");  // Thong bao neu ID da ton tai
        }
    } while (isDuplicateID(newTeacher.id));  // Lap lai cho den khi nhap duoc ID khong trung

    printf("Nhap ten giao vien: ");  // Yeu cau nhap ten giao vien
    getchar();  // Loai bo ky tu '\n' con lai tu lan nhap truoc
    fgets(newTeacher.name, sizeof(newTeacher.name), stdin);  // Doc ten giao vien
    newTeacher.name[strcspn(newTeacher.name, "\n")] = 0;  // Loai bo ky tu '\n' cuoi chuoi ten

    printf("Nhap tuoi: ");  // Yeu cau nhap tuoi giao vien 
    scanf("%d", &newTeacher.age);  // Doc tuoi giao vien

    printf("Nhap nganh giang day: ");  // Yeu cau nhap nganh giang day
    getchar();  // Loai bo ky tu '\n' con lai tu lan nhap truoc
    fgets(newTeacher.major, sizeof(newTeacher.major), stdin);  // Doc nganh giang day
    newTeacher.major[strcspn(newTeacher.major, "\n")] = 0;  // Loai bo ky tu '\n' cuoi chuoi nganh giang day

    printf("Nhap so dien thoai: ");  // Yeu cau nhap so dien thoai
    fgets(newTeacher.sdt, sizeof(newTeacher.sdt), stdin);  // Doc so dien thoai
    newTeacher.sdt[strcspn(newTeacher.sdt, "\n")] = 0;  // Loai bo ky tu '\n' cuoi chuoi so dien thoai

    // Nhap email va kiem tra dinh dang
    do {
        printf("Nhap email: ");  // Yeu cau nhap email
        fgets(newTeacher.email, sizeof(newTeacher.email), stdin);  // Doc email
        newTeacher.email[strcspn(newTeacher.email, "\n")] = 0;  // Loai bo ky tu '\n' cuoi chuoi email
        if (!isValidEmail(newTeacher.email)) {  // Kiem tra email hop le
            printf("Email khong hop le. Vui long nhap lai.\n");  // Thong bao neu email khong hop le
        }
    } while (!isValidEmail(newTeacher.email));  // Lap lai cho den khi nhap email hop le

    teachers[teacherCount++] = newTeacher;  // Them giao vien moi vao danh sach
    printf("Them giao vien thanh cong!\n");  // Thong bao them giao vien thanh cong
    displayTeachers();
    pressAnyKeyToExit();  // Yeu cau nguoi dung nhan phim de thoat
}


void displayMenuTeachers() {
    system("cls");  // Xoa man hinh
    printf("===============================\n");  // Hien thi tieu de menu
    printf("%5sQUAN LY GiAO VIEN\n", "");  // Hien thi ten chuong trinh
    printf("===============================\n");  // Hien thi duong ke phan cach
    printf("1. Hien thi danh sach giao vien\n");  // Lua chon 1: Hien thi danh sach giao vien
    printf("2. Them giao vien\n");  // Lua chon 2: Them giao vien
    printf("3. Sua thong tin giao vien\n");  // Lua chon 3: Sua thong tin giao vien
    printf("4. Xoa giao vien\n");  // Lua chon 4: Xoa giao vien
    printf("5. Tim kiem giao vien\n");  // Lua chon 5: Tim kiem giao vien
    printf("6. Sap xep danh sach giao vien\n");  // Lua chon 6: Sap xep danh sach giao vien
    printf("7. Luu danh sach vao file CSV\n");  // Lua chon 7: Luu danh sach vao file CSV
    printf("8. Doc du lieu tu file CSV\n");  // Lua chon 8: Doc du lieu tu file CSV
    printf("9. Thoat\n");  // Lua chon 9: Thoat chuong trinh
    printf("Nhap lua chon: ");  // Yeu cau nguoi dung nhap lua chon
}

void displayTeachers() {
    if (teacherCount == 0) {  // Kiem tra neu danh sach giao vien trong
        printf("Danh sach giao vien trong!\n");  // Thong bao neu danh sach trong
        pressAnyKeyToExit();  // Yeu cau nguoi dung nhan phim de thoat
        return;  // Dung ham neu danh sach trong
    }

    system("cls");  // Xoa man hinh sau khi kiem tra danh sach khong rong

    printf("--------------------------------------------------------------------------------------------------------------------\n");  // Hien thi duong ke phan cach
    printf("| %-7s | %-20s | %-5s | %-20s | %-15s | %-30s |\n",  // Hien thi tieu de cot
           "ID", "Ten", "Tuoi", "Nganh giang day", "SDT", "Email");
    printf("--------------------------------------------------------------------------------------------------------------------\n");  // Hien thi duong ke phan cach

    for (int i = 0; i < teacherCount; i++) {  // Vong lap qua danh sach giao vien
        printf("| %-7d | %-20s | %-5d | %-20s | %-15s | %-30s |\n",  // Hien thi thong tin giao vien
               teachers[i].id, teachers[i].name, teachers[i].age, 
               teachers[i].major, teachers[i].sdt, teachers[i].email);
    }

    printf("--------------------------------------------------------------------------------------------------------------------\n");  // Hien thi duong ke phan cach
    pressAnyKeyToExit();  // Yeu cau nguoi dung nhan phim de thoat
}

void EditTeachers() {
    system("cls");  // Xoa man hinh
    int id, found = 0;
    printf("Nhap ID giao vien can sua: ");  // Yeu cau nguoi dung nhap ID giao vien can sua
    scanf("%d", &id);  // Doc ID giao vien nhap vao
    
    for (int i = 0; i < teacherCount; i++) {  // Vong lap qua danh sach giao vien
        if (teachers[i].id == id) {  // Kiem tra neu ID giao vien khop voi ID can sua
            found = 1;  // Ðánh d?u là ð? t?m th?y giao vien

            printf("Sua ten giao vien: ");  // Yeu cau nguoi dung nhap ten moi
            scanf(" %[^\n]", teachers[i].name);  // Doc ten giao vien moi

            printf("Sua tuoi giao vien: ");  // Yeu cau nguoi dung nhap tuoi moi
            scanf("%d", &teachers[i].age);  // Doc tuoi giao vien moi, chú ? d?u '&' ð? tham chi?u ðúng

            printf("Sua nganh giang day: ");  // Yeu cau nguoi dung nhap khoa hoc moi
            scanf(" %[^\n]", teachers[i].major);  // Doc nganh giang day giao vien moi
            
            printf("Cap nhat thong tin thanh cong!\n");  // Thong bao cap nhat thanh cong
            displayTeachers();  // G?i hàm ð? hi?n th? l?i danh sách sinh viên sau khi s?a
            break;  // Thoat khoi vong lap sau khi cap nhat xong
        }
    }

    if (!found) {  // Neu khong tim thay giao vien voi ID da nhap
        printf("Khong tim thay giao vien voi ID nay!\n");  // Thong bao khong tim thay giao vien
        getchar(); 
    }
    pressAnyKeyToExit();  // Yeu cau nguoi dung nhan phim de thoat
}


void deleteTeacher() {
    system("cls");  // Xoa man hinh
    int id;
    printf("Nhap ID giao vien can xoa: ");  // Yeu cau nguoi dung nhap ID giao vien can xoa
    scanf("%d", &id);  // Doc ID giao vien nhap vao

    for (int i = 0; i < teacherCount; i++) {  // Vong lap qua danh sach giao vien
        if (teachers[i].id == id) {  // Ki?m tra xem ID giao vien có kh?p v?i ID c?n xóa không
            for (int j = i; j < teacherCount - 1; j++) {  // Vong lap di chuyen danh sach sinh vien de xoa
                teachers[j] = teachers[j + 1];  // Di chuyen moi giao vein sau vi tri i sang truoc 1 vi tri
            }
            teacherCount--;  // Giam so luong giao vien
            displayTeachers();  
            printf("\nDanh sach giao vien sau khi xoa:\n");  // Thong bao danh sach sau khi xoa
            getchar(); 
            return;  // Dung ham khi tim thay giao vien can xoa
        }
    }
    printf("Khong tim thay giao vien voi ten nay!\n");  // Thong bao khong tim thay giao vien voi ID da nhap
    getchar(); 
    pressAnyKeyToExit();  // Yeu cau nguoi dung nhan phim de thoat
}

void searchTeacher() {
    system("cls");  // Xoa man hinh
    char input[50], tempName[50], tempSearch[50];

    printf("Nhap ten giao vien can tim: ");  // Yeu cau nguoi dung nhap ten giao vien
    getchar();  // Loai bo ky tu '\n' con lai sau khi nhap lua chon truoc
    fgets(input, sizeof(input), stdin);  // Doc input cua nguoi dung
    input[strcspn(input, "\n")] = 0;  // Xoa ky tu xuong dong
    trimWhitespace(input);  // Xoa khoang trang 2 dau cua chuoi nhap vao

    int found = 0;  // Bien danh dau ket qua tim kiem
    printf("\n%-7s %-20s %-5s %-20s %-15s %-25s\n", "ID", "Ten", "Tuoi", "Nganh giang day", "SDT", "Email");  // Hien thi tieu de
    printf("-------------------------------------------------------------------------------------------\n");  // Dong ngan cach

    for (int i = 0; i < teacherCount; i++) {  // Vong lap de duyet qua danh sach giao vien
        strcpy(tempName, teachers[i].name);  // Sao chep ten giao vien vao tempName
        strcpy(tempSearch, input);  // Sao chep chuoi tim kiem vao tempSearch
        toLowerCase(tempName);  // Chuyen ten giao vien ve chu thuong
        toLowerCase(tempSearch);  // Chuyen chuoi tim kiem ve chu thuong

        if (strstr(tempName, tempSearch)) {  // So sanh ten giao vien voi chuoi tim kiem (khong phan biet hoa/thuong)
            printf("%-7d %-20s %-5d %-20s %-15s %-25s\n",  // Hien thi thong tin giao vien
                   teachers[i].id, teachers[i].name, teachers[i].age, 
                   teachers[i].major, teachers[i].sdt, teachers[i].email);
            found = 1;  // Tim thay giao vien, gan found = 1
        }
    }

    if (!found)  // Neu khong tim thay giao vien
        printf("Khong tim thay giao vien!\n");  // Thong bao khong tim thay giao vien

    pressAnyKeyToExit();  // Yeu cau nguoi dung nhan phim de thoat
}

void displaySortMenuTeachers() {
    system("cls");  // Xoa man hinh
    printf("===== SAP XEP GIAO VIEN =====\n");  // Hien thi tieu de menu
    printf("1. Sap xep tang dan theo ten\n");  // Lua chon sap xep tang dan theo ten
    printf("2. Sap xep giam dan theo ten\n");  // Lua chon sap xep giam dan theo ten
    printf("Nhap lua chon: ");  // Yeu cau nguoi dung nhap lua chon
    int choice;
    scanf("%d", &choice);  // Doc lua chon cua nguoi dung
    switch (choice) {  // Cau lenh switch de thuc hien lua chon
        case 1:  // Neu lua chon la 1, sap xep tang dan
            sortTeachersAscending();
            break;
        case 2:  // Neu lua chon la 2, sap xep giam dan
            sortTeachersDescending();
            break;
        case 3:  // Lua chon 3, neu duoc implement
        default:  // Truong hop lua chon khong hop le
            printf("Lua chon khong hop le!\n");  // Thong bao lua chon khong hop le
    }
}

void sortTeachersAscending() {
    system("cls");  // Xoa man hinh
    for (int i = 0; i < studentCount - 1; i++) {  // Vong lap ngoai de sap xep
        for (int j = i + 1; j < teacherCount; j++) {  // Vong lap trong de so sanh
            if (strcmp(teachers[i].name, teachers[j].name) > 0) {  // So sanh ten theo thu tu tang dan
                Teacher temp = teachers[i];  // Hoan doi neu ten khong theo thu tu
                teachers[i] = teachers[j];
                teachers[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach giao vien tang dan theo ten!\n");  // Thong bao thanh cong
    displayTeachers(); 
    pressAnyKeyToExit();  // Yeu cau nguoi dung nhan phim de thoat
}

void sortTeachersDescending() {
    system("cls");  // Xoa man hinh
    for (int i = 0; i < teacherCount - 1; i++) {  // Vong lap ngoai de sap xep
        for (int j = i + 1; j < teacherCount; j++) {  // Vong lap trong de so sanh
            if (strcmp(teachers[i].name, teachers[j].name) < 0) {  // So sanh ten theo thu tu giam dan
                Teacher temp = teachers[i];  // Hoan doi neu ten khong theo thu tu
                teachers[i] = teachers[j];
                teachers[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach giao vien giam dan theo ten!\n");  // Thong bao thanh cong
    displayTeachers(); 
    pressAnyKeyToExit();  // Yeu cau nguoi dung nhan phim de thoat
}

void saveToTeacherCSV() {
    system("cls"); // Xoa man hinh console de hien thi sach se
    FILE *file = fopen("teacher.csv", "w"); // Mo file CSV o che do ghi (w: write)
    if (!file) { // Kiem tra neu mo file that bai
        printf("Loi khi mo tep CSV!\n"); // Thong bao loi
        return; // Thoat khoi ham
    }

    // Ghi tung giao vien vao file CSV
    for (int i = 0; i < teacherCount; i++) {
        fprintf(file, "%d,%s,%d,%s,%s,%s\n", 
                teachers[i].id, teachers[i].name, teachers[i].age, 
                teachers[i].major, teachers[i].sdt, teachers[i].email);
    }

    fclose(file); // Dong file sau khi ghi xong
    printf("Da luu danh sach giao vien vao CSV!\n"); // Thong bao hoan thanh
    pressAnyKeyToExit(); // Yeu cau nhan phim de tiep tuc
}

void loadFromTeacherCsv() {
    system("cls"); // Xoa man hinh console truoc khi tai du lieu
    FILE *file = fopen("teacher.csv", "r"); // Mo file CSV o che do doc (r: read)
    if (!file) { // Kiem tra neu file khong ton tai
        printf("Khong tim thay tep du lieu. Khoi dong danh sach moi.\n"); // Thong bao khong co du lieu
        return; // Thoat khoi ham
    }

    studentCount = 0; // Dat lai so luong giao vien ve 0 de nap du lieu moi
    char line[200]; // Bien luu tru tung dong trong file CSV

    // Doc tung dong cua file CSV
    while (fgets(line, sizeof(line), file)) {
        Teacher temp; // Tao mot bien tam de luu du lieu doc duoc
        // Doc du lieu tu chuoi va luu vao bien temp
        if (sscanf(line, "%d,%49[^,],%d,%49[^,],%14[^,],%49[^\n]", 
                   &temp.id, temp.name, &temp.age, temp.major, temp.sdt, temp.email) == 6) {
            teachers[teacherCount++] = temp; // Luu giao vien vao danh sach chinh
        }
    }

    fclose(file); // Dong file sau khi doc xong
    printf("Tai du lieu thanh cong!\n"); // Thong bao hoan thanh
    pressAnyKeyToExit(); // Yeu cau nhan phim de tiep tuc
}

//tien ich
// Ki?m tra ID trùng cho sinh viên ho?c giáo viên
int isDuplicateID(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            return 1;
        }
    }
    for (int i = 0; i < teacherCount; i++) {
        if (teachers[i].id == id) {
            return 1;
        }
    }
    return 0;
}

// Ki?m tra email h?p l?
int isValidEmail(char *email) {
    int atPos = -1, dotPos = -1, len = strlen(email);
    for (int i = 0; i < len; i++) {
        if (email[i] == '@') atPos = i;
        if (email[i] == '.') dotPos = i;
    }
    return (atPos > 0 && dotPos > atPos + 1 && dotPos < len - 1);
}

// Chuy?n ch? thý?ng
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Xóa kho?ng tr?ng
void trimWhitespace(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
}

// D?ng màn h?nh
void pressAnyKeyToExit() {
    printf("\nNhan phim bat ky de quay lai...");
    getchar();
} 

