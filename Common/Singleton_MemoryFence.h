#pragma once

#include <mutex>

namespace MemoryFence
{
	class CSingleton
	{
	public:
		~CSingleton() = default;

		CSingleton(const CSingleton&) = delete;
		const CSingleton& operator=(const CSingleton&) = delete;

		static CSingleton* getInstance()
		{
			//CSingleton* tmp = m_pInstance.load(std::memory_order_relaxed);
			//std::atomic_thread_fence(std::memory_order_acquire);
			CSingleton* tmp = m_pInstance.load(std::memory_order_acquire);
			if (tmp == nullptr)
			{
				std::lock_guard<std::mutex> Lock(m_Mutex);
				tmp = m_pInstance.load(std::memory_order_relaxed);
				if (tmp == nullptr)
				{
					tmp = new CSingleton();
					//std::atomic_thread_fence(std::memory_order_release);
					//m_pInstance.store(tmp, std::memory_order_relaxed);
					m_pInstance.store(tmp, std::memory_order_release);
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
		static std::atomic<CSingleton*> m_pInstance;
		static std::mutex m_Mutex;
		int m_TestData = 0;
		std::mutex m_TestMutex;

	private:
		CSingleton() = default;
	};
}
