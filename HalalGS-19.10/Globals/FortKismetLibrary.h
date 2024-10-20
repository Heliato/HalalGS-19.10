#pragma once

/*
	- 
*/

namespace FortKismetLibrary
{
	void InitFortKismetLibrary()
	{
		UFortKismetLibrary* FortKismetLibraryDefault = UFortKismetLibrary::GetDefaultObj();

		FN_LOG(LogInit, Log, "InitFortKismetLibrary Success!");
	}
}