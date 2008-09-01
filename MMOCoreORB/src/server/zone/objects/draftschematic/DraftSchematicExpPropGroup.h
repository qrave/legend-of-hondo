/*
 *	server/zone/objects/draftschematic/DraftSchematicExpPropGroup.h generated by engine3 IDL compiler 0.55
 */

#ifndef DRAFTSCHEMATICEXPPROPGROUP_H_
#define DRAFTSCHEMATICEXPPROPGROUP_H_

#include "engine/orb/DistributedObjectBroker.h"

class ObjectControllerMessage;

class DraftSchematicExpPropGroup : public DistributedObjectStub {
public:
	DraftSchematicExpPropGroup();

	void addExperimentalProperty(const string& experimentalPropertyType, unsigned int weight);

	void sendToPlayer(ObjectControllerMessage* msg, int count);

	bool containsExpPropType(const string& expPropType);

	float getExpPropPercentage(const string& expPropType);

	unsigned int getExpPropPercentageListSize();

	float getExpPropPercentage(unsigned int index);

	unsigned char getTypeAndWeight(unsigned int index);

protected:
	DraftSchematicExpPropGroup(DummyConstructorParameter* param);

	virtual ~DraftSchematicExpPropGroup();

	friend class DraftSchematicExpPropGroupHelper;
};

class DraftSchematicExpPropGroupImplementation;

class DraftSchematicExpPropGroupAdapter : public DistributedObjectAdapter {
public:
	DraftSchematicExpPropGroupAdapter(DraftSchematicExpPropGroupImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void addExperimentalProperty(const string& experimentalPropertyType, unsigned int weight);

	void sendToPlayer(ObjectControllerMessage* msg, int count);

	bool containsExpPropType(const string& expPropType);

	float getExpPropPercentage(const string& expPropType);

	unsigned int getExpPropPercentageListSize();

	float getExpPropPercentage(unsigned int index);

	unsigned char getTypeAndWeight(unsigned int index);

protected:
	string _param0_addExperimentalProperty__string_int_;
	string _param0_containsExpPropType__string_;
	string _param0_getExpPropPercentage__string_;
};

class DraftSchematicExpPropGroupHelper : public DistributedObjectClassHelper, public Singleton<DraftSchematicExpPropGroupHelper> {
	static DraftSchematicExpPropGroupHelper* staticInitializer;

public:
	DraftSchematicExpPropGroupHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<DraftSchematicExpPropGroupHelper>;
};

class DraftSchematicExpPropGroupServant : public DistributedObjectServant {
public:
	DraftSchematicExpPropGroup* _this;

public:
	DraftSchematicExpPropGroupServant();
	virtual ~DraftSchematicExpPropGroupServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*DRAFTSCHEMATICEXPPROPGROUP_H_*/
