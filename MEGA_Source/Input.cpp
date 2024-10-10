#include "Input.h"

namespace MEGA
{
	vector<Input::Key> Input::keys = {};

	int ASCII[keyCounts] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
		VK_LBUTTON, VK_RBUTTON
	};

	void MEGA::Input::Init()
	{
		_CreateKey();
	}

	void MEGA::Input::Update()
	{
		_UpdateKey();
	}

	void Input::_CreateKey()
	{
		keys.reserve(keyCounts);

		for (size_t i = 0; i < keyCounts; i++)
		{
			Key key = {};
			key.keyCode = static_cast<e_KeyCode>(i);
			key.state = e_KeyState::None;
			key.bPressed = false;

			keys.push_back(key);
		}

	}
	void Input::_UpdateKey()
	{
		// hWnd가 활성화 되있을 때 체크
		if (GetFocus())
		{
			_PressKey();
		}
		else
		{
			_ClearKey();
		}
	}

	void Input::_PressKey()
	{
		for (size_t i = 0; i < keyCounts; i++)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000) 
			{
				if (keys[i].bPressed)
				{
					keys[i].state = e_KeyState::Pressed;
				}
				else
				{
					keys[i].state = e_KeyState::Down;
				}

				keys[i].bPressed = true;
			}
			else
			{
				if (keys[i].bPressed)
				{
					keys[i].state = e_KeyState::Up;
				}
				else
				{
					keys[i].state = e_KeyState::None;
				}

				keys[i].bPressed = false;
			}
		}
	}
	void Input::_ClearKey()
	{
		for (Key& key : keys)
		{
			if (key.state == e_KeyState::Pressed || key.state == e_KeyState::Down)
			{
				key.state = e_KeyState::Up;
			}
			else if (key.state == e_KeyState::Up)
			{
				key.state = e_KeyState::None;
			}

			key.bPressed = false;
		}
	}
}

