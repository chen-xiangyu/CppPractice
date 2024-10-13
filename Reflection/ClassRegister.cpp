#include "pch.h"
#include "ClassRegister.h"

using namespace hiveReflection;

CClassRegister::CClassRegister(const std::string& vClassName, createObject vMethod)
{
	CClassFactory* pFactory = CClassFactory::getInstance();
	pFactory->registerClass(vClassName, vMethod);
}
