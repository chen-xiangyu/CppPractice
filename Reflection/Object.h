#pragma once

#include "ClassField.h"
#include "ClassFactory.h"

namespace hiveReflection
{
	class IObject
	{
	public:
		IObject() = default;
		virtual ~IObject() = default;

		void setClassName(const std::string& vClassName) { m_ClassName = vClassName; }
		const std::string& getClassName() const { return m_ClassName; }

		size_t getFieldNum() const;
		CClassField* getField(int vPos) const;
		CClassField* getField(const std::string& vFieldName) const;

		template<typename T>
		void get(const std::string& vFieldName, T& vValue);

		template<typename T>
		void set(const std::string& vFieldName, const T& vValue);

	private:
		std::string m_ClassName;
	};

	template<typename T>
	void IObject::get(const std::string& vFieldName, T& vValue)
	{
		CClassFactory* pFactory = CClassFactory::getInstance();
		CClassField* pField = pFactory->getField(m_ClassName, vFieldName);
		size_t Offset = pField->getOffset();
		vValue = *(T*)((size_t)this + Offset);
	}

	template<typename T>
	void IObject::set(const std::string& vFieldName, const T& vValue)
	{
		CClassFactory* pFactory = CClassFactory::getInstance();
		CClassField* pField = pFactory->getField(m_ClassName, vFieldName);
		size_t Offset = pField->getOffset();
		*(T*)((size_t)this + Offset) = vValue;
	}
}
