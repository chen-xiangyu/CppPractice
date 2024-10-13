#include "pch.h"
#include "Singleton_MemoryFence.h"

using namespace MemoryFence;

std::atomic<CSingleton*> CSingleton::m_pInstance = nullptr;
std::mutex CSingleton::m_Mutex;
