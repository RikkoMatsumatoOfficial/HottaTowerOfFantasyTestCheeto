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
	try 
	{
		if (!Context || !Function || !Function->VTable) 
		{
			cout << "Called Successfully!!!" << endl;
			return oProcessEvent(Context, Function, Parms);
		}
		else 
		{
			cout << "Called Successfully!!!" << endl;
			return oProcessEvent(Context, Function, Parms);
		}
		cout << "Called Successfully!!!!" << endl;
		return oProcessEvent(Context, Function, Parms);
	}
	catch(std::exception& cx) 
	{
		const char* zjhn = cx.what();
		MessageBoxA(0, zjhn, "HottaTestCheat", MB_OK | MB_ICONERROR);
		exit(45);
	}
	
}
