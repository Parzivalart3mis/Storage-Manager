#include "storage_mgr.h"
#include "dberror.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * ############################
 *    Page File Manipulation
 * ############################
 */

void initStorageManager(void) {
    printf("Storage manager init\n");
}
RC createPageFile(char *fileName) {
    FILE *file = fopen(fileName, "w");   // "w" creates file if it doesn't exist and truncates the file if it exists
    if (file == NULL) {
        printf("New file initiated");
    }
    // char *pointer = (char *)calloc(PAGE_SIZE, sizeof(char));
    // if (pointer == NULL) {
    //     printf("Memory allocation error");
    // }
    // else {
    //     for (int i = 0; i < PAGE_SIZE; i++) {
    //         fputc('\0', file);
    //     }
    //     printf("Memory allocated!");
    //     return RC_OK;
    // }
    for (int i = 0; i < PAGE_SIZE; i++) {
        fputc('\0', file);
    }
    fclose(file);

    /*
     * To check if file has been written
     */
    // FILE *file1 = fopen(fileName, "r");   // "w" creates file if it doesn't exist and truncates the file if it exists
    // int ch;
    // while((ch = fgetc(file1)) != EOF) {
    //     putchar(ch);
    // }
    // printf("Memory allocated!\n");
    // fclose(file1);
    return RC_OK;


}

RC openPageFile(char *fileName, SM_FileHandle *fHandle) {

    return 0;
}

RC closePageFile(SM_FileHandle *fHandle) {
    return 0;
}

RC destroyPageFile(char *fileName) {
    return 0;
}

/*
 * ############################
 *   Reading blocks from disk
 * ############################
 */

RC readBlock (int pageNum, SM_FileHandle *fHandle, SM_PageHandle memPage) {
    return 0;
}

int getBlockPos (SM_FileHandle *fHandle) {
    return 0;
}
RC readFirstBlock (SM_FileHandle *fHandle, SM_PageHandle memPage) {
    return 0;
}
RC readPreviousBlock (SM_FileHandle *fHandle, SM_PageHandle memPage) {
    return 0;
}
RC readCurrentBlock (SM_FileHandle *fHandle, SM_PageHandle memPage) {
    return 0;
}
RC readNextBlock (SM_FileHandle *fHandle, SM_PageHandle memPage) {
    return 0;
}
RC readLastBlock (SM_FileHandle *fHandle, SM_PageHandle memPage) {
    return 0;
}

/*
 * #################################
 *   Writing blocks to a page file
 * #################################
 */

RC writeBlock (int pageNum, SM_FileHandle *fHandle, SM_PageHandle memPage) {
    return 0;
}
RC writeCurrentBlock (SM_FileHandle *fHandle, SM_PageHandle memPage) {
    return 0;
}
RC appendEmptyBlock (SM_FileHandle *fHandle) {
    return 0;
}
RC ensureCapacity (int numberOfPages, SM_FileHandle *fHandle) {
    return 0;
}