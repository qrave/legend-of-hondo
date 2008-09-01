/*
 *	server/zone/objects/tangible/crafting/component/Component.cpp generated by engine3 IDL compiler 0.55
 */

#include "Component.h"

#include "ComponentImplementation.h"

#include "../../../player/Player.h"

#include "../../crafting/component/Component.h"

#include "../../../creature/CreatureObject.h"

#include "../../TangibleObject.h"

/*
 *	ComponentStub
 */

Component::Component(unsigned long long oid, unsigned int tempCRC, const unicode& n, const string& tempn) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new ComponentImplementation(oid, tempCRC, n, tempn);
	_impl->_setStub(this);
}

Component::Component(CreatureObject* creature, unsigned int tempCRC, const unicode& n, const string& tempn) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new ComponentImplementation(creature, tempCRC, n, tempn);
	_impl->_setStub(this);
}

Component::Component(DummyConstructorParameter* param) : TangibleObject(param) {
}

Component::~Component() {
}

void Component::sendTo(Player* player, bool doClose) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);
		method.addBooleanParameter(doClose);

		method.executeWithVoidReturn();
	} else
		((ComponentImplementation*) _impl)->sendTo(player, doClose);
}

void Component::generateAttributes(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ComponentImplementation*) _impl)->generateAttributes(player);
}

int Component::useObject(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);

		return method.executeWithSignedIntReturn();
	} else
		return ((ComponentImplementation*) _impl)->useObject(player);
}

Component* Component::cloneComponent(Component* component, unsigned long long oid) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(component);
		method.addUnsignedLongParameter(oid);

		return (Component*) method.executeWithObjectReturn();
	} else
		return ((ComponentImplementation*) _impl)->cloneComponent(component, oid);
}

/*
 *	ComponentAdapter
 */

ComponentAdapter::ComponentAdapter(ComponentImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* ComponentAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		sendTo((Player*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case 7:
		generateAttributes((Player*) inv->getObjectParameter());
		break;
	case 8:
		resp->insertSignedInt(useObject((Player*) inv->getObjectParameter()));
		break;
	case 9:
		resp->insertLong(cloneComponent((Component*) inv->getObjectParameter(), inv->getUnsignedLongParameter())->_getObjectID());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ComponentAdapter::sendTo(Player* player, bool doClose) {
	return ((ComponentImplementation*) impl)->sendTo(player, doClose);
}

void ComponentAdapter::generateAttributes(Player* player) {
	return ((ComponentImplementation*) impl)->generateAttributes(player);
}

int ComponentAdapter::useObject(Player* player) {
	return ((ComponentImplementation*) impl)->useObject(player);
}

Component* ComponentAdapter::cloneComponent(Component* component, unsigned long long oid) {
	return ((ComponentImplementation*) impl)->cloneComponent(component, oid);
}

/*
 *	ComponentHelper
 */

ComponentHelper* ComponentHelper::staticInitializer = ComponentHelper::instance();

ComponentHelper::ComponentHelper() {
	className = "Component";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ComponentHelper::finalizeHelper() {
	ComponentHelper::finalize();
}

DistributedObject* ComponentHelper::instantiateObject() {
	return new Component(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ComponentHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ComponentAdapter((ComponentImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	ComponentServant
 */

ComponentServant::ComponentServant(unsigned long long oid, const unicode& n, const string& tempn, unsigned int tempCRC, int tp) : TangibleObjectImplementation(oid, n, tempn, tempCRC, tp) {
	_classHelper = ComponentHelper::instance();
}

ComponentServant::ComponentServant(CreatureObject* creature, const unicode& n, const string& tempn, unsigned int tempCRC, int tp) : TangibleObjectImplementation(creature, n, tempn, tempCRC, tp) {
	_classHelper = ComponentHelper::instance();
}

ComponentServant::~ComponentServant() {
}

void ComponentServant::_setStub(DistributedObjectStub* stub) {
	_this = (Component*) stub;
	TangibleObjectServant::_setStub(stub);
}

DistributedObjectStub* ComponentServant::_getStub() {
	return _this;
}

