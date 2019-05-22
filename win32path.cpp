#include "win32path.h"
#include <QFile>
#include <QDir>

#ifndef PIDLIST_ABSOLUTE
typedef ITEMIDLIST *PIDLIST_ABSOLUTE;
#endif

namespace QRunInfo {

bool Win3SysPath::createLink(const QString &fileName, const QString &linkName,
                const QString &arguments, const QString &iconPath,
                const QString &iconId)
{
    bool success = QFile::link(fileName, linkName);

    if (!success)
        return success;
    // CoInitialize cleanup object
    DeCoInitializer _;
    _.noWarrning();


    QString workingDir = QFileInfo(fileName).absolutePath();
    workingDir = QDir::toNativeSeparators(workingDir);

    IShellLink *psl = NULL;
    if (FAILED(CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink, (LPVOID*)&psl)))
        return success;

    psl->SetPath((wchar_t *)QDir::toNativeSeparators(fileName).utf16());
    psl->SetWorkingDirectory((wchar_t *)workingDir.utf16());
    if (!arguments.isNull())
        psl->SetArguments((wchar_t*)arguments.utf16());
    if (!iconPath.isNull())
        psl->SetIconLocation((wchar_t*)(iconPath.utf16()), iconId.toInt());

    IPersistFile *ppf = NULL;
    if (SUCCEEDED(psl->QueryInterface(IID_IPersistFile, (void **)&ppf))) {
        ppf->Save((wchar_t*)QDir::toNativeSeparators(linkName).utf16(), true);
        ppf->Release();
    }
    psl->Release();

    PIDLIST_ABSOLUTE pidl;

    if (SUCCEEDED(SHGetFolderLocation(0, CSIDL_STARTMENU, 0, 0, &pidl))) {
        SHChangeNotify(SHCNE_UPDATEDIR, SHCNF_IDLIST, pidl, 0);
        CoTaskMemFree(pidl);
    }
    if (SUCCEEDED(SHGetFolderLocation(0, CSIDL_COMMON_STARTMENU, 0, 0, &pidl))) {
        SHChangeNotify(SHCNE_UPDATEDIR, SHCNF_IDLIST, pidl, 0);
        CoTaskMemFree(pidl);
    }

    return success;
}

QString Win3SysPath::getWinSysDir(SYSTEMPATH path)
{
    DeCoInitializer _;
    _.noWarrning();
    PIDLIST_ABSOLUTE pidl;  // Force start menu cache update
    wchar_t MyDir[_MAX_PATH] = {0};
    if (SUCCEEDED(SHGetFolderLocation(0, path, 0, 0, &pidl))) {
        SHGetPathFromIDList(pidl,MyDir);
        SHChangeNotify(SHCNE_UPDATEDIR, SHCNF_IDLIST, pidl, 0);
        CoTaskMemFree(pidl);
    }

    return QString::fromWCharArray(MyDir).replace("\\","/");
}

} // QRUNINFO_NAMEPASE_END
