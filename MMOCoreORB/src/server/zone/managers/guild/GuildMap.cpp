/*
 *	server/zone/managers/guild/GuildMap.cpp generated by engine3 IDL compiler 0.55
 */

#include "GuildMap.h"

#include "GuildMapImplementation.h"

#include "../../objects/guild/Guild.h"

/*
 *	GuildMapStub
 */

GuildMap::GuildMap() {
	_impl = new GuildMapImplementation();
	_impl->_setStub(this);
}

GuildMap::GuildMap(DummyConstructorParameter* param) {
	_impl = NULL;
}

GuildMap::~GuildMap() {
}

void GuildMap::add(Guild* guild) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(guild);

		method.executeWithVoidReturn();
	} else
		((GuildMapImplementation*) _impl)->add(guild);
}

Guild* GuildMap::get(int index) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addSignedIntParameter(index);

		return (Guild*) method.executeWithObjectReturn();
	} else
		return ((GuildMapImplementation*) _impl)->get(index);
}

Guild* GuildMap::get(unsigned int gid) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addUnsignedIntParameter(gid);

		return (Guild*) method.executeWithObjectReturn();
	} else
		return ((GuildMapImplementation*) _impl)->get(gid);
}

Guild* GuildMap::get(string& tag) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addAsciiParameter(tag);

		return (Guild*) method.executeWithObjectReturn();
	} else
		return ((GuildMapImplementation*) _impl)->get(tag);
}

void GuildMap::remove(unsigned int gid) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addUnsignedIntParameter(gid);

		method.executeWithVoidReturn();
	} else
		((GuildMapImplementation*) _impl)->remove(gid);
}

void GuildMap::removeAll() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		method.executeWithVoidReturn();
	} else
		((GuildMapImplementation*) _impl)->removeAll();
}

int GuildMap::size() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithSignedIntReturn();
	} else
		return ((GuildMapImplementation*) _impl)->size();
}

/*
 *	GuildMapAdapter
 */

GuildMapAdapter::GuildMapAdapter(GuildMapImplementation* obj) : DistributedObjectAdapter((DistributedObjectServant*) obj) {
}

Packet* GuildMapAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		add((Guild*) inv->getObjectParameter());
		break;
	case 7:
		resp->insertLong(get(inv->getSignedIntParameter())->_getObjectID());
		break;
	case 8:
		resp->insertLong(get(inv->getUnsignedIntParameter())->_getObjectID());
		break;
	case 9:
		resp->insertLong(get(inv->getAsciiParameter(_param0_get__string_))->_getObjectID());
		break;
	case 10:
		remove(inv->getUnsignedIntParameter());
		break;
	case 11:
		removeAll();
		break;
	case 12:
		resp->insertSignedInt(size());
		break;
	default:
		return NULL;
	}

	return resp;
}

void GuildMapAdapter::add(Guild* guild) {
	return ((GuildMapImplementation*) impl)->add(guild);
}

Guild* GuildMapAdapter::get(int index) {
	return ((GuildMapImplementation*) impl)->get(index);
}

Guild* GuildMapAdapter::get(unsigned int gid) {
	return ((GuildMapImplementation*) impl)->get(gid);
}

Guild* GuildMapAdapter::get(string& tag) {
	return ((GuildMapImplementation*) impl)->get(tag);
}

void GuildMapAdapter::remove(unsigned int gid) {
	return ((GuildMapImplementation*) impl)->remove(gid);
}

void GuildMapAdapter::removeAll() {
	return ((GuildMapImplementation*) impl)->removeAll();
}

int GuildMapAdapter::size() {
	return ((GuildMapImplementation*) impl)->size();
}

/*
 *	GuildMapHelper
 */

GuildMapHelper* GuildMapHelper::staticInitializer = GuildMapHelper::instance();

GuildMapHelper::GuildMapHelper() {
	className = "GuildMap";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void GuildMapHelper::finalizeHelper() {
	GuildMapHelper::finalize();
}

DistributedObject* GuildMapHelper::instantiateObject() {
	return new GuildMap(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* GuildMapHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new GuildMapAdapter((GuildMapImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	GuildMapServant
 */

GuildMapServant::GuildMapServant() {
	_classHelper = GuildMapHelper::instance();
}

GuildMapServant::~GuildMapServant() {
}

void GuildMapServant::_setStub(DistributedObjectStub* stub) {
	_this = (GuildMap*) stub;
}

DistributedObjectStub* GuildMapServant::_getStub() {
	return _this;
}

