#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[100];
    double price;
    int pages;
    char language[50];
    double weight;
    int year;
    struct Book *next;
} Book;

Book* createBook(const char* title, double price, int pages, const char* language, double weight, int year) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    if (newBook == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newBook->title, title);
    newBook->price = price;
    newBook->pages = pages;
    strcpy(newBook->language, language);
    newBook->weight = weight;
    newBook->year = year;
    newBook->next = NULL;
    return newBook;
}

void appendBook(Book** head, const char* title, double price, int pages, const char* language, double weight, int year) {
    Book* newBook = createBook(title, price, pages, language, weight, year);
    if (*head == NULL) {
        *head = newBook;
    } else {
        Book* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
}

void displayBooks(Book* head) {
    printf("Harry Potter Series:\n\n");
    while (head != NULL) {
        printf("Title: %s\n", head->title);
        printf("Price: $%.2f\n", head->price);
        printf("Pages: %d\n", head->pages);
        printf("Language: %s\n", head->language);
        printf("Weight: %.2f kg\n", head->weight);
        printf("Year: %d\n\n", head->year);
        head = head->next;
    }
}

void freeBooks(Book* head) {
    Book* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Book* bookList = NULL;

    appendBook(&bookList, "Harry Potter and the Philosopher's Stone", 19.99, 223, "English", 0.5, 1997);
    appendBook(&bookList, "Harry Potter and the Chamber of Secrets", 20.99, 251, "English", 0.6, 1998);
    appendBook(&bookList, "Harry Potter and the Prisoner of Azkaban", 22.99, 317, "English", 0.7, 1999);
    appendBook(&bookList, "Harry Potter and the Goblet of Fire", 25.99, 636, "English", 1.0, 2000);
    appendBook(&bookList, "Harry Potter and the Order of the Phoenix", 27.99, 766, "English", 1.2, 2003);
    appendBook(&bookList, "Harry Potter and the Half-Blood Prince", 23.99, 607, "English", 1.1, 2005);
    appendBook(&bookList, "Harry Potter and the Deathly Hallows", 29.99, 607, "English", 1.1, 2007);

    displayBooks(bookList);

    freeBooks(bookList);

    return 0;
}
