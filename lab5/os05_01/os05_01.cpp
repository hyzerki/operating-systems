#include <Windows.h>
#include <intrin.h>
#include <iostream>
#include <bitset>
#include <iomanip>

using namespace std;

void printProcessPriority(HANDLE h)
{
	cout << "\nCurrent PID = " << GetCurrentProcessId() << endl;

	DWORD priority = GetPriorityClass(h);

	switch (priority)
	{
	case IDLE_PRIORITY_CLASS: cout << "Priority = IDLE_PRIORITY_CLASS" << endl; break;
	case BELOW_NORMAL_PRIORITY_CLASS: cout << "Priority = BELOW_NORMAL_PRIORITY_CLASS" << endl; break;
	case NORMAL_PRIORITY_CLASS: cout << "Priority = NORMAL_PRIORITY_CLASS" << endl; break;
	case ABOVE_NORMAL_PRIORITY_CLASS: cout << "Priority = ABOVE_NORMAL_PRIORITY_CLASS" << endl; break;
	case HIGH_PRIORITY_CLASS: cout << "Priority = HIGH_PRIORITY_CLASS" << endl; break;
	case REALTIME_PRIORITY_CLASS: cout << "Priority = REALTIME_PRIORITY_CLASS" << endl; break;
	default: cout << "Priority = ?" << endl; break;
	}
}

void printThreadPriority(HANDLE h)
{
	cout << "\nCurrent thread ID = " << GetCurrentThreadId() << endl;

	// Приоритет текущего потока
	DWORD priority = GetThreadPriority(h);

	switch (priority)
	{
	case THREAD_PRIORITY_LOWEST: cout << "Priority = THERAD_PRIORITY_LOWEST" << endl; break;
	case THREAD_PRIORITY_BELOW_NORMAL: cout << "Priority = THERAD_PRIORITY_BELOW_NORMAL" << endl; break;
	case THREAD_PRIORITY_NORMAL: cout << "Priority = THERAD_PRIORITY_NORMAL" << endl; break;
	case THREAD_PRIORITY_ABOVE_NORMAL: cout << "Priority = THERAD_PRIORITY_ABOVE_NORMAL" << endl; break;
	case THREAD_PRIORITY_HIGHEST: cout << "Priority = THERAD_PRIORITY_HIGHEST" << endl; break;
	case THREAD_PRIORITY_IDLE: cout << "Priority = THERAD_PRIORITY_IDLE" << endl; break;
	case THREAD_PRIORITY_TIME_CRITICAL: cout << "Priority = THREAD_PRIORITY_TIME_CRITICAL" << endl; break;
	default: cout << "Priority = ?" << endl; break;
	}
}

void printAffinityMask(HANDLE h)
{

	ULONG_PTR processAffinityMask, threadAffinityMask;

	SYSTEM_INFO sys_info;


	
	if (!GetProcessAffinityMask(h,
		&processAffinityMask,
		&threadAffinityMask))
	{
		throw "GetProcessAffinityMask";
	}


	bitset<8> mask(processAffinityMask);

	cout << "\nProcess affinity mask: " << mask << endl;

	GetSystemInfo(&sys_info); 

	cout << "Max count processors: " << sys_info.dwNumberOfProcessors << endl << endl;

}

void printIdealProcessor(HANDLE h)
{
	DWORD idealProcessor = -1;

	// Функция SetThreadIdealProcessor устанавливает предпочитаемый процессор для потока.
	idealProcessor = SetThreadIdealProcessor(h, // дескриптор процесса
		MAXIMUM_PROCESSORS); // номер идеального процесса
	// Значение MAXIMUM_PROCESSORS сообщает системе, 
	// что поток не имеет привилегированного процессора.

	cout << "Thread ideal processor: " << dec << idealProcessor << endl;
}

int main()
{
	HANDLE hp = GetCurrentProcess();
	HANDLE ht = GetCurrentThread();

	printProcessPriority(hp);
	printThreadPriority(ht);
	printAffinityMask(hp);
	printIdealProcessor(ht);

	return 0;
}