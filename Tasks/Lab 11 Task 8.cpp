#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int quantity;
    float price;
};

void addBook(FILE *file) {
    struct Book book;
    printf("Enter Book ID: ");
    scanf("%d", &book.id);
    printf("Enter Title: ");
    scanf(" %[^\n]", book.title);
    printf("Enter Author: ");
    scanf(" %[^\n]", book.author);
    printf("Enter Quantity: ");
    scanf("%d", &book.quantity);
    printf("Enter Price: ");
    scanf("%f", &book.price);

    fwrite(&book, sizeof(book), 1, file);
}

void viewBooks(FILE *file) {
    struct Book book;
    rewind(file);
    while (fread(&book, sizeof(book), 1, file)) {
        printf("ID: %d, Title: %s, Author: %s, Quantity: %d, Price: %.2f\n",
               book.id, book.title, book.author, book.quantity, book.price);
    }
}

int main() {
    FILE *file = fopen("books.dat", "r+b");
    if (!file) {
        file = fopen("books.dat", "w+b");
        if (!file) {
            printf("Error opening file.\n");
            return 1;
        }
    }

    int choice;
    do {
        printf("1. Add Book\n2. View Books\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(file); break;
            case 2: viewBooks(file); break;
            case 3: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 3);

    fclose(file);
    return 0;
}