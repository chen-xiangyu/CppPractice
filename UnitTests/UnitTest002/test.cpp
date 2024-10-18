#include "pch.h"
#include "Demo.h"

TEST(TestReflection, RegisterClass)
{
	hiveReflection::CClassFactory* pFactory = hiveReflection::CClassFactory::getInstance();
	
	CDemo* pDemo = static_cast<CDemo*>(pFactory->createClass("CDemo"));
	
	EXPECT_EQ(pDemo->getName(), "CDemo");
	EXPECT_EQ(pDemo->getAge(), 666);
}
