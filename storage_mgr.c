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
    for (int i = 0; i < PAGE_SIZE; i++) {
        fputc('\0', file);
    }
    fclose(file);
    return RC_OK;


}

RC openPageFile(char *fileName, SM_FileHandle *fHandle) {
    // Try opening the file in read binary mode
    FILE *page = fopen(fileName, "rb");
    if (page == NULL) {
        printf("Error: File '%s' not found.\n", fileName);
        return RC_FILE_NOT_FOUND;  // Return "file not found" if open fails
    }
    else {
        // File opened successfully
        // printf("File '%s' opened successfully.\n", fileName);
        fseek(page, 0, SEEK_END);
        long fileSize = ftell(page);
        // printf("File size is %ld\n", fileSize);
        int no_of_pages = fileSize / PAGE_SIZE;
        // printf("Number of pages = %d\n", no_of_pages);
        fHandle -> fileName = fileName;
        fHandle -> curPagePos = 0;
        fHandle -> totalNumPages = no_of_pages;
        fHandle ->mgmtInfo = page;
        // printf("Current filename is %s\n", fHandle -> fileName);
        // printf("Current curPagePos is %d\n", fHandle -> curPagePos);
        // printf("Current totalNumPages is %d\n", fHandle -> totalNumPages);
        return RC_OK;
    }
}

RC closePageFile(SM_FileHandle *fHandle) {
    printf("Inside closePageFile()\n");

    // Check if SM_FileHandle -> fileName is not empty to validate that file was opened.

    if(fHandle -> fileName == NULL) {
        printf("Error: File '%s' not found.\n", fHandle -> fileName);
    }

    // Open file before closing it :/
    // mode = 'rb' and not 'r' because the file is a .bin file
    // 'r' is used to read text files, 'rb' for rest of the files.

    FILE *file = fopen(fHandle -> fileName, "rb");
    if(file == NULL) {
        return RC_FILE_NOT_FOUND;
    }
    if(fclose(file) !=0 ) {
        RC_message = "Error closing file";
        return RC_message;
    }
    return RC_OK;
}

RC destroyPageFile(char *fileName) {
    printf("Deleting file '%s'\n", fileName);
    // if (remove(fileName) != 0) {
    //     // RC_message = "Error deleting file";
    //     return RC_FILE_NOT_FOUND;
    // }
    remove(fileName);
    return RC_OK;
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