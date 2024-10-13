#pragma once

#include <mutex>

namespace DoubleCheckLock
{
	class CSingleton
	{
	public:
		~CSingleton() = default;

		CSingleton(const CSingleton&) = delete;
		const CSingleton& operator=(const CSingleton&) = delete;

		static CSingleton* getInstance()
		{
			if (m_pInstance == nullptr)
			{
				std::lock_guard<std::mutex> Lock(m_Mutex);
				if (m_pInstance == nullptr)
				{
					m_pInstance = new CSingleton();
				}
			}
			return m_pInstance;
		}

		void add()
		{
			std::lock_guard<std::mutex> Lock(m_TestMutex);
			m_TestData = m_TestData + 1;
		}

		int getTestData() const { return m_TestData; }

	private:
		static CSingleton* m_pInstance;
		static std::mutex m_Mutex;
		int m_TestData = 0;
		std::mutex m_TestMutex;

	private:
		CSingleton() = default;
	};
}
