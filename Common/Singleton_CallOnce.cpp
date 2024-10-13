#include "pch.h"
#include "Singleton_CallOnce.h"

using namespace CallOnce;

CSingleton* CSingleton::m_pInstance = nullptr;
std::once_flag CSingleton::m_InitInstanceFlag;
