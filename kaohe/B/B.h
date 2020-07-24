#ifndef _B_H
#define _B_H

#ifdef DLL_A
#define		DLL_IMPORT_EXPORT	__declspec(dllexport)	
#else
#define		DLL_IMPORT_EXPORT	__declspec(dllimport)		
#endif
DLL_IMPORT_EXPORT	int sub(int a, int b);

#endif