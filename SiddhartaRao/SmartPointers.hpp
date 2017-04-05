#ifndef SIDDHARTA_RAO_SMART_POINTERS
#define SIDDHARTA_RAO_SMART_POINTERS

#include "Utils.hpp"
#include <ctime>

namespace smartPointers
{
namespace passingInArgs
{

template<typename T>
void passByValue(T arg)
{
	(void) arg;
}

template<typename T>
void passByRef(T& arg)
{
	(void) arg;
}

template<typename T>
void passByMove(T&& arg)
{
	(void) arg;
}

template<typename T>
double passByValueInLoop(T arg)
{
	std::clock_t timeStart = std::clock();
	for (int i = 0; i < MILLION; i++)
	{
		passByValue(arg);
	}
	std::clock_t timeEnd = std::clock();

	return timeEnd - timeStart;
}

template<typename T>
double passByRefInLoop(T arg)
{
	std::clock_t timeStart = std::clock();
	for (int i = 0; i < MILLION; i++)
	{
		passByRef(arg);
	}
	std::clock_t timeEnd = std::clock();

	return timeEnd - timeStart;
}

template<typename T>
double passByMoveInLoop(T arg)
{
	std::clock_t timeStart = std::clock();
	for (int i = 0; i < MILLION; i++)
	{
		passByMove(arg);
	}
	std::clock_t timeEnd = std::clock();

	return timeEnd - timeStart;
}

void start()
{
	std::cout << "*************** SMART_POINTERS ***************" << EOL;

	std::cout << "Time when pass shared_ptr by val = " <<
		passByValueInLoop(std::make_shared<WrapperForInteger>()) << " ms " << EOL;

	std::cout << "Time when pass shared_ptr by lValRef = " <<
		passByRefInLoop(std::make_shared<WrapperForInteger>()) << EOL;

	std::cout << "Time when pass shared_ptr by rValRef = " <<
		passByMoveInLoop(std::make_shared<WrapperForInteger>()) << EOL << EOL;

	std::cout << "Time when pass unique_ptr by rValRef = " <<
		passByMoveInLoop(std::make_unique<WrapperForInteger>()) << EOL;

	std::cout << "Time when pass unique_ptr by lValRef = " <<
		passByRefInLoop(std::make_unique<WrapperForInteger>()) << EOL << EOL;
}

}

namespace referencesToThem
{

void printVal(WrapperForInteger* inObj)
{
	std::cout << inObj->state << EOL;
}

void start()
{
	std::cout << "*************** SMART_POINTERS ***************" << EOL;

	std::cout << "simpleSmartPtr ";
	std::shared_ptr<WrapperForInteger> simpleSmartPtr = std::make_shared<WrapperForInteger>();
	std::cout << simpleSmartPtr->state << EOL;

	// std::cout << "SimpleObject ";
	// WrapperForInteger simpleObject;
	// std::cout << simpleObject.state << EOL;

	// std::cout << "NotInitializedPtr "; // there will be a crash
	// std::shared_ptr<WrapperForInteger> notInitializedPtr;
	// std::cout << notInitializedPtr->state << EOL;

	// std::cout << "Pass smartPtr when raw is expected ";
	// std::shared_ptr<WrapperForInteger> simpleObject2 = std::make_shared<WrapperForInteger>();
	// printVal(simpleObject2.get());
	// std::cout << notInitializedPtr->state << EOL;
}

}

}

/* Why ?
SharedPointers contains _Atomic_counter_t _Uses;
SharedPointers contains _Atomic_counter_t _Weak;

Copying and handling with atomic operations is so hard
*/

#endif  // SIDDHARTA_RAO_SMART_POINTERS