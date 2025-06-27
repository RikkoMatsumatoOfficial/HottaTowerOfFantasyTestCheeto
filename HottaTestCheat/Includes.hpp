#pragma once

#include <MinHook.h>
#include <SDK.hpp> //SDK by ME(HottaSDK)
#include <Windows.h>
#include <iostream>
using namespace std;
using namespace SDK;
void(__fastcall* oProcessEvent)(UObject*, UFunction*, void*);
bool MinHookInit() {
	if (MH_Initialize() == MH_OK) {
		return true;
	}
	else {
		return false;
	}
}

void __fastcall hProcessEvent(UObject* Context, UFunction* Function, void* Parms) {
	__try {
		if (!Context || !Function || !Function->VTable) 
		{
			return oProcessEvent(Context, Function, Parms);
		}
		else {
			return oProcessEvent(Context, Function, Parms);
		}
		return oProcessEvent(Context, Function, Parms);
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		MessageBoxA(0, "Due to Limitation of this Game(AntiCheat Basic Level with AntiDebugger), This Cheeto is Crashed!!!", "HottaTestCheat", MB_OK | MB_ICONERROR);
		exit(45);
	}
	
}
