#pragma once

#include <windows.h>
#include <vector>
#include <Psapi.h>
#include <tchar.h>
#include <cstdint>
#include <iostream>
#include <tlhelp32.h>


std::vector<std::string> GetProcesses(void);