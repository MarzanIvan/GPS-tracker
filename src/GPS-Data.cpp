#include "../include/GPS-Data.h"

bool DoesStringContainSubString( const char *Array, const char* SubString) {
	while (*Array) {
		if (*Array == (*SubString)) {
			const char *TempStr = Array;
			while (*TempStr == *SubString) {
				if (*TempStr != *SubString) {
					return false;
				}
				TempStr++;
				SubString++;
			}
			return true;
		}
		Array++;
	}
}