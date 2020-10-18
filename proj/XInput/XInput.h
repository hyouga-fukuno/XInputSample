#ifndef __XINPUT_H__
#define __XINPUT_H__
// ----------------- Include File -----------------
#include <windows.h>
#include <XInput.h>
// ----------------- Library File -----------------
#pragma comment (lib, "xinput.lib")
// ------------------- const�錾 ------------------
const int XINPUT_MAX_CONTROLLERS = 4;	// �ڑ�����ő�R���g���[���[��(Xinput�͍ő�4�܂�)
const int XINPUT_THRESHOLD = 6000;		// �������l
// ------------------- enum�錾 -------------------
enum NumXInputConnect	// �R���g���[���[�̐ڑ��ԍ�
{
	First,		// 1P
	Second,		// 2P
	Third,		// 3P
	Fourth		// 4P
};
// ------------------ �N���X�錾 ------------------
class XINPUTJOYSTATE
{
public:
	XINPUT_STATE state;
	bool isConnected;
	WORD syncButtons[XINPUT_MAX_CONTROLLERS];
public:
	XINPUTJOYSTATE();
};
// ------------------- �֐��錾 -------------------
void UpdateXInputJoystate(XINPUTJOYSTATE*, DWORD);	// XInputJoystate�̍X�V�֐�
bool IsXInputConnect(XINPUTJOYSTATE*, DWORD);		// �R���g���[���[���ڑ�����Ă��邩�m�F����֐�
#endif /* __XINPUT_H__ */
