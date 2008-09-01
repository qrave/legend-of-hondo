/*
 *	server/zone/managers/planet/PlanetManager.h generated by engine3 IDL compiler 0.55
 */

#ifndef PLANETMANAGER_H_
#define PLANETMANAGER_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/util/Coordinate.h"

class Zone;

#include "server/zone/ZoneProcessServerImplementation.h"

class Player;

class ShuttleCreature;

class BuildingObject;

class CellObject;

class PlanetManager : public DistributedObjectStub {
public:
	PlanetManager(Zone* zone, ZoneProcessServerImplementation* processor);

	void init();

	void start();

	void stop();

	unsigned long long getNextStaticObjectID(bool doLock = true);

	void landShuttles();

	void takeOffShuttles();

	BuildingObject* findBuildingType(const string& word, float targetX, float targetY);

	ShuttleCreature* getShuttle(const string& Shuttle);

	void sendPlanetTravelPointListResponse(Player* player);

	CellObject* getCell(unsigned long long id);

	BuildingObject* getBuilding(unsigned long long id);

	unsigned long long getLandingTime();

	unsigned int getTravelFare(string& departurePlanet, string& arrivalPlanet);

protected:
	PlanetManager(DummyConstructorParameter* param);

	virtual ~PlanetManager();

	friend class PlanetManagerHelper;
};

class PlanetManagerImplementation;

class PlanetManagerAdapter : public DistributedObjectAdapter {
public:
	PlanetManagerAdapter(PlanetManagerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void init();

	void start();

	void stop();

	unsigned long long getNextStaticObjectID(bool doLock);

	void landShuttles();

	void takeOffShuttles();

	BuildingObject* findBuildingType(const string& word, float targetX, float targetY);

	ShuttleCreature* getShuttle(const string& Shuttle);

	void sendPlanetTravelPointListResponse(Player* player);

	CellObject* getCell(unsigned long long id);

	BuildingObject* getBuilding(unsigned long long id);

	unsigned long long getLandingTime();

	unsigned int getTravelFare(string& departurePlanet, string& arrivalPlanet);

protected:
	string _param0_findBuildingType__string_float_float_;
	string _param0_getShuttle__string_;
	string _param0_getTravelFare__string_string_;
	string _param1_getTravelFare__string_string_;
};

class PlanetManagerHelper : public DistributedObjectClassHelper, public Singleton<PlanetManagerHelper> {
	static PlanetManagerHelper* staticInitializer;

public:
	PlanetManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<PlanetManagerHelper>;
};

class PlanetManagerServant : public DistributedObjectServant {
public:
	PlanetManager* _this;

public:
	PlanetManagerServant();
	virtual ~PlanetManagerServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*PLANETMANAGER_H_*/
