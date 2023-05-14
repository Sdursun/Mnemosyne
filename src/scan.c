#include <stdio.h>
#include <stdlib.h>
#include "scan.h"
#include "funcs.h"
#include <proto/dos.h>

int scan(void)
{
    printf("Please enter the name of the file you want to scan: ");
    char name[100];
    scanf("%s", name);
    FILE *file;
    file = fopen(name, "r");
    if (file == NULL)
    {
        printf("File does not exist.\n");
        return 0;
    }
    else
    {
        printf("File exists.\n");

        printf("Scanning...\n");
        char *filename = name;
        printf(
            "Size of file `%s` is %ld bytes.\n",
            filename,
            get_file_size(filename));
    }

    return 0;
}

long totalSize = 0;

void scanPath(char *path){
    printf("Path: %s\n", path);
    BPTR lockPath = Lock(path, ACCESS_READ);
    if (!lockPath){
        printf("Path Doesn't Exist\n");
        return;
    }

    printf("Path Exists\n");

    // Check if path is file or folder with Examine()
    struct FileInfoBlock *fib;

    if (!Examine(lockPath, fib)){
        printf("Examine Failed on path: %s\n", path);
        goto exit;
    }

    // If file return size
    if(fib->fib_DirEntryType < 0){
        printf("%s: %ld bytes\n",fib->fib_FileName , fib->fib_Size);
        goto exit;
    }
    // If folder scan recursivly and return size for each child
    if(fib->fib_DirEntryType > 0){
        printf("This is a Directory\n");
        while(ExNext(lockPath, fib)){
            printf("%s: %ld bytes\n",fib->fib_FileName , fib->fib_Size);
            totalSize += fib->fib_Size;
            if(fib->fib_DirEntryType > 0){
                // TODO: Scan SubFolders

            }
        }
        printf("Total Size Of Path Given: %ld bytes", totalSize);

    }

exit:
    UnLock(lockPath);
    return;
}