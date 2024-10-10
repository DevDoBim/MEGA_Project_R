#pragma once
#include "MEGA_InClude.h"
#include "Singleton.h"

namespace MEGA
{
	class Application
	{
		friend Application* Singleton<Application>::Init();

	public:
		~Application() = default;

	public:
		Application();

	public:
		void Init(HWND hWnd, UINT width, UINT height);
		void Run();
		void Update();
		void Render();
		void Release();

	private:
		void _AdjustWindowRect(HWND hWnd, UINT width, UINT height);
		void _CreateBuffer();
		void _ResetHdc();
		void _CopyHdc();

	private:
		HWND _hWnd;
		HDC  _hdc;
		HDC _backHdc;
		HBITMAP _backBuffer;

		RECT _rect;

		UINT _width;
		UINT _height;

	};

}