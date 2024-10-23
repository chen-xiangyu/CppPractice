#pragma once

#include "ClassFactory.h"
#include "Object.h"

namespace hiveReflection
{
	class CClassRegister
	{
	public:
		CClassRegister(const std::string& vClassName, createObject vMethod);
		CClassRegister(const std::string& vClassName, const std::string& vFieldName, const std::string& vType, size_t vOffset);
		~CClassRegister() = default;
	};

	#define REGISTER_CLASS(vClassName)                            \
		hiveReflection::IObject* createObject##vClassName()       \
		{                                                         \
			hiveReflection::IObject* pObject = new vClassName();  \
			pObject->setClassName(#vClassName);                   \
			return pObject;                                       \
		}                                                         \
		hiveReflection::CClassRegister ClassRegister##vClassName(#vClassName, createObject##vClassName)

	#define REGISTER_CLASS_FIELD(vClassName, vFieldName, vType)									\
		vClassName ClassName##vFieldName;														\
		hiveReflection::CClassRegister ClassRegister##vClassName##vFieldName(					\
			#vClassName,																		\
			#vFieldName,																		\
			#vType,																				\
			(size_t)(&(ClassName##vFieldName.vFieldName)) - (size_t)(&ClassName##vFieldName)	\
		)

}
