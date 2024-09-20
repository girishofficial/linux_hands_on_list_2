/*
============================================================================
Name : addHeader.c
Author : GIRISH KUMAR SAHU
Description : Description of addHeader.c
Date: 20th Sep, 2024.
=============================================================================
*/
#include <stdio.h>
#include <stdlib.h>

#define HEADER "/*
\
============================================================================
\
Name : 9.c
\
Author : Girish Kumar Sahu
\
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
\
signal - Use signal system call.
\
Date: 19th Sep, 2024.
\
============================================================================
\
*/
"

void add_header(const char *filename) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s
", filename);
        exit(EXIT_FAILURE);
    }

    // Move to the beginning of the file
    fseek(file, 0, SEEK_SET);

    // Write the header to the file using putchar
    for (const char *p = HEADER; *p; p++) {
        putchar(*p);
        fputc(*p, file);
    }

    // Now append the original file content after the header
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
        fputc(ch, file);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>
", argv[0]);
        return EXIT_FAILURE;
    }

    add_header(argv[1]);

    printf("Header added to %s
", argv[1]);
    return EXIT_SUCCESS;
}
