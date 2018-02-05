#include "types.h"  
#include <stdarg.h>
#include <windows.h>
#include <stdio.h>
#include "stdfax.h"
using namespace std;
FILE *h;
string fileName;
int L_DEBUG(string s)
{
	freopen(fileName.data(), "at+", stdout);
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	printf("%4d/%02d/%02d %02d:%02d:%02d:%03d ", sys.wYear, sys.wMonth, sys.wDay, sys.wHour
		, sys.wMinute, sys.wSecond, sys.wMilliseconds);
	printf("%d ", GetCurrentThreadId());
	cout << "[DEBUG]" << "[" << __FILE__ << ":" << __LINE__ << "]" << s << endl;
	return 0;
}
int  L_INIT(char * s)
{
	fileName = s;
	h = fopen(s, "at+");
	return 0;
}
int L_INFO(string s)
{
	freopen(fileName.data(), "at+", stdout);
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	printf("%4d/%02d/%02d %02d:%02d:%02d:%03d ", sys.wYear, sys.wMonth, sys.wDay, sys.wHour
		, sys.wMinute, sys.wSecond, sys.wMilliseconds);
	printf("%d ", GetCurrentThreadId());
	cout << "[INFO]" << "[" << __FILE__ << ":" << __LINE__ << "]" << s << endl;
	return 0;
}
int L_ERROR(string s)
{
	freopen(fileName.data(), "at+", stdout);
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	printf("%4d/%02d/%02d %02d:%02d:%02d:%03d ", sys.wYear, sys.wMonth, sys.wDay, sys.wHour
		, sys.wMinute, sys.wSecond, sys.wMilliseconds);
	printf("%d ", GetCurrentThreadId());
	cout << "[ERROR]" << "[" << __FILE__ << ":" << __LINE__ << "]" << s << endl;
	return 0;
}
int main()
{
	L_INIT("my.txt");
	L_DEBUG("HELLO WORLD");
	L_INFO("HELLO WORLD");
	L_ERROR("HELLO WORLD");
	L_UNINIT();
	return 0;
}
int  L_UNINIT()
{
	fclose(h);
	return 0;
}