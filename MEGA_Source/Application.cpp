#include "Application.h"
#include "Time.h"
#include "Input.h"

namespace MEGA
{
	Application::Application() :
		_hWnd(nullptr), _hdc(nullptr), 
		_backHdc(nullptr), _backBuffer(NULL), _rect{},
		_width(0), _height(0)
	{

	}

	void Application::Init(HWND hWnd, UINT width, UINT height)
	{
		_AdjustWindowRect(hWnd, width, height);
		_CreateBuffer();

		Time::Init();
		Input::Init();
	}
	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();
	}

	void Application::Render()
	{
		_ResetHdc();
		Time::Render(_backHdc);

		_CopyHdc();
	}

	void Application::Release()
	{
	}

	void Application::_AdjustWindowRect(HWND hWnd, UINT width, UINT height)
	{
		_hWnd = hWnd;
		_hdc = GetDC(hWnd);

		_width = width;
		_height = height;

		RECT rect = { 0, 0, _width, _height };

		_rect = rect;

		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
	}
	void Application::_CreateBuffer()
	{
		// DC客 BitMap 积己
		_backHdc = CreateCompatibleDC(_hdc);
		_backBuffer = CreateCompatibleBitmap(_hdc, _width, _height);

		HBITMAP bitmap = (HBITMAP)SelectObject(_backHdc, _backBuffer);
		DeleteObject(bitmap);
	}
	void Application::_ResetHdc()
	{
		// _backHdc 府悸
		FillRect(_backHdc, &_rect, (HBRUSH)GetStockObject(WHITE_BRUSH));
	}
	void Application::_CopyHdc()
	{
		// backHdc -> hdc 汗荤
		BitBlt(_hdc, 0, 0, _width, _height, _backHdc, 0, 0, SRCCOPY);
	}
	
	
}

	

