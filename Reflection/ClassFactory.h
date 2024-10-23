#pragma once

#include "../Common/Singleton.h"
#include "ClassField.h"

namespace hiveReflection
{
	class IObject;

	using createObject = IObject * (*)(void);

	class CClassFactory : public hiveCommon::CSingleton<CClassFactory>
	{
		friend class hiveCommon::CSingleton<CClassFactory>;

	public:
		~CClassFactory() = default;

		void registerClass(const std::string& vClassName, createObject vMethod);
		IObject* createClass(const std::string& vClassName);

		void registerClassField(const std::string& vClassName, const std::string& vFieldName, const std::string& vType, size_t vOffset);
		size_t getFieldNum(const std::string& vClassName);
		CClassField* getField(const std::string& vClassName, int vPos);
		CClassField* getField(const std::string& vClassName, const std::string& vFieldName);

	private:
		std::map<std::string, createObject> m_ClassMap;
		std::map<std::string, std::vector<CClassField*>> m_ClassFields;

	private:
		CClassFactory() = default;
	};
}
