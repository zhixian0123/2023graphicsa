///week11-1_PlaySound.cpp�������]���䤣��PlaySoundA
///OpenCV��3�G�y   GLUT��5�G�y   PlaySound��1�G�y
///Setting-Compiler....��Linker Setting�n�[�Wwinmm
#include <windows.h>
int main()
{                                                      ///�n���ݦP�B SND_SYNC ���M�|��������
    PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\do.wav", NULL, SND_SYNC);
    PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\do.wav", NULL, SND_SYNC);
    PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\do.wav", NULL, SND_SYNC);
    PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\re.wav", NULL, SND_SYNC);
    PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\mi.wav", NULL, SND_SYNC);
}
