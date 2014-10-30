#ifndef COMMOM_H
#define COMMOM_H

#include "qruninfo_global.h"

#include <QObject>
#include <QString>
#include <qt_windows.h>
#include <shlobj.h>

QRUNINFO_NAMEPASE_BEGIN

struct DeCoInitializer
{
    DeCoInitializer()
        : neededCoInit(CoInitialize(NULL) == S_OK)
    {
    }
    ~DeCoInitializer()
    {
        if (neededCoInit)
            CoUninitialize();
    }
    bool neededCoInit;
    void noWarrning(){}
};

class QRUNINFOSHARED_EXPORT Win3SysPath
{
public:
    //用户目录和临时目录，请用QDir获取
    enum SYSTEMPATH
    {
        UserDeskTopPath = CSIDL_DESKTOPDIRECTORY,//桌面
        UserDocumentsPath = CSIDL_PERSONAL,//我的文档
        UserMusicPath = CSIDL_MYMUSIC,//我的音乐
        UserVideoPath = CSIDL_MYVIDEO,//我的视频
        UserPricturesPath = CSIDL_MYPICTURES,//我的图片
        UserFavoritesPath = CSIDL_FAVORITES,//我的收藏
        UserAppDataPath = CSIDL_APPDATA,//当前用户的特定的应用程序数据存储文件夹
        UserLocalAppDataPath = CSIDL_LOCAL_APPDATA,//表示当前用户的应用程序数据文件夹，例如：C:\Documents and Settings\username\Local Settings\Application Dat
        UserNetHoodPath = CSIDL_NETHOOD,//表示当前用户存在的网络连接的文件夹，例如：C:\Documents and Settings\username\NetHood
        UserPrintHoodPath = CSIDL_PRINTHOOD,//表示当前用户存在的网络打印机的虚拟文件夹，例如：C:\Documents and Settings\username\PrintHood

        UserStartMenuPath = CSIDL_STARTMENU,//用户开始菜单
        UserStartMenuProgramsPath = CSIDL_PROGRAMS,//用户开始程序菜单
        UserStartUpPath = CSIDL_STARTUP,//启动目录
        UserSentTo = CSIDL_SENDTO,//表示当前用户的“发送到”文件夹，例如：C:\Documents and Settings\username\SendTo

        AdminToolsPath = CSIDL_COMMON_ADMINTOOLS,//表示所有用户的“管理工具”系统文件夹
        CommonAppData = CSIDL_COMMON_APPDATA,//表示所有用户的特定的应用程序数据存储文件夹,例如:C:\Documents and Settings\All Users\Application Data
        CommonDeskTopPath = CSIDL_COMMON_DESKTOPDIRECTORY,//表示所有用户的“桌面”文件夹，例如：C:\Documents and Settings\All Users\Desktop。
        CommonDocumentsPath = CSIDL_COMMON_DOCUMENTS,//表示所有用户的“我的文档”文件夹，例如:C:\Documents and Settings\All Users\Documents
        CommonFavoritesPath =CSIDL_COMMON_FAVORITES,//表示所有用户的“我的收藏夹”文件夹。
        CommonMusicPath = CSIDL_COMMON_MUSIC,// 公共音乐 0x0035
        CommonPricturesPath = CSIDL_COMMON_PICTURES,// 公共图片0x0036
        CommonVideoPath = CSIDL_COMMON_VIDEO,//公共视频 0x0037
        CommonStartMenuProgramsPath = CSIDL_COMMON_PROGRAMS,//表示所有用户的“程序”文件夹，例如：C:\Documents and Settings\All Users\Start Menu\Programs
        CommonStartMenuPath = CSIDL_COMMON_STARTMENU,//表示所有用户的“开始菜单”文件夹，例如：C:\Documents and Settings\All Users\Start Menu
        CommonStartUpPath = CSIDL_COMMON_STARTUP,//表示所有用户的“启动”文件夹，例如：C:\Documents and Settings\All Users\Start Menu\Programs\Startup
        CommonTemplantesPath = CSIDL_COMMON_TEMPLATES,//表示所有用户的“模块”文件夹，例如：C:\Documents and Settings\All Users\Templates

        IECookiesPath = CSIDL_COOKIES,//表示当前用户Internet Explorer的cookie 文件夹，例如：C:\Documents and Settings\username\Cookies
        IEHistoryPath = CSIDL_HISTORY,//表示Inernet Explorer的“历史记录”文件夹
        IECachePath = CSIDL_INTERNET_CACHE,//表示当前用户的Internet Explorer的"Cache"文件夹，例如：C:\Documents and Settings\username\Temporary Internet Files

        TemplantesPath = CSIDL_TEMPLATES,//模板目录
        FontsPath   = CSIDL_FONTS,//字体目录
        ProgramFilesPath = CSIDL_PROGRAM_FILES,//表示程序文件的文件夹，例如：C:\Program Files
        ProgramFilesCommonPath =CSIDL_PROGRAM_FILES_COMMON,//表示系统程序共用组件文件夹，例如：C:\Program Files\Common
        SystemPath = CSIDL_SYSTEM,//表示WINDOWS系统的系统文件夹，例如：C:\WINNT\SYSTEM32
        WindowsPath = CSIDL_WINDOWS//表示的是系统中Windows目录的文件珍，例如：C:\WINNT
    };
    static bool createLink(const QString &fileName, const QString &linkName,
        const QString &arguments = QString(), const QString &iconPath = QString(),
        const QString &iconId = QString());//创建快捷方式：源文件，创建到的完整path

    static QString  getWinSysDir(SYSTEMPATH path);//获取系统的路径

private:
    Win3SysPath(){}
};

QRUNINFO_NAMEPASE_END

#endif // COMMOM_H
