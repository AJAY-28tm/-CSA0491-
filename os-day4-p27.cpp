#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    // Check if a directory path is provided as a command-line argument
    const char *dirPath = (argc > 1) ? argv[1] : ".";

    // Open the directory
    DIR *dir = opendir(dirPath);

    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    // Read and print the contents of the directory
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close the directory
    closedir(dir);

    return 0;
}

