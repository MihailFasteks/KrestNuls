
#include <Windows.h>
#include "resource.h"

HINSTANCE hInstance;

INT_PTR CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	::hInstance = hInstance;
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}
static HWND hButtons[9];
static HWND StartNewGame;


HICON hIcon1 = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));


INT_PTR CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		hButtons[0] = GetDlgItem(hwnd, IDC_BUTTON1);
		hButtons[1] = GetDlgItem(hwnd, IDC_BUTTON2);
		hButtons[2] = GetDlgItem(hwnd, IDC_BUTTON3);
		hButtons[3] = GetDlgItem(hwnd, IDC_BUTTON4);
		hButtons[4] = GetDlgItem(hwnd, IDC_BUTTON5);
		hButtons[5] = GetDlgItem(hwnd, IDC_BUTTON6);
		hButtons[6] = GetDlgItem(hwnd, IDC_BUTTON7);
		hButtons[7] = GetDlgItem(hwnd, IDC_BUTTON8);
		hButtons[8] = GetDlgItem(hwnd, IDC_BUTTON9);
		StartNewGame = GetDlgItem(hwnd, IDOK);
		
		

		
		CheckRadioButton(hwnd, IDC_RADIO1, IDC_RADIO2, IDC_RADIO2);
		break;
	}

	case WM_COMMAND:
	{
		if (LOWORD(wParam) == IDOK && HIWORD(wParam) == BN_CLICKED) {
			for (int i = 0; i < 9; i++) {
				EnableWindow(hButtons[i], TRUE);
				SetWindowText(hButtons[i], L"");
			}
		}
		int wmId = LOWORD(wParam);
		switch (wmId)
		{
		case IDC_BUTTON1:
		case IDC_BUTTON2:
		case IDC_BUTTON3:
		case IDC_BUTTON4:
		case IDC_BUTTON5:
		case IDC_BUTTON6:
		case IDC_BUTTON7:
		case IDC_BUTTON8:
		case IDC_BUTTON9:
		{
			if (HIWORD(wParam) == BN_CLICKED)
			{
				HWND hButtonClicked = GetDlgItem(hwnd, wmId);
				EnableWindow(hButtonClicked, FALSE);
				SetWindowText(GetDlgItem(hwnd, wmId), L"X");
				int value;
				bool isEnable;
				do {
					value = rand() % 9;
					isEnable = IsWindowEnabled(hButtons[value]);
				} while (isEnable==false);
				EnableWindow(hButtons[value], FALSE);
				SetWindowText(hButtons[value], L"0");
				
			}
			break;
		}
		default:
			return FALSE;
		}
		wchar_t buttonText[256];
		if ((((IsWindowEnabled(hButtons[0]) == 0) &&
			(GetWindowText(hButtons[0], buttonText, 256) > 0) &&
			(wcscmp(buttonText, L"X") == 0)) &&
			((IsWindowEnabled(hButtons[1]) == 0) &&
			(GetWindowText(hButtons[1], buttonText, 256) > 0) &&
			(wcscmp(buttonText, L"X") == 0))&& ((IsWindowEnabled(hButtons[2]) == 0) &&
				(GetWindowText(hButtons[2], buttonText, 256) > 0) &&
				(wcscmp(buttonText, L"X") == 0)))
			|| (((IsWindowEnabled(hButtons[6]) == 0) &&
				(GetWindowText(hButtons[6], buttonText, 256) > 0) &&
				(wcscmp(buttonText, L"X") == 0)) &&
				((IsWindowEnabled(hButtons[7]) == 0) &&
					(GetWindowText(hButtons[7], buttonText, 256) > 0) &&
					(wcscmp(buttonText, L"X") == 0)) && ((IsWindowEnabled(hButtons[8]) == 0) &&
						(GetWindowText(hButtons[8], buttonText, 256) > 0) &&
						(wcscmp(buttonText, L"X") == 0)))
		|| (((IsWindowEnabled(hButtons[0]) == 0) &&
			(GetWindowText(hButtons[0], buttonText, 256) > 0) &&
			(wcscmp(buttonText, L"X") == 0)) &&
			((IsWindowEnabled(hButtons[3]) == 0) &&
				(GetWindowText(hButtons[3], buttonText, 256) > 0) &&
				(wcscmp(buttonText, L"X") == 0)) && ((IsWindowEnabled(hButtons[6]) == 0) &&
					(GetWindowText(hButtons[6], buttonText, 256) > 0) &&
					(wcscmp(buttonText, L"X") == 0))) 
		|| (((IsWindowEnabled(hButtons[2]) == 0) &&
			(GetWindowText(hButtons[2], buttonText, 256) > 0) &&
			(wcscmp(buttonText, L"X") == 0)) &&
			((IsWindowEnabled(hButtons[5]) == 0) &&
				(GetWindowText(hButtons[5], buttonText, 256) > 0) &&
				(wcscmp(buttonText, L"X") == 0)) && ((IsWindowEnabled(hButtons[8]) == 0) &&
					(GetWindowText(hButtons[8], buttonText, 256) > 0) &&
					(wcscmp(buttonText, L"X") == 0))) 
		|| (((IsWindowEnabled(hButtons[0]) == 0) &&
			(GetWindowText(hButtons[0], buttonText, 256) > 0) &&
			(wcscmp(buttonText, L"X") == 0)) &&
			((IsWindowEnabled(hButtons[4]) == 0) &&
				(GetWindowText(hButtons[4], buttonText, 256) > 0) &&
				(wcscmp(buttonText, L"X") == 0)) && ((IsWindowEnabled(hButtons[8]) == 0) &&
					(GetWindowText(hButtons[8], buttonText, 256) > 0) &&
					(wcscmp(buttonText, L"X") == 0)))
		|| (((IsWindowEnabled(hButtons[2]) == 0) &&
			(GetWindowText(hButtons[2], buttonText, 256) > 0) &&
			(wcscmp(buttonText, L"X") == 0)) &&
			((IsWindowEnabled(hButtons[6]) == 0) &&
				(GetWindowText(hButtons[6], buttonText, 256) > 0) &&
				(wcscmp(buttonText, L"X") == 0)) && ((IsWindowEnabled(hButtons[4]) == 0) &&
					(GetWindowText(hButtons[4], buttonText, 256) > 0) &&
					(wcscmp(buttonText, L"X") == 0)))) {
			MessageBox(NULL, L"Крестики победили", L"", MB_OK);
			for (int i = 0; i < 9; i++) {
				EnableWindow(hButtons[i], TRUE);
				SetWindowText(hButtons[i], L"");
			}

		}
		else if ((((IsWindowEnabled(hButtons[0]) == 0) &&
			(GetWindowText(hButtons[0], buttonText, 256) > 0) &&
			(wcscmp(buttonText, L"0") == 0)) &&
			((IsWindowEnabled(hButtons[1]) == 0) &&
				(GetWindowText(hButtons[1], buttonText, 256) > 0) &&
				(wcscmp(buttonText, L"0") == 0)) && ((IsWindowEnabled(hButtons[2]) == 0) &&
					(GetWindowText(hButtons[2], buttonText, 256) > 0) &&
					(wcscmp(buttonText, L"0") == 0)))
			|| (((IsWindowEnabled(hButtons[6]) == 0) &&
				(GetWindowText(hButtons[6], buttonText, 256) > 0) &&
				(wcscmp(buttonText, L"0") == 0)) &&
				((IsWindowEnabled(hButtons[7]) == 0) &&
					(GetWindowText(hButtons[7], buttonText, 256) > 0) &&
					(wcscmp(buttonText, L"0") == 0)) && ((IsWindowEnabled(hButtons[8]) == 0) &&
						(GetWindowText(hButtons[8], buttonText, 256) > 0) &&
						(wcscmp(buttonText, L"0") == 0)))
			|| (((IsWindowEnabled(hButtons[0]) == 0) &&
				(GetWindowText(hButtons[0], buttonText, 256) > 0) &&
				(wcscmp(buttonText, L"0") == 0)) &&
				((IsWindowEnabled(hButtons[3]) == 0) &&
					(GetWindowText(hButtons[3], buttonText, 256) > 0) &&
					(wcscmp(buttonText, L"0") == 0)) && ((IsWindowEnabled(hButtons[6]) == 0) &&
						(GetWindowText(hButtons[6], buttonText, 256) > 0) &&
						(wcscmp(buttonText, L"0") == 0)))
			|| (((IsWindowEnabled(hButtons[2]) == 0) &&
				(GetWindowText(hButtons[2], buttonText, 256) > 0) &&
				(wcscmp(buttonText, L"0") == 0)) &&
				((IsWindowEnabled(hButtons[5]) == 0) &&
					(GetWindowText(hButtons[5], buttonText, 256) > 0) &&
					(wcscmp(buttonText, L"0") == 0)) && ((IsWindowEnabled(hButtons[8]) == 0) &&
						(GetWindowText(hButtons[8], buttonText, 256) > 0) &&
						(wcscmp(buttonText, L"0") == 0)))
			|| (((IsWindowEnabled(hButtons[0]) == 0) &&
				(GetWindowText(hButtons[0], buttonText, 256) > 0) &&
				(wcscmp(buttonText, L"0") == 0)) &&
				((IsWindowEnabled(hButtons[4]) == 0) &&
					(GetWindowText(hButtons[4], buttonText, 256) > 0) &&
					(wcscmp(buttonText, L"0") == 0)) && ((IsWindowEnabled(hButtons[8]) == 0) &&
						(GetWindowText(hButtons[8], buttonText, 256) > 0) &&
						(wcscmp(buttonText, L"0") == 0)))
			|| (((IsWindowEnabled(hButtons[2]) == 0) &&
				(GetWindowText(hButtons[2], buttonText, 256) > 0) &&
				(wcscmp(buttonText, L"0") == 0)) &&
				((IsWindowEnabled(hButtons[6]) == 0) &&
					(GetWindowText(hButtons[6], buttonText, 256) > 0) &&
					(wcscmp(buttonText, L"0") == 0)) && ((IsWindowEnabled(hButtons[4]) == 0) &&
						(GetWindowText(hButtons[4], buttonText, 256) > 0) &&
						(wcscmp(buttonText, L"0") == 0)))) {
			MessageBox(NULL, L"Нолики победили", L"", MB_OK);
			for (int i = 0; i < 9; i++) {
				EnableWindow(hButtons[i], TRUE);
				SetWindowText(hButtons[i], L"");
			}
		}
	
		break;
	}

	case WM_CLOSE:
		EndDialog(hwnd, 0);
		return TRUE;
	}

	return FALSE;
}