#include "pch.h"

#include "Object.h"

using namespace hiveReflection;

size_t IObject::getFieldNum() const
{
	CClassFactory* pFactory = CClassFactory::getInstance();
	return pFactory->getFieldNum(m_ClassName);
}

CClassField* IObject::getField(int vPos) const
{
	CClassFactory* pFactory = CClassFactory::getInstance();
	return pFactory->getField(m_ClassName, vPos);
}

CClassField* IObject::getField(const std::string& vFieldName) const
{
	CClassFactory* pFactory = CClassFactory::getInstance();
	return pFactory->getField(m_ClassName, vFieldName);
}
