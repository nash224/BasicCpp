
#include <array>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <conio.h>
#include <intrin.h>

#include <xhash>

#include <Windows.h>

static std::string CPUID = "BFEBFBFF000906A3";

std::string GetProcessorId() 
{
	std::array<int, 4> cpuInfo;
	__cpuid(cpuInfo.data(), 1);
	std::ostringstream buffer;
	buffer
		<< std::uppercase << std::hex << std::setfill('0')
		<< std::setw(8) << cpuInfo.at(3)
		<< std::setw(8) << cpuInfo.at(0);
	return buffer.str();
}

int main() 
{
	std::hash<std::string> Hash;
	std::string ProcessorId = GetProcessorId();

	{
		InputBox();
	}

	std::cout << "Processor Serial number is:  ";
	std::cout << GetProcessorId() << std::endl;
	char A = _getch();
	return 0;
}