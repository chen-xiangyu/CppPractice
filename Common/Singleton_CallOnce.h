#pragma once

#include <mutex>

namespace CallOnce
{
	class CSingleton
	{
	public:
		~CSingleton() = default;

		CSingleton(const CSingleton&) = delete;
		const CSingleton& operator=(const CSingleton&) = delete;

		static CSingleton* getInstance()
		{
			std::call_once(m_InitInstanceFlag, &CSingleton::init);
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
		static std::once_flag m_InitInstanceFlag;
		int m_TestData = 0;
		std::mutex m_TestMutex;

	private:
		CSingleton() = default;

		static void init()
		{
			m_pInstance = new CSingleton();
		}
	};
}
