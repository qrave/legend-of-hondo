/*
 *	server/zone/ZoneClient.cpp generated by engine3 IDL compiler 0.55
 */

#include "ZoneClient.h"

#include "ZoneClientImplementation.h"

#include "ZoneServer.h"

#include "objects/player/Player.h"

/*
 *	ZoneClientStub
 */

ZoneClient::ZoneClient(DatagramServiceThread* server, Socket* sock, SocketAddress* addr) {
	_impl = new ZoneClientImplementation(server, sock, addr);
	_impl->_setStub(this);
}

ZoneClient::ZoneClient(DummyConstructorParameter* param) {
	_impl = NULL;
}

ZoneClient::~ZoneClient() {
}

void ZoneClient::disconnect(bool doLock) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addBooleanParameter(doLock);

		method.executeWithVoidReturn();
	} else
		((ZoneClientImplementation*) _impl)->disconnect(doLock);
}

void ZoneClient::closeConnection(bool doLock) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addBooleanParameter(doLock);

		method.executeWithVoidReturn();
	} else
		((ZoneClientImplementation*) _impl)->closeConnection(doLock);
}

void ZoneClient::sendMessage(BaseMessage* msg) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(msg);

		method.executeWithVoidReturn();
	} else
		((ZoneClientImplementation*) _impl)->sendMessage(msg);
}

void ZoneClient::sendMessage(StandaloneBaseMessage* msg) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(msg);

		method.executeWithVoidReturn();
	} else
		((ZoneClientImplementation*) _impl)->sendMessage(msg);
}

void ZoneClient::resetPacketCheckupTime() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		method.executeWithVoidReturn();
	} else
		((ZoneClientImplementation*) _impl)->resetPacketCheckupTime();
}

void ZoneClient::balancePacketCheckupTime() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		method.executeWithVoidReturn();
	} else
		((ZoneClientImplementation*) _impl)->balancePacketCheckupTime();
}

void ZoneClient::info(const string& msg, bool foredLog) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addAsciiParameter(msg);
		method.addBooleanParameter(foredLog);

		method.executeWithVoidReturn();
	} else
		((ZoneClientImplementation*) _impl)->info(msg, foredLog);
}

void ZoneClient::setPlayer(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ZoneClientImplementation*) _impl)->setPlayer(player);
}

Player* ZoneClient::getPlayer() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		return (Player*) method.executeWithObjectReturn();
	} else
		return ((ZoneClientImplementation*) _impl)->getPlayer();
}

bool ZoneClient::isAvailable() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		return method.executeWithBooleanReturn();
	} else
		return ((ZoneClientImplementation*) _impl)->isAvailable();
}

string& ZoneClient::getAddress() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		method.executeWithAsciiReturn(_return_getAddress);
		return _return_getAddress;
	} else
		return ((ZoneClientImplementation*) _impl)->getAddress();
}

unsigned int ZoneClient::getSessionKey() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((ZoneClientImplementation*) _impl)->getSessionKey();
}

/*
 *	ZoneClientAdapter
 */

ZoneClientAdapter::ZoneClientAdapter(ZoneClientImplementation* obj) : DistributedObjectAdapter((DistributedObjectServant*) obj) {
}

Packet* ZoneClientAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		disconnect(inv->getBooleanParameter());
		break;
	case 7:
		closeConnection(inv->getBooleanParameter());
		break;
	case 8:
		sendMessage((BaseMessage*) inv->getObjectParameter());
		break;
	case 9:
		sendMessage((StandaloneBaseMessage*) inv->getObjectParameter());
		break;
	case 10:
		resetPacketCheckupTime();
		break;
	case 11:
		balancePacketCheckupTime();
		break;
	case 12:
		info(inv->getAsciiParameter(_param0_info__string_bool_), inv->getBooleanParameter());
		break;
	case 13:
		setPlayer((Player*) inv->getObjectParameter());
		break;
	case 14:
		resp->insertLong(getPlayer()->_getObjectID());
		break;
	case 15:
		resp->insertBoolean(isAvailable());
		break;
	case 16:
		resp->insertAscii(getAddress());
		break;
	case 17:
		resp->insertInt(getSessionKey());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ZoneClientAdapter::disconnect(bool doLock) {
	return ((ZoneClientImplementation*) impl)->disconnect(doLock);
}

void ZoneClientAdapter::closeConnection(bool doLock) {
	return ((ZoneClientImplementation*) impl)->closeConnection(doLock);
}

void ZoneClientAdapter::sendMessage(BaseMessage* msg) {
	return ((ZoneClientImplementation*) impl)->sendMessage(msg);
}

void ZoneClientAdapter::sendMessage(StandaloneBaseMessage* msg) {
	return ((ZoneClientImplementation*) impl)->sendMessage(msg);
}

void ZoneClientAdapter::resetPacketCheckupTime() {
	return ((ZoneClientImplementation*) impl)->resetPacketCheckupTime();
}

void ZoneClientAdapter::balancePacketCheckupTime() {
	return ((ZoneClientImplementation*) impl)->balancePacketCheckupTime();
}

void ZoneClientAdapter::info(const string& msg, bool foredLog) {
	return ((ZoneClientImplementation*) impl)->info(msg, foredLog);
}

void ZoneClientAdapter::setPlayer(Player* player) {
	return ((ZoneClientImplementation*) impl)->setPlayer(player);
}

Player* ZoneClientAdapter::getPlayer() {
	return ((ZoneClientImplementation*) impl)->getPlayer();
}

bool ZoneClientAdapter::isAvailable() {
	return ((ZoneClientImplementation*) impl)->isAvailable();
}

string& ZoneClientAdapter::getAddress() {
	return ((ZoneClientImplementation*) impl)->getAddress();
}

unsigned int ZoneClientAdapter::getSessionKey() {
	return ((ZoneClientImplementation*) impl)->getSessionKey();
}

/*
 *	ZoneClientHelper
 */

ZoneClientHelper* ZoneClientHelper::staticInitializer = ZoneClientHelper::instance();

ZoneClientHelper::ZoneClientHelper() {
	className = "ZoneClient";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ZoneClientHelper::finalizeHelper() {
	ZoneClientHelper::finalize();
}

DistributedObject* ZoneClientHelper::instantiateObject() {
	return new ZoneClient(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ZoneClientHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ZoneClientAdapter((ZoneClientImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	ZoneClientServant
 */

ZoneClientServant::ZoneClientServant() {
	_classHelper = ZoneClientHelper::instance();
}

ZoneClientServant::~ZoneClientServant() {
}

void ZoneClientServant::_setStub(DistributedObjectStub* stub) {
	_this = (ZoneClient*) stub;
}

DistributedObjectStub* ZoneClientServant::_getStub() {
	return _this;
}

