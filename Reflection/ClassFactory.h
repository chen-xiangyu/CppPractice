#pragma once

#include "Object.h"
#include "../Common/Singleton.h"

namespace hiveReflection
{
	using createObject = IObject * (*)(void);

	class CClassFactory : public hiveCommon::CSingleton<CClassFactory>
	{
		friend class hiveCommon::CSingleton<CClassFactory>;
	public:
		~CClassFactory() = default;

		void registerClass(const std::string& vClassName, createObject vMethod);
		IObject* createClass(const std::string& vClassName);

	private:
		std::map<std::string, createObject> m_ClassMap;
	};
}
