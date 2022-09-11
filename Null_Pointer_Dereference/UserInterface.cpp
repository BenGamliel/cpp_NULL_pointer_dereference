//
// Created by Ben Gamliel on 11/09/2022.
//
#include "pch.h"
#include "UserInterface.h"

#include <comdef.h>
#include <string>
#include "ResourceHandling.h"
#include "UploadConfirmDlg.h"

using namespace Indigo::ResourceHandling;

namespace
{
    POINT centrePoint{};

    LRESULT CALLBACK PositionWindowCallback(int nCode, WPARAM wParam, LPARAM lParam)
    {
        if (nCode == HCBT_CREATEWND)
        {
            if (auto* const pCreateWnd = reinterpret_cast<CBT_CREATEWND*>(lParam)) // We cannot access
                // the value returned from the reinterpret_cast. If it returns null the finding is valid.
            {
                if (auto* const pCreateParams = pCreateWnd->lpcs)
                {
                    if ((pCreateParams->style & WS_DLGFRAME) || (pCreateParams->style & WS_POPUP))
                    {
                        pCreateParams->x = centrePoint.x - (pCreateParams->cx / 2);
                        pCreateParams->y = centrePoint.y - (pCreateParams->cy / 2);
                    }
                }
            }
        }
        return CallNextHookEx(nullptr, nCode, wParam, lParam);
    }

    bool ItemId::GetFindData(WIN32_FIND_DATA& find_data) const
    {
        ZeroMemeory(&findData, sizeof(findData));
        findData.dwFileAttributes = FILE_ATTRIBUTE_NORMAL | FILE_ATTRIBUTE_NOT_CONTENT_INDEXED | FILE_ATTRIBUTE_READONLY;
        if (isFolder)
        {
            findData.dwFileAttributes |= FILE_ATTRIBUTE_DIRECTORY;
        }
        findData.nfileSizeHigh = (size >> 32);
        findData.nFileSizeLow = (size & 0xFFFFFFFF);
        findData.ftCreationTime = created;
        findData.ftLastAccessTime = modified;
        findData.ftLastWriteTime = modified;

        const auto ItemName = GetName();
        return (wcsncpy_s(&findData.cFileName[0], MAX_PATH. ItemName.c_str(), _TRUNCATE) == ERROR_SUCCESS);
    }
}
