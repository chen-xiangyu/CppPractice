#include "pch.h"
#include "ClassFactory.h"

using namespace hiveReflection;

void CClassFactory::registerClass(const std::string& vClassName, createObject vMethod)
{
	m_ClassMap[vClassName] = vMethod;
}

IObject* CClassFactory::createClass(const std::string& vClassName)
{
	auto Iter = m_ClassMap.find(vClassName);
	if (Iter != m_ClassMap.end())
	{
		return Iter->second();
	}
	return nullptr;
}
