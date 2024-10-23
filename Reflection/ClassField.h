#pragma once

namespace hiveReflection
{
	class CClassField
	{
	public:
		CClassField(const std::string& vName, const std::string& vType, size_t vOffset) 
			: m_Name(vName), m_Type(vType), m_Offset(vOffset) {}
		~CClassField() = default;

		const std::string& getName() const { return m_Name; }
		const std::string& getType() const { return m_Type; }
		size_t getOffset() const { return m_Offset; }

	private:
		std::string m_Name;
		std::string m_Type;
		size_t m_Offset;
	};
}