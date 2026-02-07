//this diary can read and save text in files and can load and search entries and saves them to files of txt
#include <stdio.h>
#include <string.h>

void addEntry() {
    FILE *f = fopen("diary.txt", "a");
    char date[20], text[500];
    printf("Enter date (dd-mm-yyyy): ");
    scanf("%s", date);
    getchar();
    printf("Write entry: ");
    fgets(text, sizeof(text), stdin);
    fprintf(f, "%s|%s", date, text);
    fclose(f);
}

void viewEntries() {
    FILE *f = fopen("diary.txt", "r");
    char line[600];
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
    }
    fclose(f);
}

void searchEntry() {
    FILE *f = fopen("diary.txt", "r");
    char date[20], fileDate[20], text[500], line[600];
    printf("Enter date to search: ");
    scanf("%s", date);
    while (fgets(line, sizeof(line), f)) {
        sscanf(line, "%[^|]|%[^\n]", fileDate, text);
        if (strcmp(date, fileDate) == 0) {
            printf("%s\n", text);
        }
    }
    fclose(f);
}

int login() {
    char pass[20];
    printf("Password: ");
    scanf("%s", pass);
    if (strcmp(pass, "1234") == 0) return 1;
    return 0;
}

int main() {
    int choice;
    if (!login()) {
        printf("Wrong password\n");
        return 0;
    }
    while (1) {
        printf("\n1 Add Entry\n2 View All\n3 Search By Date\n4 Exit\nChoose: ");
        scanf("%d", &choice);
        if (choice == 1) addEntry();
        else if (choice == 2) viewEntries();
        else if (choice == 3) searchEntry();
        else break;
    }
    return 0;
}
