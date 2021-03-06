#include "IsWinEvent.h"
#include "AppMacros.h"

void IsWinEvent::happen()
{
	int checkId=NO_EVENT_FLAG, winNext=this->next;

	if(args->count()<1) 
		CCLog("IsWinEvent should have an arg. Event Id: %d", this->id);
	CCInteger* iLine=(CCInteger*)args->objectAtIndex(0);
	checkId=iLine->getValue();

	if(args->count()>=2)
	{
		CCInteger* iNext=(CCInteger*)args->objectAtIndex(1);
		winNext=iNext->getValue();
	}

	if (Combat::gameWinner == MOSTER_WIN_FLAG)
	{
		sGlobal->doneList[checkId]=false;
		for(int i=0;i<sGlobal->doneIdSed->count();i++)
		{
			CCInteger* intg=(CCInteger*)sGlobal->doneIdSed->objectAtIndex(i);
			if(intg->getValue()==checkId)
				sGlobal->doneIdSed->removeObject(intg);
		}
	}
	else if(winNext!=NO_EVENT_FLAG)
		this->next=winNext;
}

