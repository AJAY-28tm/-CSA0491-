	#include <stdio.h>
#include <stdlib.h>

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }

    printf("File '%s' created successfully.\n", filename);

    fclose(file);
}

void writeFile(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s", content);

    printf("Content written to '%s'.\n", filename);

    fclose(file);
}

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    char ch;
    printf("Content of '%s':\n", filename);

    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

void deleteFile(const char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        perror("Error deleting file");
        exit(EXIT_FAILURE);
    }
}

int main() {
    const char *filename = "example.txt";
    const char *content = "Hello, File Management in C!\n";

    // Create and write to a file
    createFile(filename);
    writeFile(filename, content);

    // Read from the file
    readFile(filename);

    // Delete the file
    deleteFile(filename);

    return EXIT_SUCCESS;
}

