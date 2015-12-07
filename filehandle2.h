#ifndef FILEHANDLE2_H_INCLUDED
#define FILEHANDLE2_H_INCLUDED

#include "main.h"
#define CHAR_BUF 2000

char* filename;

void LoadFile();

void OpenFile(char *fname);

void NewFile();

void SaveFile(char *fname);

void SaveFileAs();


#endif // FILEHANDLE2_H_INCLUDED
