#include "pch.h"
#include "Demo.h"

template<typename T>
void testWithMultThread()
{
	int ThreadNum = 1000, IterNum = 1000;
	std::vector<std::thread> Threads;

	for (int i = 0; i < ThreadNum; i++)
	{
		Threads.push_back(std::thread([&]() {
			for (int j = 0; j < IterNum; j++)
			{
				T::getInstance()->add();
			}
			}));
	}

	for (int i = 0; i < ThreadNum; i++)
	{
		Threads[i].join();
	}
	EXPECT_EQ(T::getInstance()->getTestData(), ThreadNum * IterNum);
}

TEST(TestSingleton, SingleThread)
{
	SingleThread::CSingleton* pSingleton = SingleThread::CSingleton::getInstance();

	pSingleton->add();
	EXPECT_EQ(pSingleton->getTestData(), 1);
}

//TEST(TestSingleton, SingletonError)
//{
//	testWithMultThread<SingleThread::CSingleton>();
//}

TEST(TestSingleton, UseMutex)
{
	testWithMultThread<UseMutex::CSingleton>();
}

TEST(TestSingleton, DoubleCheckLock)
{
	testWithMultThread<DoubleCheckLock::CSingleton>();
}

TEST(TestSingleton, MemoryFence)
{
	testWithMultThread<MemoryFence::CSingleton>();
}

TEST(TestSingleton, CallOnce)
{
	testWithMultThread<CallOnce::CSingleton>();
}

TEST(TestSingleton, StaticLocalVariable)
{
	testWithMultThread<StaticLocalVariable::CSingleton>();
}

TEST(TestSingleton, SingletonCRTP)
{
	testWithMultThread<CDemoCRTP>();
}

TEST(TestSingleton, Singleton)
{
	CDemo* pDemo = BiliBili::CSingleton<CDemo>::getInstance();

	EXPECT_EQ(pDemo->getName(), "CDemo");
}

