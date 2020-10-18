// ----------------- Include File -----------------
#include "XInput.h"

// コンストラクタ
XINPUTJOYSTATE::XINPUTJOYSTATE()
{
	state = XINPUT_STATE();
	isConnected = false;
	memset(syncButtons, 0x00, sizeof(syncButtons));
}

//	関数名:UpdateXInputJoystate		XInputJoystateの更新関数
//	引数名:joystate					XINPUTJOYSTATEのポインタ
//		  :index					コントローラー番号(0～3)
//	戻り値:							なし
void UpdateXInputJoystate(XINPUTJOYSTATE* joystate, DWORD index)
{
	joystate->isConnected = IsXInputConnect(joystate, index);
}

//	関数名:UpdateXInputJoystate		XInputJoystateの更新関数
//	引数名:joystate					XINPUTJOYSTATEのポインタ
//		  :index					コントローラー番号(0～3)
//	戻り値:							なし
bool IsXInputConnect(XINPUTJOYSTATE* joystate, DWORD index)
{
	DWORD dwResult;
	dwResult = XInputGetState(index, &joystate->state);

	if (ERROR_SUCCESS == dwResult)
	{
		return true;
	}
	else
	{
		return false;
	}
}