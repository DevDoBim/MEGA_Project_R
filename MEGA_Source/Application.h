#pragma once
#include <Windows.h>
#include "Singleton.h"

namespace MEGA
{
	class Application
	{
		friend Application* Singleton<Application>::Init();

	public:
		~Application() = default;

	private:
		Application() = default;

	public:
		void Init();
		void Run();
		void Update();
		void Render(HDC hdc);
		void Release();

	private:

	};

}