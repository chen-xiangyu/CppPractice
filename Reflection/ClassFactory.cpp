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

void CClassFactory::registerClassField(const std::string& vClassName, const std::string& vFieldName, const std::string& vType, size_t vOffset)
{
	m_ClassFields[vClassName].push_back(new CClassField(vFieldName, vType, vOffset));
}

size_t CClassFactory::getFieldNum(const std::string& vClassName)
{
	return m_ClassFields[vClassName].size();
}

CClassField* CClassFactory::getField(const std::string& vClassName, int vPos)
{
	size_t Size = m_ClassFields[vClassName].size();
	if (vPos < 0 || vPos >= Size) return nullptr;
	return m_ClassFields[vClassName][vPos];
}

CClassField* CClassFactory::getField(const std::string& vClassName, const std::string& vFieldName)
{
	auto& Fields = m_ClassFields[vClassName];
	for (auto Iter = Fields.begin(); Iter != Fields.end(); Iter++)
	{
		if ((*Iter)->getName() == vFieldName) return (*Iter);
	}
	return nullptr;
}
