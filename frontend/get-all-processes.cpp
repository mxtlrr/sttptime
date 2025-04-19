#include "get-all-processes.hpp"

std::vector<std::string> GetProcesses(void){
  std::vector<std::string> fk;


  HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);

	if (Process32First(hSnapshot, &pe)) {
		do {
      fk.push_back(std::string(pe.szExeFile));
		} while (Process32Next(hSnapshot, &pe));
	}

	CloseHandle(hSnapshot);
  return fk;
}