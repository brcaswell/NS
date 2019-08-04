#ifndef AVHREINFORCEABLE_H
#define AVHREINFORCEABLE_H

#include "../util/nowarnings.h"
#include "../dlls/extdll.h"
#include "../dlls/util.h"
#include "AvHConstants.h"
#include "AvHBuildable.h"
#include "../dlls/cbase.h"
#include "AvHMessage.h"
#include "AvHSpecials.h"
#include "AvHPlayer.h"

class AvHReinforceable
{
public:
					AvHReinforceable();

	virtual void	CueRespawnEffect(AvHPlayer* inPlayer);
					
	virtual bool	GetCanReinforce() const = 0;

	virtual bool	GetSpawnLocationForPlayer(CBaseEntity* inPlayer, Vector& outLocation) const = 0;

	virtual AvHTeamNumber	GetReinforceTeamNumber() const = 0;

	AvHPlayer*		GetReinforcingPlayer();

	virtual float	GetReinforceTime() const;
	
	virtual void	ResetEntity(void);
	
	virtual void	UpdateReinforcements();

protected:
	virtual void	ResetReinforcingPlayer(bool inSuccess);
	
private:
	
	int				mReinforcingPlayer;
	float			mLastTimeReinforced;

};

#endif
