#include "pch.h"
#include "Singleton_UseMutex.h"

using namespace UseMutex;

CSingleton* CSingleton::m_pInstance = nullptr;
std::mutex CSingleton::m_Mutex;
