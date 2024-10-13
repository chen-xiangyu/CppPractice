#include "pch.h"
#include "Singleton_DoubleCheckLock.h"

using namespace DoubleCheckLock;

CSingleton* CSingleton::m_pInstance = nullptr;
std::mutex CSingleton::m_Mutex;
