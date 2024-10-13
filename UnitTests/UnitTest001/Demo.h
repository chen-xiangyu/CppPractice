#pragma once

#include <iostream>
#include <string>
#include "../../Common/Singleton.h"

class CDemo
{
	friend class BiliBili::CSingleton<CDemo>;

public:
	std::string getName() const { return m_Name; }

private:
	std::string m_Name;

private:
	CDemo() : m_Name("CDemo") {}
	~CDemo() = default;
	CDemo(const CDemo&) = delete;
	const CDemo& operator=(const CDemo&) = delete;
};

class CDemoCRTP : public hiveCommon::CSingleton<CDemoCRTP>
{
public:
	friend class hiveCommon::CSingleton<CDemoCRTP>;

	~CDemoCRTP() = default;

	void add()
	{
		std::lock_guard<std::mutex> Lock(m_TestMutex);
		m_TestData = m_TestData + 1;
	}

	int getTestData() const { return m_TestData; }

private:
	int m_TestData = 0;
	std::mutex m_TestMutex;

private:
	CDemoCRTP() = default;
};