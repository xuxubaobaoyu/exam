#ifndef _B_H
#define _B_H

#ifdef DLL_B
#define		DLL_IMPORT_EXPORT	__declspec(dllexport)	
#else
#define		DLL_IMPORT_EXPORT	__declspec(dllimport)		
#endif
extern "C" DLL_IMPORT_EXPORT	double sub_B(double a, double b);

#endif