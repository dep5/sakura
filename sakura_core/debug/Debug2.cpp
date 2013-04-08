#include "StdAfx.h"
#include "debug/Debug2.h"

//2007.08.30 kobake �ǉ�

#ifdef _DEBUG
//!�f�o�b�O���b�Z�[�W�o��
void debug_output(const char* str, ...)
{
	static char buf[_MAX_PATH+150];
	va_list mark;
	va_start(mark,str);
	// FILE��, LINE �� ���K�v
	tchar_vsnprintf_s(buf,_countof(buf),str,mark);
	va_end(mark);

	//�f�o�b�K�ɏo��
	OutputDebugStringA(buf);
}

//!�����I��
void debug_exit()
{
	MessageBox(NULL,_T("assert�Ƃ��Ɉ����|�������ۂ��ł�"),GSTR_APPNAME,MB_OK);
	exit(1);
}

void warning_point()
{
	int n;
	n=0; //���������Ƀu���[�N�|�C���g��݂��Ă����ƁA�C�Ӄ��[�j���O�Ńu���[�N�ł���
}
#endif	// _DEBUG