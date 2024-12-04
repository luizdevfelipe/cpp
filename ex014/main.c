#include <stdio.h>

int main(void) {
    FILE *file = fopen("phonebook.csv", "a");
    char name[10];
    char number[20];

    printf("Name: ");
    scanf("%s", &name);

    printf("Number: ");
    scanf("%s", &number);

    fprintf(file, "%s, %s\n", name, number);
    fclose(file);
}