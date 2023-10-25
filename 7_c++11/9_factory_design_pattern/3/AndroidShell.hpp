#ifndef _ANDROID_SHELL_
#define _ANDROID_SHELL_
class AndroidShell : public Shell
{
public:
    void protect()
    {
        cout << "AndroidShell protect android" << endl;
    }
};

#endif