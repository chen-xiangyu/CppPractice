#pragma once

#include <mutex>

namespace StaticLocalVariable
{
	class CSingleton
	{
	public:
		~CSingleton() = default;

		CSingleton(const CSingleton&) = delete;
		const CSingleton& operator=(const CSingleton&) = delete;

		static CSingleton* getInstance()
		{
			static CSingleton Instance;
			return &Instance;
		}

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
		CSingleton() = default;
	};
}
