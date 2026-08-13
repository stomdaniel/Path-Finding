/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : FileLoader.cpp
Description : Loads a file from fileexplorer.
Author : Daniel Kane
Mail : daniel.kane@mds.ac.nz
**************************************************************************/

#include "FileLoader.h"

/// <summary>
/// Load file from file explorer.
/// </summary>
/// <param name="_file"></param>
void LoadFile(std::ifstream* _file)
{
    HRESULT hResult = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

    if (SUCCEEDED(hResult))
    {
        IFileOpenDialog* fileOpen = nullptr;

        hResult = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
            IID_IFileOpenDialog, reinterpret_cast<void**>(&fileOpen));

        COMDLG_FILTERSPEC rgSpec[] =
        {
            { L"TXT (*.txt)", L"*.txt" },
            { L"ALL", L"*.*" }
        };

        LPCWSTR fileName = L"untitled.txt";


        fileOpen->SetFileTypes(2, rgSpec);

        if (SUCCEEDED(hResult))
        {
            hResult = fileOpen->Show(NULL);

            if (SUCCEEDED(hResult))
            {
                IShellItem* item = nullptr;

                hResult = fileOpen->GetResult(&item);

                if (SUCCEEDED(hResult))
                {
                    PWSTR filePath;
                    hResult = item->GetDisplayName(SIGDN_FILESYSPATH, &filePath);

                    if (SUCCEEDED(hResult))
                    {
                        _file->open(filePath);

                        CoTaskMemFree(filePath);
                    }

                    item->Release();
                }
            }
            fileOpen->Release();
        }
        CoUninitialize();
    }
}

/// <summary>
/// Save file.
/// </summary>
/// <param name="_file"></param>
void SaveFile(std::ofstream* _file)
{
    HRESULT hResult = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

    if (SUCCEEDED(hResult))
    {
        IFileSaveDialog* fileSave = nullptr;

        hResult = CoCreateInstance(CLSID_FileSaveDialog, NULL, CLSCTX_ALL,
            IID_IFileSaveDialog, reinterpret_cast<void**>(&fileSave));


        COMDLG_FILTERSPEC rgSpec[] =
        {
            { L"TXT (*.txt)", L"*.txt" },
            { L"ALL", L"*.*" }
        };

        LPCWSTR fileName = L"untitled.txt";


        fileSave->SetFileName(fileName);
        fileSave->SetFileTypes(2, rgSpec);


        if (SUCCEEDED(hResult))
        {
            hResult = fileSave->Show(NULL);

            if (SUCCEEDED(hResult))
            {
                IShellItem* item = nullptr;

                hResult = fileSave->GetResult(&item);

                if (SUCCEEDED(hResult))
                {
                    PWSTR filePath;

                    hResult = item->GetDisplayName(SIGDN_FILESYSPATH, &filePath);

                    if (SUCCEEDED(hResult))
                    {
                        _file->open(filePath);

                        CoTaskMemFree(filePath);
                    }
                    item->Release();
                }
            }
            fileSave->Release();
        }
        CoUninitialize();
    }
}