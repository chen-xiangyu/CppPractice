#include "pch.h"
#include "Demo.h"

class CTestReflection : public testing::Test
{
protected:
	hiveReflection::CClassFactory* pFactory = nullptr;
	hiveReflection::IObject* pObject = nullptr;

	void SetUp()
	{
		pFactory = hiveReflection::CClassFactory::getInstance();
		EXPECT_TRUE(pFactory != nullptr);

		pObject = pFactory->createClass("CDemo");
		EXPECT_TRUE(pObject != nullptr);
	}
};

TEST_F(CTestReflection, NT_RegisterClassField)
{
	EXPECT_EQ(pObject->getClassName(), "CDemo");

	pObject->set("m_Name", std::string("Jack"));
	std::string Name;
	pObject->get("m_Name", Name);
	EXPECT_EQ(Name, static_cast<CDemo*>(pObject)->getName());

	pObject->set("m_Age", 100);
	int Age;
	pObject->get("m_Age", Age);
	EXPECT_EQ(Age, static_cast<CDemo*>(pObject)->getAge());

	EXPECT_EQ(pObject->getFieldNum(), 2);

	hiveReflection::CClassField* pNameField = pObject->getField("m_Name");
	EXPECT_TRUE(pNameField != nullptr && pNameField->getName() == "m_Name" && pNameField->getType() == "std::string");
	
	hiveReflection::CClassField* pAgeField = pObject->getField(1);
	EXPECT_TRUE(pAgeField != nullptr && pAgeField->getName() == "m_Age" && pAgeField->getType() == "int");
}


