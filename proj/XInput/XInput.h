#ifndef __XINPUT_H__
#define __XINPUT_H__
// ----------------- Include File -----------------
#include <windows.h>
#include <XInput.h>
// ----------------- Library File -----------------
#pragma comment (lib, "xinput.lib")
// ------------------- const宣言 ------------------
const int XINPUT_MAX_CONTROLLERS = 4;	// 接続する最大コントローラー数(Xinputは最大4つまで)
const int XINPUT_THRESHOLD = 6000;		// しきい値
// ------------------- enum宣言 -------------------
enum NumXInputConnect	// コントローラーの接続番号
{
	First,		// 1P
	Second,		// 2P
	Third,		// 3P
	Fourth		// 4P
};
// ------------------ クラス宣言 ------------------
class XINPUTJOYSTATE
{
public:
	XINPUT_STATE state;
	bool isConnected;
	WORD syncButtons[XINPUT_MAX_CONTROLLERS];
public:
	XINPUTJOYSTATE();
};
// ------------------- 関数宣言 -------------------
void UpdateXInputJoystate(XINPUTJOYSTATE*, DWORD);	// XInputJoystateの更新関数
bool IsXInputConnect(XINPUTJOYSTATE*, DWORD);		// コントローラーが接続されているか確認する関数
#endif /* __XINPUT_H__ */
