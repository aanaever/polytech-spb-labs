
// GraphDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Graph.h"
#include "GraphDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CGraphDlg



CGraphDlg::CGraphDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GRAPH_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGraphDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGraphDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT_BUTTON, &CGraphDlg::OnClickedExitButton)
	ON_WM_DESTROY()
	ON_WM_TIMER()
//	ON_BN_CLICKED(IDC_DRAWGRAPHICS_BUTTON, &CGraphDlg::OnClickedDrawgraphicsButton)
ON_BN_CLICKED(IDC_DRAWGRAPHICS_BUTTON, &CGraphDlg::OnClickedDrawgraphicsButton)
//ON_NOTIFY(BCN_DROPDOWN, IDC_DRAWGRAPHICS_BUTTON, &CGraphDlg::OnDropdownDrawgraphicsButton)
ON_COMMAND(IDC_RED_RADIO, &CGraphDlg::OnRedRadio)
END_MESSAGE_MAP()


// Обработчики сообщений CGraphDlg

BOOL CGraphDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	///Установить системный таймер
	///Установить системный таймер
	int iInstallResult;
	iInstallResult = SetTimer(1, 50, NULL);
	if (iInstallResult == FALSE)
	{
		MessageBox(L"Cannot install timer",
			L"Error message",
			MB_OK + MB_ICONERROR);
	}

	//Выбрать радиокнопку RED
	m_dlg.m_RedRadio = 0;

	m_Radius = 50;
	m_Direction = 1;
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CGraphDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CGraphDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//OnClickedDrawgraphicsButton();

		///Создать объект контекста устройства(DC)
		CPaintDC dc(this);

		//Создать новое перо
		CPen MyNewPen;
		//MyNewPen.CreatePen(PS_SOLID, 10, RGB(255,0,0));

		switch (m_dlg.m_RedRadio)
		{
		case 0:
			MyNewPen.CreatePen(PS_SOLID, 10, RGB(255, 0, 0));
			break;
		case 1:
			MyNewPen.CreatePen(PS_SOLID, 10, RGB(0, 255, 0));
			break;
		case 2:
			MyNewPen.CreatePen(PS_SOLID, 10, RGB(0, 0, 255));
			break;
		}
		//Выбрать перо
		CPen* pOriginalPen;
		pOriginalPen = dc.SelectObject(&MyNewPen);
		// CRect MyRectangle(20, 10, 120,110);

		CRect MyRectangle(20, 10, 20 + m_Radius * 2, 10 + m_Radius * 2);

		//Нарисовать круг
		dc.Ellipse(&MyRectangle);

		//Выбрать первоначальное перо
		dc.SelectObject(pOriginalPen);

		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CGraphDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGraphDlg::OnClickedExitButton()
{
	// TODO: добавьте свой код обработчика уведомлений
	OnOK();
}


void CGraphDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: добавьте свой код обработчика сообщений
	KillTimer(1);
}


void CGraphDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	//MessageBeep((WORD)-2);
	m_Radius = m_Radius + m_Direction;
	if (m_Radius >= 100)
	{
		m_Direction = -1;
	}
	if (m_Radius <= 10)
	{
		m_Direction = 1;
	}

	CDialogEx::OnTimer(nIDEvent);
}


//void CGraphDlg::OnClickedDrawgraphicsButton()
//{
	// TODO: добавьте свой код обработчика уведомлений
//}


void CGraphDlg::OnClickedDrawgraphicsButton()
{
	// TODO: добавьте свой код обработчика уведомлений
	m_dlg.DoModal();

}





//void CGraphDlg::OnDropdownDrawgraphicsButton(NMHDR* pNMHDR, LRESULT* pResult)
//{
//	LPNMBCDROPDOWN pDropDown = reinterpret_cast<LPNMBCDROPDOWN>(pNMHDR);
	// TODO: добавьте свой код обработчика уведомлений
//	*pResult = 0;
//}


void CGraphDlg::OnRedRadio()
{
	// TODO: добавьте свой код обработчика команд
	UpdateData(TRUE);
}
