#include "pch.h"
#include "ClassRegister.h"

using namespace hiveReflection;

CClassRegister::CClassRegister(const std::string& vClassName, createObject vMethod)
{
	CClassFactory* pFactory = CClassFactory::getInstance();
	pFactory->registerClass(vClassName, vMethod);
}

CClassRegister::CClassRegister(const std::string& vClassName, const std::string& vFieldName, const std::string& vType, size_t vOffset)
{
	CClassFactory* pFactory = CClassFactory::getInstance();
	pFactory->registerClassField(vClassName, vFieldName, vType, vOffset);
}
