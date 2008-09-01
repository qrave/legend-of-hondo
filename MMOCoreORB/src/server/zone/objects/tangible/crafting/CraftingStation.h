/*
 *	server/zone/objects/tangible/crafting/CraftingStation.h generated by engine3 IDL compiler 0.55
 */

#ifndef CRAFTINGSTATION_H_
#define CRAFTINGSTATION_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/service/Message.h"

class Player;

class CreatureObject;

class TangibleObject;

#include "../TangibleObject.h"

class CraftingStation : public TangibleObject {
public:
	CraftingStation(unsigned long long oid, unsigned int tempCRC, const unicode& n, const string& tempn);

	CraftingStation(CreatureObject* creature, unsigned int tempCRC, const unicode& n, const string& tempn);

	void generateAttributes(Player* player);

	int useObject(Player* player);

	void setEffectiveness(float eff);

	float getEffectiveness();

	int getStationType();

protected:
	CraftingStation(DummyConstructorParameter* param);

	virtual ~CraftingStation();

	friend class CraftingStationHelper;
};

class CraftingStationImplementation;

class CraftingStationAdapter : public TangibleObjectAdapter {
public:
	CraftingStationAdapter(CraftingStationImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void generateAttributes(Player* player);

	int useObject(Player* player);

	void setEffectiveness(float eff);

	float getEffectiveness();

	int getStationType();

};

class CraftingStationHelper : public DistributedObjectClassHelper, public Singleton<CraftingStationHelper> {
	static CraftingStationHelper* staticInitializer;

public:
	CraftingStationHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<CraftingStationHelper>;
};

#include "../TangibleObjectImplementation.h"

class CraftingStationServant : public TangibleObjectImplementation {
public:
	CraftingStation* _this;

public:
	CraftingStationServant(unsigned long long oid, const unicode& n, const string& tempn, unsigned int tempCRC, int tp);
	CraftingStationServant(CreatureObject* creature, const unicode& n, const string& tempn, unsigned int tempCRC, int tp);
	virtual ~CraftingStationServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*CRAFTINGSTATION_H_*/
