#pragma once

class CDemo : public hiveReflection::IObject
{
public:
	CDemo() : m_Name("CDemo"), m_Age(666) {}
	~CDemo() = default;

	const std::string& getName() const { return m_Name; }
	int getAge() const { return m_Age; }

private:
	std::string m_Name;
	int m_Age;
};

