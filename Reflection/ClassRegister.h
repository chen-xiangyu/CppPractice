#pragma once

#include "ClassFactory.h"
#include "Object.h"

namespace hiveReflection
{
	class CClassRegister
	{
	public:
		CClassRegister(const std::string& vClassName, createObject vMethod);
		~CClassRegister() = default;
	};

	#define REGISTER_CLASS(vClassName)                            \
		hiveReflection::IObject* createObject##vClassName()       \
		{                                                         \
			hiveReflection::IObject* pObject = new vClassName();  \
			return pObject;                                       \
		}                                                         \
		hiveReflection::CClassRegister ClassRegister##vClassName(#vClassName, createObject##vClassName)
}
