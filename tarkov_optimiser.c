#include <windows.h>
#include <psapi.h>
#include <stdio.h>

//	Precompiled decision so that MAX_PROCESSES is instantly replaced with 1024 in the code
#define  MAX_PROCESSES 1024


//	Function for defining, labelling and filtering all PID's
void list_process_ids() {

	//	process_ids is DWORD (32 byte), and size of 1024, therefore 4096 bytes
	DWORD process_ids[MAX_PROCESSES];
	DWORD bytes_returned;


	if (!EnumProcesses(process_ids, sizeof(process_ids), &bytes_returned)) {
		printf("Failed to enumerate processes.\n");
		return;
	}

	DWORD num_processes = bytes_returned / sizeof(DWORD);

	for (DWORD i = 0; i < num_processes; i++) {

		DWORD pid = process_ids[i];

		//	Avoid System Idle Process placeholder which is pid 0
		if (pid == 0) continue;

		//	Attempt to open the process with lowest-level rights
		HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
		if (hProcess) {
			HMODULE hMod;
			DWORD cbNeeded;
		}





	}


}

int main() {


}