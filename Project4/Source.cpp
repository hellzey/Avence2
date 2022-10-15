#include <windows.h>
#include "resource.h"
#include <CommCtrl.h>
#include <string>
#include <locale.h>
#include <fstream>
#include <vector>
#include <bitset>
#include <CommDlg.h>
using namespace std;
struct usuarios {
    wstring nombreadm;
    wstring contraadm;
    wstring comercioadm;
    wstring nomcom;
    wstring alias;
    wstring foto;
    usuarios* siguente;
    usuarios* anterio;

};
usuarios* auxiliar = nullptr;
usuarios* raiz = nullptr;

//#pragma warning (disable : 4996)

HMENU hmenu;
HINSTANCE hintance;
HWND ghDlg = 0;
HWND h_edit;
char contenido_edit[30];
HBITMAP manejador_bitmap;
HWND   personaje;
HINSTANCE hInstGlobal;
HBITMAP logo;
int x = 0;
int y = 0;

LRESULT CALLBACK Registro(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK Menu(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK AltaAdmin(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK BajaAdmin(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ActuaAdmin(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ListaAdmin(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK AltaCliente(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK BajaCliente(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ActuaCliente(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ListaCliente(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK AltaPromo(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK BajaPromo(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ActuaPromo(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ListaPromo(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK AltaConsumo(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ListaConsumo(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);



int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow)
{
    hInstGlobal = hInstance; 
    ghDlg = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (DLGPROC)WindowProc);
    ShowWindow(ghDlg, nCmdShow);
    MSG msg;
    ZeroMemory(&msg, sizeof(MSG));
    while (GetMessage(&msg, 0, 0, 0))   
    {
        if (ghDlg == 0 || !IsDialogMessage(ghDlg, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int)msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
       
     
    case WM_INITDIALOG:
        logo = (HBITMAP)LoadImage(NULL, "logo.bmp", IMAGE_BITMAP, 50, 50, LR_LOADFROMFILE);
        SendDlgItemMessage(hwnd, imagen, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)logo);
//hmenu = LoadMenu(hintance, MAKEINTRESOURCE(IDR_MENU2));
//        SetMenu(hwnd, hmenu);
        break;
     
    case WM_COMMAND:

        switch (LOWORD(wParam))
        {
        case 1003: 
            
             DialogBox(hInstGlobal, MAKEINTRESOURCE(IDD_DIALOG3), NULL, Menu); 
            break;
        case 1016:
          
            DialogBox(hInstGlobal, MAKEINTRESOURCE(IDD_DIALOG2), NULL, Registro);
            break;
        case 1015:

            break;

        case 1010:
         
            break;

        }   
        break;

    case WM_CLOSE:
        DestroyWindow(hwnd);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    }
  
    return FALSE;
}

LRESULT CALLBACK Registro(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE:

    case WM_INITDIALOG:
        hmenu = LoadMenu(hintance, MAKEINTRESOURCE(IDR_MENU2));
        SetMenu(hwnd, hmenu);
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
       
        case boton:
            DestroyWindow(hwnd);
            break;
        case IDC_BUTTON1:
            int opc = MessageBox(hwnd, "Admin Registrado ¿Desea salir?", "AVISO", MB_YESNO | MB_ICONQUESTION);
            if (opc == IDYES)
                DestroyWindow(hwnd);
            break;
        }
        break;
    case WM_CLOSE:
        int opc = MessageBox(hwnd, "¿Seguro que desea salir?", "AVISO", MB_YESNO | MB_ICONQUESTION);
        if (opc == IDYES)
            DestroyWindow(hwnd);

        break;

    }
    return 0;
}
LRESULT CALLBACK Menu(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  
    switch ( uMsg) {
    case WM_CREATE:HMENU hmenu;
    case WM_INITDIALOG:
 hmenu = LoadMenu(hintance, MAKEINTRESOURCE(IDR_MENU2));
        SetMenu(hwnd, hmenu);
        break; 
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDC_BUTTON1:
            DialogBox(hInstGlobal, MAKEINTRESOURCE(IDD_DIALOG4), NULL, AltaAdmin);
            break;
        case IDC_BUTTON2:
            DialogBox(hInstGlobal, MAKEINTRESOURCE(IDD_DIALOG5), NULL, BajaAdmin);
            break;
        case IDC_BUTTON3:
            DialogBox(hInstGlobal, MAKEINTRESOURCE(IDD_DIALOG6), NULL,ActuaAdmin);
            break;
        case IDC_BUTTON4:
            DialogBox(hInstGlobal, MAKEINTRESOURCE(IDD_DIALOG7), NULL,ListaAdmin);
            break;
        case IDC_BUTTON5:
            DialogBox(hInstGlobal, MAKEINTRESOURCE(IDD_DIALOG8), NULL, AltaCliente);
            break;
        case IDC_BUTTON6:
            DialogBox(hInstGlobal, MAKEINTRESOURCE(IDD_DIALOG9), NULL, BajaCliente);
            break;
        case IDC_BUTTON7:
            DialogBox(hInstGlobal, MAKEINTRESOURCE(IDD_DIALOG10), NULL, ActuaCliente);
            break;
        case IDC_BUTTON8:
            DialogBox(hInstGlobal, MAKEINTRESOURCE(IDD_DIALOG11), NULL, ListaCliente);
            break;
        case IDC_BUTTON9:
            DialogBox(hInstGlobal, MAKEINTRESOURCE(IDD_DIALOG12), NULL, AltaPromo);
            break;
        case IDC_BUTTON10:
            DialogBox(hInstGlobal, MAKEINTRESOURCE(IDD_DIALOG13), NULL, BajaPromo);
            break;
        case IDC_BUTTON11:
            DialogBox(hInstGlobal, MAKEINTRESOURCE(IDD_DIALOG18), NULL, ActuaPromo);
            break;
        case IDC_BUTTON12:
            DialogBox(hInstGlobal, MAKEINTRESOURCE(IDD_DIALOG15), NULL, ListaPromo);
            break;
        case IDC_BUTTON13:
            DialogBox(hInstGlobal, MAKEINTRESOURCE(IDD_DIALOG16), NULL, AltaConsumo);
            break;
        case IDC_BUTTON14:
            DialogBox(hInstGlobal, MAKEINTRESOURCE(IDD_DIALOG17), NULL, ListaConsumo);
            break;
        case IDC_BUTTON16:
            int opc = MessageBox(hwnd, "¿Desea salir?", "AVISO", MB_YESNO | MB_ICONQUESTION);
            if (opc == IDYES)
                DestroyWindow(hwnd);
            break;
 }
        break; 
            break;
    case WM_CLOSE:
        int opc = MessageBox(hwnd, "¿Seguro que desea salir?", "AVISO", MB_YESNO | MB_ICONQUESTION);
        if (opc == IDYES)
            DestroyWindow(hwnd);
        break;
    }
    return 0;
}


LRESULT CALLBACK AltaAdmin(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg ) {
    case WM_INITDIALOG:

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case 109:
            DestroyWindow(hwnd);
            break;
    
        case nose:
            MessageBox(hwnd, "Alta realizada", "AVISO", MB_ICONQUESTION);
                DestroyWindow(hwnd);
            break;
        }
        break;
    
    case WM_CLOSE:
        int opc = MessageBox(hwnd, "¿Seguro que desea salir?", "AVISO", MB_YESNO | MB_ICONQUESTION);
        if (opc == IDYES)
            DestroyWindow(hwnd);

        break;

    }
    return 0;
}
LRESULT CALLBACK BajaAdmin(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_INITDIALOG:

        break;

    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case wea3:
            MessageBox(hwnd, "Baja realizada", "AVISO",MB_ICONQUESTION);
            DestroyWindow(hwnd);
            
            break;

        }
        break;
    case WM_CLOSE:
        int opc = MessageBox(hwnd, "¿Seguro que desea salir?", "AVISO", MB_YESNO | MB_ICONQUESTION);
        if (opc == IDYES)
            DestroyWindow(hwnd);

        break;

    }
    return 0;
}
LRESULT CALLBACK ActuaAdmin(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_INITDIALOG:

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case wea5:
            DestroyWindow(hwnd);
            break;

        }
        break;
    case WM_CLOSE:
        int opc = MessageBox(hwnd, "¿Seguro que desea salir?", "AVISO", MB_YESNO | MB_ICONQUESTION);
        if (opc == IDYES)
            DestroyWindow(hwnd);

        break;

    }
    return 0;
}
LRESULT CALLBACK ListaAdmin(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_INITDIALOG:

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case wea6:
            DestroyWindow(hwnd);
            break;

        }
        break;
    case WM_CLOSE:
        int opc = MessageBox(hwnd, "¿Seguro que desea salir?", "AVISO", MB_YESNO | MB_ICONQUESTION);
        if (opc == IDYES)
            DestroyWindow(hwnd);

        break;

    }
    return 0;
}
LRESULT CALLBACK AltaCliente(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_INITDIALOG:

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case wea7:MessageBox(hwnd, "Alta realizada", "AVISO", MB_ICONQUESTION); 
            DestroyWindow(hwnd);
            break;
            case wea8: 
                DestroyWindow(hwnd);
            break;

        }
        break;
    case WM_CLOSE:
        int opc = MessageBox(hwnd, "¿Seguro que desea salir?", "AVISO", MB_YESNO | MB_ICONQUESTION);
        if (opc == IDYES)
            DestroyWindow(hwnd);

        break;

    }
    return 0;
}
LRESULT CALLBACK BajaCliente(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_INITDIALOG:

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) { 
        case wea9:
            DestroyWindow(hwnd);
            break;
        case wea10:
            MessageBox(hwnd, "Baja realizada", "AVISO", MB_ICONQUESTION);
            DestroyWindow(hwnd);
            break;
        }
        break;
        
    
    case WM_CLOSE:
        int opc = MessageBox(hwnd, "¿Seguro que desea salir?", "AVISO", MB_YESNO | MB_ICONQUESTION);
        if (opc == IDYES)
            DestroyWindow(hwnd);

        break;

    }
    return 0;
}
LRESULT CALLBACK ActuaCliente(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_INITDIALOG:

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case wea11:
            DestroyWindow(hwnd);
            break;
        case wea12: MessageBox(hwnd, "Actulizacion realizada", "AVISO", MB_ICONQUESTION);
            DestroyWindow(hwnd);
            break;
          

        }
        break;
    case WM_CLOSE:
        int opc = MessageBox(hwnd, "¿Seguro que desea salir?", "AVISO", MB_YESNO | MB_ICONQUESTION);
        if (opc == IDYES)
            DestroyWindow(hwnd);

        break;

    }
    return 0;
}
LRESULT CALLBACK ListaCliente(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_INITDIALOG:
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case wea12:
            DestroyWindow(hwnd);
            break;

        }
        break;
       
    
    case WM_CLOSE:
        int opc = MessageBox(hwnd, "¿Seguro que desea salir?", "AVISO", MB_YESNO | MB_ICONQUESTION);
        if (opc == IDYES)
            DestroyWindow(hwnd);

        break;

    }
    return 0;
}
LRESULT CALLBACK AltaPromo(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_INITDIALOG:

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case wea13: DestroyWindow(hwnd);
            break;
        case wea14:MessageBox(hwnd, "Alta realizada", "AVISO", MB_ICONQUESTION);
            DestroyWindow(hwnd);
            break;

        }
        break;
    case WM_CLOSE:
        int opc = MessageBox(hwnd, "¿Seguro que desea salir?", "AVISO", MB_YESNO | MB_ICONQUESTION);
        if (opc == IDYES)
            DestroyWindow(hwnd);

        break;

    }
    return 0;
}
LRESULT CALLBACK BajaPromo(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_INITDIALOG:

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case wea15: 
            DestroyWindow(hwnd);
            break;
        case wea16:
            MessageBox(hwnd, "Baja realizada", "AVISO", MB_ICONQUESTION);
            DestroyWindow(hwnd);
            break;

        }
        break;
    case WM_CLOSE:
        int opc = MessageBox(hwnd, "¿Seguro que desea salir?", "AVISO", MB_YESNO | MB_ICONQUESTION);
        if (opc == IDYES)
            DestroyWindow(hwnd);

        break;

    }
    return 0;
}
LRESULT CALLBACK ActuaPromo(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_INITDIALOG:

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case wea17:  DestroyWindow(hwnd);
            break;
        case wea18: MessageBox(hwnd, "Actualizacion realizada", "AVISO", MB_ICONQUESTION);
            DestroyWindow(hwnd);
            break;

        }
        break;
    case WM_CLOSE:
        int opc = MessageBox(hwnd, "¿Seguro que desea salir?", "AVISO", MB_YESNO | MB_ICONQUESTION);
        if (opc == IDYES)
            DestroyWindow(hwnd);

        break;

    }
    return 0;
}
LRESULT CALLBACK ListaPromo(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_INITDIALOG:

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case wea19:  DestroyWindow(hwnd);
            break;

        }
        break;
    case WM_CLOSE:
        int opc = MessageBox(hwnd, "¿Seguro que desea salir?", "AVISO", MB_YESNO | MB_ICONQUESTION);
        if (opc == IDYES)
            DestroyWindow(hwnd);

        break;

    }
    return 0;
}
LRESULT CALLBACK AltaConsumo(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_INITDIALOG:

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case wea20:DestroyWindow(hwnd);
            break;
        case wea21:MessageBox(hwnd, "Alta realizada", "AVISO", MB_ICONQUESTION);
            DestroyWindow(hwnd);
                break;

        }
        break;
    case WM_CLOSE:
        int opc = MessageBox(hwnd, "¿Seguro que desea salir?", "AVISO", MB_YESNO | MB_ICONQUESTION);
        if (opc == IDYES)
            DestroyWindow(hwnd);

        break;

    }
    return 0;
}
LRESULT CALLBACK ListaConsumo (HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
 {
    switch (uMsg) {
    case WM_INITDIALOG:

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case wea22:DestroyWindow(hwnd);
            break;

        }
        break;
    case WM_CLOSE:
        int opc = MessageBox(hwnd, "¿Seguro que desea salir?", "AVISO", MB_YESNO | MB_ICONQUESTION);
        if (opc == IDYES)
            DestroyWindow(hwnd);

        break;

    }
    return 0;
}
