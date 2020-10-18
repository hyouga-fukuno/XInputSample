// ----------------- Include File -----------------
#include "XInput.h"

// �R���X�g���N�^
XINPUTJOYSTATE::XINPUTJOYSTATE()
{
	state = XINPUT_STATE();
	isConnected = false;
	memset(syncButtons, 0x00, sizeof(syncButtons));
}

//	�֐���:UpdateXInputJoystate		XInputJoystate�̍X�V�֐�
//	������:joystate					XINPUTJOYSTATE�̃|�C���^
//		  :index					�R���g���[���[�ԍ�(0�`3)
//	�߂�l:							�Ȃ�
void UpdateXInputJoystate(XINPUTJOYSTATE* joystate, DWORD index)
{
	joystate->isConnected = IsXInputConnect(joystate, index);
}

//	�֐���:UpdateXInputJoystate		XInputJoystate�̍X�V�֐�
//	������:joystate					XINPUTJOYSTATE�̃|�C���^
//		  :index					�R���g���[���[�ԍ�(0�`3)
//	�߂�l:							�Ȃ�
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