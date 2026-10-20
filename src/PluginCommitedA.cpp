// PluginCommited.cpp
// TrafficMonitor plugin: display Windows Committed memory (提交内存) percentage and amount.
// Built against PluginInterface.h from V1.86 tag (API version 7).
// Compiler: MSVC (cl.exe), no MFC dependency.

#include "inc/PluginInterface.h"
#include <windows.h>
#include <psapi.h>
#include <string>

#pragma comment(lib, "psapi.lib")

//------------------------------------------------------------------------------
// Item 1: committed memory percentage
class CCommitedPercentItem : public IPluginItem
{
public:
    const wchar_t* GetItemName() const override
    {
        return L"已提交内存百分比";
    }

    const wchar_t* GetItemId() const override
    {
        return L"commited_mem_percent";   // keep id stable, used by config
    }

    const wchar_t* GetItemLableText() const override
    {
        return L"提交:";
    }

    const wchar_t* GetItemValueText() const override
    {
        return m_strValue.c_str();
    }

    const wchar_t* GetItemValueSampleText() const override
    {
        return L"100%";
    }

    int IsDrawResourceUsageGraph() const override
    {
        return 1;
    }

    float GetResourceUsageGraphValue() const override
    {
        return m_usage_float;
    }

    void SetValue(int percent, float usage_float, const std::wstring& text)
    {
        m_usage_float = usage_float;
        m_strValue = text;
    }

private:
    std::wstring m_strValue = L"0%";
    float m_usage_float = 0.0f;
};

//------------------------------------------------------------------------------
// Item 2: committed memory amount (GB)
class CCommitedAmountItem : public IPluginItem
{
public:
    const wchar_t* GetItemName() const override
    {
        return L"已提交内存量";
    }

    const wchar_t* GetItemId() const override
    {
        return L"commited_mem_amount";
    }

    const wchar_t* GetItemLableText() const override
    {
        return L"已提交:";
    }

    const wchar_t* GetItemValueText() const override
    {
        return m_strValue.c_str();
    }

    const wchar_t* GetItemValueSampleText() const override
    {
        // 必须 >= 实际 GetItemValueText 的宽度，否则数值右对齐会向左溢出压到标签
        return L"999.9/999.9 GB";
    }

    void SetValue(const std::wstring& text)
    {
        m_strValue = text;
    }

private:
    std::wstring m_strValue = L"0G";
};

//------------------------------------------------------------------------------
// Plugin implementation
class CCommitedPlugin : public ITMPlugin
{
public:
    CCommitedPlugin()
    {
    }

    // ITMPlugin
    IPluginItem* GetItem(int index) override
    {
        switch (index)
        {
        case 0: return &m_percent_item;
        case 1: return &m_amount_item;
        default: return nullptr;
        }
    }

    void DataRequired() override
    {
        PERFORMANCE_INFORMATION pi = {};
        pi.cb = sizeof(pi);
        if (::GetPerformanceInfo(&pi, sizeof(pi)))
        {
            if (pi.CommitLimit == 0) return;   // guard against divide-by-zero

            const auto commit_total = pi.CommitTotal * pi.PageSize;
            const auto commit_limit = pi.CommitLimit * pi.PageSize;

            // percentage 0..100
            const double percent = static_cast<double>(commit_total) / static_cast<double>(commit_limit) * 100.0;

            // format: "45.2%"
            wchar_t buf[32] = {};
            swprintf_s(buf, L"%.1f%%", percent);
            m_percent_item.SetValue(static_cast<int>(percent), static_cast<float>(percent / 100.0), buf);

            // format amount as "37.3/43.4 GB" (已提交/提交限额, 单位后置, 一位小数, 斜杠无空格)
            wchar_t buf2[64] = {};
            const double gb_total = static_cast<double>(commit_total) / (1024.0 * 1024.0 * 1024.0);
            const double gb_limit = static_cast<double>(commit_limit) / (1024.0 * 1024.0 * 1024.0);
            swprintf_s(buf2, L"%.1f/%.1f GB", gb_total, gb_limit);
            m_amount_item.SetValue(buf2);
        }
    }

    const wchar_t* GetInfo(PluginInfoIndex index) override
    {
        switch (index)
        {
        case TMI_NAME:        return L"已提交内存";
        case TMI_DESCRIPTION: return L"显示Windows已提交内存(提交量/提交限制)百分比与数值";
        case TMI_AUTHOR:      return L"DeskApps";
        case TMI_COPYRIGHT:   return L"";
        case TMI_VERSION:     return L"1.0.0";
        case TMI_URL:         return L"";
        default:              return L"";
        }
    }

    void OnInitialize(ITrafficMonitor* pApp) override
    {
        m_pApp = pApp;
    }

private:
    CCommitedPercentItem m_percent_item;
    CCommitedAmountItem m_amount_item;
    ITrafficMonitor* m_pApp = nullptr;
};

//------------------------------------------------------------------------------
// export entry point (must match PluginInterface.h requirement)
extern "C" __declspec(dllexport) ITMPlugin* TMPluginGetInstance()
{
    static CCommitedPlugin plugin;
    return &plugin;
}
