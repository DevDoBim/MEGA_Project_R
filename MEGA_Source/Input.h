#pragma once
#include "MEGA_InClude.h"
#include <vector>

using std::vector;

namespace MEGA
{
	enum class e_KeyState
	{
		Down,
		Pressed,
		Up,
		None,
		End
	};

	enum class e_KeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up,
		LButton, RButton,
		End
	};

	constexpr int keyCounts = static_cast<UINT>(e_KeyCode::End);

	class Input
	{
	public:
		~Input() = default;

	private:
		Input() = default;

	public:
		struct Key
		{
			e_KeyCode keyCode;
			e_KeyState state;
			bool bPressed;
		};

	public:
		static void Init();
		static void Update();

	public:

	private:
		static void _CreateKey();
		static void _UpdateKey();
		static void _PressKey();
		static void _ClearKey();



	private:
		static vector<Key> keys;

	};


}
