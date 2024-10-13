#pragma once

#include <mutex>

namespace BiliBili
{
	// todo��ʹ��˫�����ʵ���̰߳�ȫ
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
