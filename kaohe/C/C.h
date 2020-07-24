#ifndef _C_H
#define _C_H

#ifdef DLL_C
#define		DLL_IMPORT_EXPORT	extern "C" __declspec(dllexport)	
#else
#define		DLL_IMPORT_EXPORT	extern "C" __declspec(dllimport)		
#endif
DLL_IMPORT_EXPORT	int chen(int a, int b);

#endif