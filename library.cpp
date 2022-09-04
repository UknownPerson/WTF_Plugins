
#include "library.h"

using namespace std;

CPluginTemplate CPluginTemplate::m_instance;

CPluginTemplate::CPluginTemplate() {
}

CPluginTemplate &CPluginTemplate::Instance() {
    return m_instance;
}

IPluginItem *CPluginTemplate::GetItem(int index) {
    switch (index) {
        case 0:
            //return &m_item;
        default:
            break;
    }
    return nullptr;
}

const wchar_t *CPluginTemplate::GetTooltipInfo() {
    return m_tooltip_info.c_str();
}

void CPluginTemplate::DataRequired() {
    //TODO: 在此添加获取监控数据的代码
}

ITMPlugin::OptionReturn CPluginTemplate::ShowOptionsDialog(void *hParent) {
    /*
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    CWnd* pParent = CWnd::FromHandle((HWND)hParent);
    COptionsDlg dlg(pParent);
    dlg.m_data = g_data.m_setting_data;
    if (dlg.DoModal() == IDOK)
    {
        g_data.m_setting_data = dlg.m_data;
        return ITMPlugin::OR_OPTION_CHANGED;
    }
     */
    return ITMPlugin::OR_OPTION_UNCHANGED;
}

const wchar_t *CPluginTemplate::GetInfo(PluginInfoIndex index) {
    static string str;
    switch (index) {

        case TMI_NAME:
            return L"WTF Plugins";
        case TMI_DESCRIPTION:
            return L"添加一些随便写的东西";
        case TMI_AUTHOR:
            //TODO: 在此返回作者的名字
            return L"UknownPerson";
        case TMI_COPYRIGHT:
            //TODO: 在此返回版权信息
            return L"Copyright (C) by UknownPerson 2022";
        case ITMPlugin::TMI_URL:
            //TODO: 在此返回URL
            return L"https://github.com/UknownPerson";
            break;
        case TMI_VERSION:
            //TODO: 在此修改插件的版本
            return L"1.0";
        default:
            break;
    }
    return L"";
}

ITMPlugin *TMPluginGetInstance() {
    // AFX_MANAGE_STATE(AfxGetStaticModuleState());
    return &CPluginTemplate::Instance();
}