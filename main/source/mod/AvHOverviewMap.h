#ifndef AVHOVERVIEWMAP_H
#define AVHOVERVIEWMAP_H

#include "AvHEntityHierarchy.h"
#include "AvHMapExtents.h"
#include "AvHOrder.h"
#include <list>

class DrawableEntity
{
public:
	DrawableEntity() : mUser3(AVH_USER3_NONE), mIsAlive(true), mX(0), mY(0), mAngleRadians(0), mIsLocalPlayer(false), mEntityNumber(0), mTeam(TEAM_IND), mSquadNumber(0), mIsUnderAttack(0), mPlayerSlot(0), mHealth(0)
	{}
	
	AvHUser3	    mUser3;
	bool		    mIsAlive;
	bool			mIsUnderAttack;
	int			    mX;
	int			    mY;
    AvHTeamNumber   mTeam;
	float	  	    mAngleRadians;
	bool		    mIsLocalPlayer;
	int			    mEntityNumber;
    int             mSquadNumber;
    int             mPlayerSlot; // todo currently mEntityNumber is used which is not necessarily equal to the PlayerSlot
    int             mHealth; //todo
};

class AvHOverviewMap
{										                                                                                                            
public:

    struct DrawInfo
    {

        int mX;
        int mY;
        int mWidth;
        int mHeight;
    
        float mViewWorldMinX;
        float mViewWorldMinY;
        float mViewWorldMaxX;
        float mViewWorldMaxY;

		float mZoomScale;
        bool mFullScreen;
        bool mCommander;
    };
    
    std::vector<std::vector<int>> player_colors = {
   // {255,0,0}, {0,255,0}, {0,0,255}, {2,181,160}, {249, 175,31}, {0,0,0}, {118,122,121}
   //   {255,192,203}, {0,255,0}, {0,0,255}, {2,181,160}, {249, 175,31}, {255,255,255}
    //    {154,5,102},{199,131,7},{17,59,132},{136,188,6},{203,203,203},{0,0,0,0}
        {191,23,170},{255,148,31},{28,136,177},{203,247,30},{203,203,203},{0,0,0,0}
    };
    std::list<int> players_marine_team;
    std::list<int> players_alien_team;
    int m_pColorIndex = -1;
    int thePlayerId = -1;
                                    AvHOverviewMap();

	void							Clear();

	bool							GetHasData() const;
	void							GetWorldPosFromMouse(const DrawInfo& inDrawInfo, int inMouseX, int inMouseY, float& outWorldX, float& outWorldY);
	
    void							SetMapExtents(const string& inMapName, const AvHMapExtents& inMapExtents);
	void                            GetMapExtents(AvHMapExtents& outMapExtents);
    
    void							SetUser3(AvHUser3 inUser3);
	void							SetWorldPosition(float inWorldX, float inWorldY);
    void                            GetWorldPosition(float& outWorldX, float& outWorldY);
	
	void							Update(float inCurrentTime);
	void                            UpdateOrders(const OrderListType& inOrderList, const EntityListType& inDrawPlayers);
    void							VidInit(void);

    void                            AddAlert(float x, float y);

    void                            Draw(const DrawInfo& inDrawInfo);

    int                             GetEntityAtWorldPosition(float inWorldX, float inWorldY, float inRadius) const;

protected:
	void							KillOldAlerts(float inCurrentTime);
	
    void							DrawMiniMap(const DrawInfo& inDrawInfo);
	void							DrawMiniMapEntity(const DrawInfo& inDrawInfo, const DrawableEntity& inEntity);
    void                            DrawAlerts(const DrawInfo& inDrawInfo);

	AvHUser3						mUser3;
    AvHTeamNumber                   mTeam;
	// : 1066 the name of the last minimap we loaded
	int								mLastMinimap;	
private:
	
    void                            WorldToMiniMapCoords(const DrawInfo& inDrawInfo, float& x, float& y);

	void							Init();
    void                            GetSpriteForEntity(const DrawableEntity& entity, AVHHSPRITE& outSprite, int& outFrame, int& outRenderMode, bool commanderOverview);
    void                            GetColorForEntity(const DrawableEntity& entity, float& outR, float& outG, float& outB);
    
	void							UpdateDrawData(float inCurrentTime);

	float							mWorldPlayerX;
	float							mWorldPlayerY;

	float							mBlinkTime;
	bool							mBlinkOn;

	AvHMapExtents					mMapExtents;

	string							mMapName;
	int								mMiniMapSprite;

	AVHHSPRITE						mReticleSprite;
	
	typedef vector<DrawableEntity>	DrawableEntityListType;
	DrawableEntityListType			mDrawableEntityList;

    struct MapAlert
    {
        
        float mStartTime;
        float mExpireTime;
        
        float mX; // World space.
        float mY;

    };

    typedef std::vector<MapAlert>	MapAlertListType;
    MapAlertListType				mAlertList;

    struct MapOrder
    {
        float mX; // World space.
        float mY;
    };

    typedef std::vector<MapOrder>	MapOrderListType;
    MapOrderListType				mMapOrderList;

    float                           mLastUpdateTime;

};

#endif