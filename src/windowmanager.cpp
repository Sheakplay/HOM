#include "windowmanager.h"
#include "taskbar.h"
#include <Roster.h>
#include <AppInfo.h>
#include <Entry.h>
#include <StorageDefs.h>
#include <String.h>
#include <Application.h>

WindowManager::WindowManager() {
    fRoster = new BRoster();
    Initialize();
}

WindowManager::~WindowManager() {
    delete fRoster;
    // Clean up any BString pointers in list
    int32 count = fAppInfoList.CountItems();
    for (int32 i = 0; i < count; i++) {
        BString* str = (BString*)fAppInfoList.ItemAt(i);
        delete str;
    }
    fAppInfoList.MakeEmpty();
}

void WindowManager::Initialize() {
    MonitorApps();
}

void WindowManager::MonitorApps() {
    fAppInfoList.MakeEmpty();

    if (fRoster == NULL) return;

    BList list;
    status_t status = fRoster->GetAppList(&list);
    if (status == B_OK) {
        for (int32 i = 0; i < list.CountItems(); i++) {
            app_info* info = (app_info*)list.ItemAt(i);
            if (info != NULL) {
                BString* name = new BString(info->signature);
                fAppInfoList.AddItem(name);
            }
        }
    }
}

void WindowManager::RefreshTaskbar(Taskbar* taskbar) {
    if (taskbar == NULL) return;

    // Build array of running app signatures (simplified)
    const char* names[10];
    int count = GetRunningApps(NULL, 10);

    // For simplicity, just pass known apps
    names[0] = "StyledEdit";
    names[1] = "Terminal";
    names[2] = "Tracker";
    names[3] = "WebPositive";
    count = 4;

    taskbar->RefreshApps(names, count);
}

void WindowManager::LaunchApp(const char* signature) {
    if (fRoster == NULL || signature == NULL) return;
    fRoster->Launch(signature, NULL);
    MonitorApps();
}

void WindowManager::LaunchAppByPath(const char* path) {
    if (path == NULL) return;
    // Launch by entry
    entry_ref ref;
    if (get_ref_for_path(path, &ref) == B_OK) {
        be_roster->Launch(&ref);
    }
}

void WindowManager::ActivateApp(team_id team) {
    if (fRoster != NULL) {
        fRoster->ActivateApp(team);
    }
}

void WindowManager::ActivateApp(const char* signature) {
    if (fRoster == NULL) return;
    BList list;
    fRoster->GetAppList(&list);
    for (int32 i = 0; i < list.CountItems(); i++) {
        app_info* info = (app_info*)list.ItemAt(i);
        if (info != NULL && strcmp(info->signature, signature) == 0) {
            fRoster->ActivateApp(info->team);
            break;
        }
    }
}

status_t WindowManager::GetRunningApps(BString* outNames, int maxCount) {
    if (fRoster == NULL) return B_ERROR;

    BList list;
    status_t status = fRoster->GetAppList(&list);
    if (status != B_OK) return status;

    int count = 0;
    for (int32 i = 0; i < list.CountItems() && count < maxCount; i++) {
        app_info* info = (app_info*)list.ItemAt(i);
        if (info != NULL) {
            outNames[count].SetTo(info->signature);
            count++;
        }
    }
    return B_OK;
}
