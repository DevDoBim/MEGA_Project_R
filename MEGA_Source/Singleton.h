#pragma once
#include <cassert>

namespace MEGA
{
	template<typename T>
	class Singleton
	{
	public:
		~Singleton()
		{
			Release();
		}

	public:
		static T* Init()
		{
			if (_instance == nullptr)
			{
				_instance = new T;
			}
			return _instance;
		}

		static T* GetInstance()
		{
			assert(_instance && "_instance is nullptr");
			return _instance;
		}

		static void Release()
		{
			if (_instance)
			{
				delete _instance;
				_instance = nullptr;
			}
		}


	private:
		static T* _instance;

	private:
		Singleton() = default;


		Singleton(const Singleton&) = delete;
		Singleton operator= (const Singleton&) = delete;
		Singleton(Singleton&&) = delete;
		Singleton(const Singleton&&) = delete;
	};

	template<typename T> T* Singleton<T>::_instance = nullptr;
}

#define Application_Inst	MEGA::Singleton<MEGA::Application>::GetInstance()