#pragma once

#include <windows.h>
#include <Psapi.h>
#include <tchar.h>
#include <cstdint>
#include <iostream>
#include <tlhelp32.h>

// If i can open a handle to the app, then it is running
bool IsAppRunning(std::string app);