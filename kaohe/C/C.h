#ifndef _C_H
#define _C_H

#ifdef DLL_C
#define		DLL_IMPORT_EXPORT	 __declspec(dllexport)	
#else
#define		DLL_IMPORT_EXPORT	 __declspec(dllimport)		
#endif
extern "C"	DLL_IMPORT_EXPORT	int chen(int a, int b);

#endif