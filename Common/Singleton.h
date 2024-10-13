#pragma once
#include <mutex>

namespace hiveCommon
{
	template<typename T>
	class CSingleton
	{
	public:
		CSingleton(const CSingleton&) = delete;
		const CSingleton& operator=(const CSingleton&) = delete;

		static T* getInstance()
		{
			static T Instance;
			return &Instance;
		}

	protected:
		CSingleton() = default;
		virtual ~CSingleton() = default;
	};
}

namespace SingleThread
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
				m_pInstance = new CSingleton();
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
		int m_TestData = 0;
		std::mutex m_TestMutex;

	private:
		CSingleton() = default;
	};

	CSingleton* CSingleton::m_pInstance = nullptr;
}

namespace UseMutex
{
	class CSingleton
	{
	public:
		~CSingleton() = default;

		CSingleton(const CSingleton&) = delete;
		const CSingleton& operator=(const CSingleton&) = delete;

		static CSingleton* getInstance()
		{
			std::lock_guard<std::mutex> Lock(m_Mutex);
			if (m_pInstance == nullptr)
			{
				m_pInstance = new CSingleton();
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

	CSingleton* CSingleton::m_pInstance = nullptr;
	std::mutex CSingleton::m_Mutex;
}

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

	CSingleton* CSingleton::m_pInstance = nullptr;
	std::mutex CSingleton::m_Mutex;
}

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

	std::atomic<CSingleton*> CSingleton::m_pInstance = nullptr;
	std::mutex CSingleton::m_Mutex;
}

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

	CSingleton* CSingleton::m_pInstance = nullptr;
	std::once_flag CSingleton::m_InitInstanceFlag;
}

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

namespace BiliBili
{
	// todo：使用双检查锁实现线程安全
	template<typename T>
	class CSingleton
	{
	public:
		CSingleton(const CSingleton<T>&) = delete;
		const CSingleton<T>& operator=(const CSingleton<T>&) = delete;

		static T* getInstance()
		{
			if (m_pInstance == nullptr)
			{
				m_pInstance = new T();
			}
			return m_pInstance;
		}

	private:
		static T* m_pInstance;

	private:
		CSingleton() = default;
		~CSingleton() = default;
	};

	template<typename T>
	T* CSingleton<T>::m_pInstance = nullptr;
}