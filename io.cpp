#include <stdio.h>
#include <Windows.h>
#include <winbase.h>
#include <tchar.h>
#include <strsafe.h>

/* Charles Thomas Wallace Truscott Watters */
/* Byron Bay, NSW, 2481 Australia	   */
/* Github.com/r0ss1n1			   */


int main(void) {
	void * null_pointer;
	HANDLE hdisk = CreateFileW(L"\\\\.\\C:", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if (hdisk == INVALID_HANDLE_VALUE) {
		printf("CreateFile failed, sorry ..\n");
		printf("%d\n", GetLastError());
	} 

	LARGE_INTEGER position = { 0 };

	BOOL ok = SetFilePointerEx(hdisk, position, NULL, FILE_BEGIN);

	BYTE buffer[65536];
	DWORD read;
	ok = ReadFile(hdisk, buffer, 65536, &read, NULL);
	int i = 0;
	for(; i < 1000; ++i) {
		printf("%x\t", buffer[i]);
	}
	Sleep(3000);
	i = 0;
	for(; i < 65536; ++i) {
		printf("%c", buffer[i]);
	}
	return 0;
}