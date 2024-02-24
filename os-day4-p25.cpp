#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <permission_mode>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    const char *permission_mode_str = argv[2];

    // Convert permission mode string to an integer
    int permission_mode = strtol(permission_mode_str, NULL, 8);

    // Change file permissions using chmod
    if (chmod(filename, permission_mode) == 0) {
        printf("File permissions for %s changed successfully.\n", filename);
    } else {
        perror("Error changing file permissions");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

