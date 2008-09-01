/*
 *	server/zone/objects/player/sui/SuiBox.cpp generated by engine3 IDL compiler 0.55
 */

#include "SuiBox.h"

#include "SuiBoxImplementation.h"

#include "../Player.h"

/*
 *	SuiBoxStub
 */

SuiBox::SuiBox(DummyConstructorParameter* param) {
	_impl = NULL;
}

SuiBox::~SuiBox() {
}

BaseMessage* SuiBox::generateCloseMessage() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		return (BaseMessage*) method.executeWithObjectReturn();
	} else
		return ((SuiBoxImplementation*) _impl)->generateCloseMessage();
}

void SuiBox::setPromptTitle(const string& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addAsciiParameter(name);

		method.executeWithVoidReturn();
	} else
		((SuiBoxImplementation*) _impl)->setPromptTitle(name);
}

void SuiBox::setPromptText(const string& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addAsciiParameter(name);

		method.executeWithVoidReturn();
	} else
		((SuiBoxImplementation*) _impl)->setPromptText(name);
}

void SuiBox::setCancelButton(bool value) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addBooleanParameter(value);

		method.executeWithVoidReturn();
	} else
		((SuiBoxImplementation*) _impl)->setCancelButton(value);
}

void SuiBox::setUsingObjectID(unsigned long long oid) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addUnsignedLongParameter(oid);

		method.executeWithVoidReturn();
	} else
		((SuiBoxImplementation*) _impl)->setUsingObjectID(oid);
}

bool SuiBox::isInputBox() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithBooleanReturn();
	} else
		return ((SuiBoxImplementation*) _impl)->isInputBox();
}

bool SuiBox::isListBox() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithBooleanReturn();
	} else
		return ((SuiBoxImplementation*) _impl)->isListBox();
}

bool SuiBox::isMessageBox() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		return method.executeWithBooleanReturn();
	} else
		return ((SuiBoxImplementation*) _impl)->isMessageBox();
}

bool SuiBox::isTransferBox() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		return method.executeWithBooleanReturn();
	} else
		return ((SuiBoxImplementation*) _impl)->isTransferBox();
}

bool SuiBox::isColorPicker() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		return method.executeWithBooleanReturn();
	} else
		return ((SuiBoxImplementation*) _impl)->isColorPicker();
}

bool SuiBox::isBankTransferBox() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		return method.executeWithBooleanReturn();
	} else
		return ((SuiBoxImplementation*) _impl)->isBankTransferBox();
}

unsigned long long SuiBox::getBoxID() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		return method.executeWithUnsignedLongReturn();
	} else
		return ((SuiBoxImplementation*) _impl)->getBoxID();
}

int SuiBox::getBoxTypeID() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);

		return method.executeWithSignedIntReturn();
	} else
		return ((SuiBoxImplementation*) _impl)->getBoxTypeID();
}

unsigned long long SuiBox::getUsingObjectID() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);

		return method.executeWithUnsignedLongReturn();
	} else
		return ((SuiBoxImplementation*) _impl)->getUsingObjectID();
}

Player* SuiBox::getPlayer() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);

		return (Player*) method.executeWithObjectReturn();
	} else
		return ((SuiBoxImplementation*) _impl)->getPlayer();
}

/*
 *	SuiBoxAdapter
 */

SuiBoxAdapter::SuiBoxAdapter(SuiBoxImplementation* obj) : DistributedObjectAdapter((DistributedObjectServant*) obj) {
}

Packet* SuiBoxAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertLong(generateCloseMessage()->_getObjectID());
		break;
	case 7:
		setPromptTitle(inv->getAsciiParameter(_param0_setPromptTitle__string_));
		break;
	case 8:
		setPromptText(inv->getAsciiParameter(_param0_setPromptText__string_));
		break;
	case 9:
		setCancelButton(inv->getBooleanParameter());
		break;
	case 10:
		setUsingObjectID(inv->getUnsignedLongParameter());
		break;
	case 11:
		resp->insertBoolean(isInputBox());
		break;
	case 12:
		resp->insertBoolean(isListBox());
		break;
	case 13:
		resp->insertBoolean(isMessageBox());
		break;
	case 14:
		resp->insertBoolean(isTransferBox());
		break;
	case 15:
		resp->insertBoolean(isColorPicker());
		break;
	case 16:
		resp->insertBoolean(isBankTransferBox());
		break;
	case 17:
		resp->insertLong(getBoxID());
		break;
	case 18:
		resp->insertSignedInt(getBoxTypeID());
		break;
	case 19:
		resp->insertLong(getUsingObjectID());
		break;
	case 20:
		resp->insertLong(getPlayer()->_getObjectID());
		break;
	default:
		return NULL;
	}

	return resp;
}

BaseMessage* SuiBoxAdapter::generateCloseMessage() {
	return ((SuiBoxImplementation*) impl)->generateCloseMessage();
}

void SuiBoxAdapter::setPromptTitle(const string& name) {
	return ((SuiBoxImplementation*) impl)->setPromptTitle(name);
}

void SuiBoxAdapter::setPromptText(const string& name) {
	return ((SuiBoxImplementation*) impl)->setPromptText(name);
}

void SuiBoxAdapter::setCancelButton(bool value) {
	return ((SuiBoxImplementation*) impl)->setCancelButton(value);
}

void SuiBoxAdapter::setUsingObjectID(unsigned long long oid) {
	return ((SuiBoxImplementation*) impl)->setUsingObjectID(oid);
}

bool SuiBoxAdapter::isInputBox() {
	return ((SuiBoxImplementation*) impl)->isInputBox();
}

bool SuiBoxAdapter::isListBox() {
	return ((SuiBoxImplementation*) impl)->isListBox();
}

bool SuiBoxAdapter::isMessageBox() {
	return ((SuiBoxImplementation*) impl)->isMessageBox();
}

bool SuiBoxAdapter::isTransferBox() {
	return ((SuiBoxImplementation*) impl)->isTransferBox();
}

bool SuiBoxAdapter::isColorPicker() {
	return ((SuiBoxImplementation*) impl)->isColorPicker();
}

bool SuiBoxAdapter::isBankTransferBox() {
	return ((SuiBoxImplementation*) impl)->isBankTransferBox();
}

unsigned long long SuiBoxAdapter::getBoxID() {
	return ((SuiBoxImplementation*) impl)->getBoxID();
}

int SuiBoxAdapter::getBoxTypeID() {
	return ((SuiBoxImplementation*) impl)->getBoxTypeID();
}

unsigned long long SuiBoxAdapter::getUsingObjectID() {
	return ((SuiBoxImplementation*) impl)->getUsingObjectID();
}

Player* SuiBoxAdapter::getPlayer() {
	return ((SuiBoxImplementation*) impl)->getPlayer();
}

/*
 *	SuiBoxHelper
 */

SuiBoxHelper* SuiBoxHelper::staticInitializer = SuiBoxHelper::instance();

SuiBoxHelper::SuiBoxHelper() {
	className = "SuiBox";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void SuiBoxHelper::finalizeHelper() {
	SuiBoxHelper::finalize();
}

DistributedObject* SuiBoxHelper::instantiateObject() {
	return new SuiBox(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SuiBoxHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SuiBoxAdapter((SuiBoxImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	SuiBoxServant
 */

SuiBoxServant::SuiBoxServant() {
	_classHelper = SuiBoxHelper::instance();
}

SuiBoxServant::~SuiBoxServant() {
}

void SuiBoxServant::_setStub(DistributedObjectStub* stub) {
	_this = (SuiBox*) stub;
}

DistributedObjectStub* SuiBoxServant::_getStub() {
	return _this;
}

