#include <proto/intuition.h>
#ifndef SCAN_H
#define SCAN_H

extern char pastPath[256]; // This is the path that was last Scanned


void scanPath(char *, BOOL, Object *);

#endif