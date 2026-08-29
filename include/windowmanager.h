#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <Object.h>
#include <String.h>
#include <List.h>
#include <Roster.h>

class Taskbar;

class WindowManager : public BObject {
public:
    WindowManager();
    ~WindowManager();

    void Initialize();
    void MonitorApps();
    void RefreshTaskbar(Taskbar* taskbar);

    void LaunchApp(const char* signature);
    void LaunchAppByPath(const char* path);
    void ActivateApp(team_id team);
    void ActivateApp(const char* signature);

    status_t GetRunningApps(BString* outNames, int maxCount);

private:
    BRoster* fRoster;
    BList fAppInfoList; // holds BString pointers for simplicity
};

#endif // WINDOWMANAGER_H
