///week11-1_PlaySound.cpp不能執行因為找不到PlaySoundA
///OpenCV需3咒語   GLUT需5咒語   PlaySound需1咒語
///Setting-Compiler....的Linker Setting要加上winmm
#include <windows.h>
int main()
{                                                      ///要等待同步 SND_SYNC 不然會瞬間結束
    PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\do.wav", NULL, SND_SYNC);
    PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\do.wav", NULL, SND_SYNC);
    PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\do.wav", NULL, SND_SYNC);
    PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\re.wav", NULL, SND_SYNC);
    PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\mi.wav", NULL, SND_SYNC);
}
