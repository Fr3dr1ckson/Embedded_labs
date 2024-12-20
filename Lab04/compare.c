#include <stdio.h>

void compareStrings(const char* str1, const char* str2) {
    int i = 0;
    int areEqual = 1;

    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            areEqual = 0;
            break;
        }
        i++;
    }

    if (areEqual && str1[i] == '\0' && str2[i] == '\0') {
        printf("The strings are identical.\n");
    } else {
        printf("The strings are different.\n");
    }
}

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == '\n') {
            str1[i] = '\0';
            break;
        }
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        if (str2[i] == '\n') {
            str2[i] = '\0';
            break;
        }
    }

    compareStrings(str1, str2);

    return 0;
}
