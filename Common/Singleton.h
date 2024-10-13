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
