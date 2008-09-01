/*
 *	server/zone/managers/bank/BankManager.cpp generated by engine3 IDL compiler 0.55
 */

#include "BankManager.h"

#include "BankManagerImplementation.h"

#include "../../objects/player/Player.h"

#include "server/zone/ZoneServer.h"

/*
 *	BankManagerStub
 */

BankManager::BankManager(ZoneServer* server, ZoneProcessServerImplementation* processor) {
	_impl = new BankManagerImplementation(server, processor);
	_impl->_setStub(this);
}

BankManager::BankManager(DummyConstructorParameter* param) {
	_impl = NULL;
}

BankManager::~BankManager() {
}

bool BankManager::isBankTerminal(long long objectid) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addSignedLongParameter(objectid);

		return method.executeWithBooleanReturn();
	} else
		return ((BankManagerImplementation*) _impl)->isBankTerminal(objectid);
}

/*
 *	BankManagerAdapter
 */

BankManagerAdapter::BankManagerAdapter(BankManagerImplementation* obj) : DistributedObjectAdapter((DistributedObjectServant*) obj) {
}

Packet* BankManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertBoolean(isBankTerminal(inv->getSignedLongParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

bool BankManagerAdapter::isBankTerminal(long long objectid) {
	return ((BankManagerImplementation*) impl)->isBankTerminal(objectid);
}

/*
 *	BankManagerHelper
 */

BankManagerHelper* BankManagerHelper::staticInitializer = BankManagerHelper::instance();

BankManagerHelper::BankManagerHelper() {
	className = "BankManager";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void BankManagerHelper::finalizeHelper() {
	BankManagerHelper::finalize();
}

DistributedObject* BankManagerHelper::instantiateObject() {
	return new BankManager(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* BankManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new BankManagerAdapter((BankManagerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	BankManagerServant
 */

BankManagerServant::BankManagerServant() {
	_classHelper = BankManagerHelper::instance();
}

BankManagerServant::~BankManagerServant() {
}

void BankManagerServant::_setStub(DistributedObjectStub* stub) {
	_this = (BankManager*) stub;
}

DistributedObjectStub* BankManagerServant::_getStub() {
	return _this;
}

