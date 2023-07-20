#ifndef FUNCS_H
#define FUNCS_H
long get_file_size(char *);
int GetListLength(struct List *);
void getParentPath(char *, char *, int);
void getNameFromPath(char *, char *, unsigned int);
STRPTR longToString(long);
STRPTR intToString(int);
STRPTR ULongToString(ULONG);
STRPTR floatToString(float);
int presentageFromInts(int, int);
int stringToInt(char *);
int longToInt(long);
BOOL clearList(struct List);
BOOL clearPointerList(struct List *);
ULONG stringToULONG(char *);
float presentageFromULongs(ULONG, ULONG, STRPTR, STRPTR);
#endif