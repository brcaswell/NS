#include "GammaTable.h"

// Include windows gamma functions
#ifdef _WIN32
#include "winsani_in.h"
#include <windows.h>
#include "winuser.h"
#include "winsani_out.h"
#endif

GammaTable::GammaTable()
{
	this->mSlope = 1.0f;
	//this->InitializeToFlat(); // will cause @linux client to crash at start
	this->mDirect3DMode = false;
}

GammaTable::~GammaTable()
{
}

float GammaTable::GetGammaSlope() const
{
	return this->mSlope;
}

void GammaTable::InitializeToFlat()
{
	this->mSlope = 1.0f;
	
	for(int j = 0; j < 3; j++)
	{
		for(int i = 0; i < 256; i++)
		{
			int theBaseOffset = j*256 + i;
			uint8 theNewColor = (uint8)i;
			uint16 theNewWord = theNewColor << 8;
			
			((uint16*)this->mBaseData)[theBaseOffset] = theNewWord;
			((uint16*)this->mSlopeData)[theBaseOffset] = theNewWord;
		}
	}
}
#ifdef _WIN32
bool GammaTable::InitializeFromVideoState()
{
	bool theSuccess = false;

	if(!this->mDirect3DMode)
	{
		HDC theDC = GetDC(NULL); // evil
		if(theDC != 0)
		{
			// Read current settings in
			if(GetDeviceGammaRamp(theDC, this->mBaseData) == TRUE) // more evil
			{
				// Copy to base data also
				memcpy(this->mSlopeData, this->mBaseData, kGammaTableSize*sizeof(char));
		
				// This may not actually be one, but we treat one as the base state always
				this->mSlope = 1.0f;
		
				theSuccess = true;
			}
		
			if(!ReleaseDC(NULL, theDC))
			{
				// emit error about leak
			}
		}
	}	
	return theSuccess;
}

bool GammaTable::InitializeToVideoState()
{
	bool theSuccess = false;

	if(!this->mDirect3DMode)
	{
		HDC theDC = GetDC(NULL);
		if(theDC != 0)
		{
            // Multi-monitor support returns false for some reason, even though it seems to work
            #define SM_CMONITORS 80
            bool theIgnoreErrorCode = (GetSystemMetrics(SM_CMONITORS) > 1);
            bool theSetGammaRamp = (SetDeviceGammaRamp(theDC, this->mSlopeData) == TRUE);

			// Restore original gamma ramp
			if(theSetGammaRamp || theIgnoreErrorCode)
			{
				theSuccess = true;
			}

			if(!ReleaseDC(NULL, theDC))
			{
				// emit error about leak
			}
		}
	}	
	return theSuccess;
}
#endif
void GammaTable::ProcessSlope(float inSlope)
{
	this->mSlope = inSlope;

	// Steepen and saturate, ala Q3
	uint8 kMaxValue = uint8(-1);
	for(int j = 0; j < 3; j++)
	{
		for(int i = 0; i < 256; i++)
		{
			int theBaseOffset = j*256 + i;
			uint16 theWord = ((uint16*)this->mBaseData)[theBaseOffset];
			uint8 theBaseColor = (theWord & 0xFF00) >> 8;
			uint8 theNewColor = (uint8)min(theBaseColor*inSlope, (float)kMaxValue);
			uint16 theNewWord = theNewColor << 8;
			((uint16*)this->mSlopeData)[theBaseOffset] = theNewWord;
		}
	}
}
