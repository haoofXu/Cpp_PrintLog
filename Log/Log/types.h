#include <iostream>
#include <string>
using namespace std;
//#define DLL_API _declspec(dllexport);

extern int  LOG_DEBUG(string s);
extern int  L_INIT(char *s);
extern int  L_UNINIT();
extern int L_ERROR(string s);
extern int L_INFO(string s);