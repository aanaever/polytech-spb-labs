// CSetDlg.cpp: файл реализации
//

#include "pch.h"
#include "Graph.h"
#include "afxdialogex.h"
#include "CSetDlg.h"


// Диалоговое окно CSetDlg

IMPLEMENT_DYNAMIC(CSetDlg, CDialogEx)

CSetDlg::CSetDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CUSTOM_DIALOG, pParent)
	, m_RedRadio(0)
{

}

CSetDlg::~CSetDlg()
{
}

void CSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RED_RADIO, m_RedRadio);
}


BEGIN_MESSAGE_MAP(CSetDlg, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений CSetDlg
