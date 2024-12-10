
// FourUpDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "FourUp.h"
#include "FourUpDlg.h"
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


// Диалоговое окно CFourUpDlg



CFourUpDlg::CFourUpDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FOURUP_DIALOG, pParent)
{
	

	m_Club = AfxGetApp()->LoadIcon(IDI_CLUB);
	m_Diamond = AfxGetApp()->LoadIcon(IDI_DIAMOND);
	m_Heart = AfxGetApp()->LoadIcon(IDI_HEART);
	m_Spade = AfxGetApp()->LoadIcon(IDI_SPADE);


}

void CFourUpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CARD1, m_Card1);
	DDX_Control(pDX, IDC_CARD2, m_Card2);
	DDX_Control(pDX, IDC_CARD3, m_Card3);
	DDX_Control(pDX, IDC_CARD4, m_Card4);
	DDX_Control(pDX, IDC_AMT_LEFT, m_Amt_Left);
	
}

BEGIN_MESSAGE_MAP(CFourUpDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDC_DEALCARDS, &CFourUpDlg::OnClickedDealcards)
	ON_BN_CLICKED(IDCANCEL, &CFourUpDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_DEALCARDS, &CFourUpDlg::OnClickedDealcards)
END_MESSAGE_MAP()


// Обработчики сообщений CFourUpDlg

BOOL CFourUpDlg::OnInitDialog()
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

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CFourUpDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFourUpDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CFourUpDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFourUpDlg::OnClickedDealcards()
{
	// TODO: добавьте свой код обработчика уведомлений
	//Отнять два доллара при сдаче карт
	m_Amt_Remaining -= 2.00;

	//Сдать карты
	DealCards();

	//Подсчитать выйгрыш
	CalculateWinnings();

	//Изменить заголовок элемента Group Box
	CString s;
	s.Format(L"Amount Remaining $ %.2f", m_Amt_Remaining);
	m_Amt_Left.SetWindowText(s);

}

void CFourUpDlg::DealCards()
{

	//Обнуляем заначение выпавших карт одной масти
	for (int i = 0; i < 4; i++)m_Cards[i] = 0;

	//Меняем иконку в элементах управления иконками
	m_Card1.SetIcon(PickRandomCard());
	m_Card2.SetIcon(PickRandomCard());
	m_Card3.SetIcon(PickRandomCard());
	m_Card4.SetIcon(PickRandomCard());
}

HICON& CFourUpDlg::PickRandomCard()
{

	//Выбрать номер карты случайным образом
	int num = (rand() % 4);
	/*Проссумировать кол-во выпавших карт одной масти*/
	m_Cards[num]++;

	/*В зависимости от выпавшего номера вернуть адрес иконки*/
	switch (num)
	{
	case 0: return m_Club;
	case 1: return m_Diamond;
	case 2: return m_Heart;
	}
	return m_Spade;
}

void CFourUpDlg::CalculateWinnings()
{
	int pairs = 0;
	for (int i = 0; i < 4; i++)
	{
		if (m_Cards[i] == 2)
		{
			if (pairs > 0)
			{
				m_Amt_Remaining += 3.00;
				break;
			}
			else
			{
				pairs++;
			}
		}
		else if (m_Cards[i] == 3)
		{
			m_Amt_Remaining += 6.00;
			break;

		}
		else if (m_Cards[i] == 4)
		{
			m_Amt_Remaining += 9.00;
			break;
		}
	}
}


void CFourUpDlg::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений

	CString s;
	//Добавить в сторку размер выйгрыша
	s.Format(L"Good game! I have $ %.2f.", m_Amt_Remaining);
	//Выдать окно сообщения
	MessageBox(s, L"Thank you for game in FourUp!");

	///-Ваш код заканчивается здесь-///


	CDialogEx::OnCancel();
}
