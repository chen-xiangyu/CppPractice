//
// pch.h
//

#pragma once

#include <thread>
#include <vector>

#include "gtest/gtest.h"

#include "../../Common/Singleton_SingleThread.h"
#include "../../Common/Singleton_UseMutex.h"
#include "../../Common/Singleton_DoubleCheckLock.h"
#include "../../Common/Singleton_MemoryFence.h"
#include "../../Common/Singleton_CallOnce.h"
#include "../../Common/Singleton_StaticLocalVariable.h"