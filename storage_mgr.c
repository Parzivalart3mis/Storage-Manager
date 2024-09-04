#include "storage_mgr.h"
#include "dberror.h"
#include <stdio.h>
#include <stdlib.h>

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