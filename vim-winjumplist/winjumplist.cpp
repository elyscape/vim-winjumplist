#include <sdkddkver.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <ShlObj.h>
#include <new>

extern "C" {
	__declspec(dllexport) _Ret_null_ LPCSTR addToJumpList(_In_ LPCSTR path);

	__declspec(dllexport) _Ret_null_ LPCSTR addToJumpList(_In_ LPCSTR path) {
		int length = MultiByteToWideChar(CP_UTF8, 0, path, -1, nullptr, 0);
		if (length == 0) {
			return nullptr;
		}

		LPWSTR widepath = nullptr;
		try {
			widepath = new WCHAR[length];
		}
		catch (std::bad_alloc) {
			SetLastError(ERROR_NOT_ENOUGH_MEMORY);
			return nullptr;
		}

		MultiByteToWideChar(CP_UTF8, 0, path, -1, widepath, length);
		widepath[length - 1] = 0;

		SHAddToRecentDocs(SHARD_PATHW, widepath);
		delete[] widepath;
		return nullptr;
	}
}
