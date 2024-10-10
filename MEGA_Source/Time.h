#pragma once
#include "MEGA_InClude.h"

namespace MEGA
{
	class Time
	{
	public:
		~Time() = default;

	private:
		Time() = default;

	public:
		static void Init();
		static void Update();
		static void Render(HDC hdc);

	public:
		static float DeltaTime() { return deltaTime; }

	private:
		// cpu GHz ¿˙¿Â
		static LARGE_INTEGER cpuFrequency;
		static LARGE_INTEGER startFrequency;
		static LARGE_INTEGER endFrequency;

		static float deltaTime;
		static int _fps;
	};
}


