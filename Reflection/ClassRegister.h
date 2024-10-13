#pragma once

#include "ClassFactory.h"

namespace hiveReflection
{
	class CClassRegister
	{
	public:
		CClassRegister(const std::string& vClassName, createObject vMethod);
		~CClassRegister() = default;
	};

	#define REGISTER_CLASS(vClassName)            \
		IObject* createObject##vClassName()       \
		{                                         \
			IObject* pObject = new vClassName();  \
			return pObject;                       \
		}                                         \
		CClassRegister CClassRegister##vClassName(#vClassName, createObject##vClassName)
}
