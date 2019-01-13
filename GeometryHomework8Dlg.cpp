
// GeometryHomework8Dlg.cpp : implementation file
// Pictures by www.iconarchive.com and www.slideshare.net

#include "stdafx.h"
#include "GeometryHomework8.h"
#include "GeometryHomework8Dlg.h"
#include "afxdialogex.h"

#include "GeometryHomework.h"

#include <string>
using std::string;

#include <sstream> 
using std::ostringstream;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CGeometryHomework8Dlg dialog



CGeometryHomework8Dlg::CGeometryHomework8Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GEOMETRYHOMEWORK8_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGeometryHomework8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGeometryHomework8Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT4, &CGeometryHomework8Dlg::OnEnChangeEdit4)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CGeometryHomework8Dlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDOK, &CGeometryHomework8Dlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT2, &CGeometryHomework8Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &CGeometryHomework8Dlg::OnEnChangeEdit1)
	ON_STN_CLICKED(IDC_STATIC5, &CGeometryHomework8Dlg::OnStnClickedStatic5)
END_MESSAGE_MAP()


// CGeometryHomework8Dlg message handlers

BOOL CGeometryHomework8Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CTabCtrl* pTab = (CTabCtrl*)GetDlgItem(IDC_TAB1);
	pTab->InsertItem(0, _T("Square"));
	pTab->InsertItem(1, _T("Rectangle"));
	pTab->InsertItem(2, _T("Cirlcle"));
	pTab->InsertItem(3, _T("Cube"));
	pTab->InsertItem(4, _T("Prism/Cuboid"));
	pTab->InsertItem(5, _T("Cylinder"));
	pTab->SetCurSel(0); // set initial control visibility to match this

	// Picture control setup
	// place BMPs in /res, import as bitmap resources (IDB_BITMAP1, IDB_BITMAP2, etc)
	CStatic* pPicture1= (CStatic*)GetDlgItem(IDC_STATIC5);
	pPicture1->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb1 = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture1->SetBitmap(hb1);

	CStatic* pPicture2 = (CStatic*)GetDlgItem(IDC_STATIC6);
	pPicture2->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb2 = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture2->SetBitmap(hb2);

	CStatic* pPicture3 = (CStatic*)GetDlgItem(IDC_STATIC7);
	pPicture3->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb3 = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP3), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture3->SetBitmap(hb3);

	CStatic* pPicture4 = (CStatic*)GetDlgItem(IDC_STATIC8);
	pPicture4->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb4 = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP4), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture4->SetBitmap(hb4);

	CStatic* pPicture5 = (CStatic*)GetDlgItem(IDC_STATIC9);
	pPicture5->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb5 = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP5), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture5->SetBitmap(hb5);

	CStatic* pPicture6 = (CStatic*)GetDlgItem(IDC_STATIC10);
	pPicture6->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb6 = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP6), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture6->SetBitmap(hb6);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGeometryHomework8Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGeometryHomework8Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGeometryHomework8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGeometryHomework8Dlg::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGeometryHomework8Dlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	// get pointers to all controls in all tabs
	CEdit* pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
	CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_EDIT3);
	CEdit* pEdit4 = (CEdit*)GetDlgItem(IDC_EDIT4);
	CStatic* pStatic1 = (CStatic*)GetDlgItem(IDC_STATIC1);
	CStatic* pStatic2 = (CStatic*)GetDlgItem(IDC_STATIC2);
	CStatic* pStatic3 = (CStatic*)GetDlgItem(IDC_STATIC3);
	CStatic* pPicture1 = (CStatic*)GetDlgItem(IDC_STATIC5);
	CStatic* pPicture2 = (CStatic*)GetDlgItem(IDC_STATIC6);
	CStatic* pPicture3 = (CStatic*)GetDlgItem(IDC_STATIC7);
	CStatic* pPicture4 = (CStatic*)GetDlgItem(IDC_STATIC8);
	CStatic* pPicture5 = (CStatic*)GetDlgItem(IDC_STATIC9);
	CStatic* pPicture6 = (CStatic*)GetDlgItem(IDC_STATIC10);

	// hide all controls in all tabs
	pEdit1->ShowWindow(SW_HIDE);
	pEdit2->ShowWindow(SW_HIDE);
	pEdit3->ShowWindow(SW_HIDE);
	pStatic1->ShowWindow(SW_HIDE);
	pStatic2->ShowWindow(SW_HIDE);
	pStatic3->ShowWindow(SW_HIDE);
	pPicture1->ShowWindow(SW_HIDE);
	pPicture2->ShowWindow(SW_HIDE);
	pPicture3->ShowWindow(SW_HIDE);
	pPicture4->ShowWindow(SW_HIDE);
	pPicture5->ShowWindow(SW_HIDE);
	pPicture6->ShowWindow(SW_HIDE);

	// show controls for selected tab
	CTabCtrl* pTab = (CTabCtrl*)GetDlgItem(IDC_TAB1);
	switch (pTab->GetCurFocus())
	{

		case 0: // square
		{
			pStatic1->SetWindowText(CString(_T("Side:")));
			pEdit1->SetWindowText(CString(_T("0")));
			pEdit4->SetWindowText(CString(_T("SQUARE\r\nSide=0.00\r\nArea=0.00\r\nPerimeter=0.00")));
			pEdit1->ShowWindow(SW_SHOW);
			pStatic1->ShowWindow(SW_SHOW);
			pPicture1->ShowWindow(SW_SHOW);
			break;
		}

		case 1: // rectangle
		{
			pStatic1->SetWindowText(CString(_T("Length:")));
			pStatic2->SetWindowText(CString(_T("Width:")));
			pEdit1->SetWindowText(CString(_T("0")));
			pEdit2->SetWindowText(CString(_T("0")));
			pEdit4->SetWindowText(CString(_T("RECTANGLE\r\nLength=0.00 Width=0\r\nArea=0.00\r\nPerimeter=0.00")));
			pEdit1->ShowWindow(SW_SHOW);
			pEdit2->ShowWindow(SW_SHOW);
			pStatic1->ShowWindow(SW_SHOW);
			pStatic2->ShowWindow(SW_SHOW);
			pPicture2->ShowWindow(SW_SHOW);
			break;
		}

		case 2: // circle
		{
			pStatic1->SetWindowText(CString(_T("Radius:")));
			pEdit1->SetWindowText(CString(_T("0")));
			pEdit4->SetWindowText(CString(_T("CIRCLE\r\nRadius=0\r\nArea=0.00\r\nPerimeter=0.00")));
			pEdit1->ShowWindow(SW_SHOW);
			pStatic1->ShowWindow(SW_SHOW);
			pPicture3->ShowWindow(SW_SHOW);
			break;
		}

		case 3: // cube
		{
			pStatic1->SetWindowText(CString(_T("Side:")));
			pEdit1->SetWindowText(CString(_T("0")));
			pEdit4->SetWindowText(CString(_T("CUBE\r\nSide=0\r\nSurface Area=0.00\r\nVolume=0.00")));
			pEdit1->ShowWindow(SW_SHOW);
			pStatic1->ShowWindow(SW_SHOW);
			pPicture4->ShowWindow(SW_SHOW);
			break;
		}

		case 4: // prism
		{
			pStatic1->SetWindowText(CString(_T("Length:")));
			pStatic2->SetWindowText(CString(_T("Width:")));
			pStatic3->SetWindowText(CString(_T("Height:")));
			pEdit1->SetWindowText(CString(_T("0")));
			pEdit2->SetWindowText(CString(_T("0")));
			pEdit3->SetWindowText(CString(_T("0")));
			pEdit4->SetWindowText(CString(_T("PRISM\r\nLength=0 Width=0 Height=0\r\nSurface Area=0.00\r\nVolume=0.00")));
			pEdit1->ShowWindow(SW_SHOW);
			pEdit2->ShowWindow(SW_SHOW);
			pEdit3->ShowWindow(SW_SHOW);
			pStatic1->ShowWindow(SW_SHOW);
			pStatic2->ShowWindow(SW_SHOW);
			pStatic3->ShowWindow(SW_SHOW);
			pPicture5->ShowWindow(SW_SHOW);
			break;
		}

		case 5: // cylinder
		{
			pStatic1->SetWindowText(CString(_T("Radius:")));
			pStatic2->SetWindowText(CString(_T("Height:")));
			pEdit1->SetWindowText(CString(_T("0")));
			pEdit2->SetWindowText(CString(_T("0")));
		  pEdit4->SetWindowText(CString(_T("CYLINDER\r\nRadius=0 Height=0 \r\nSurface Area=0.00\r\nVolume=0.00")));
			pEdit1->ShowWindow(SW_SHOW);
			pEdit2->ShowWindow(SW_SHOW);
			pStatic1->ShowWindow(SW_SHOW);
			pStatic2->ShowWindow(SW_SHOW);
			pPicture6->ShowWindow(SW_SHOW);
			break;
	}
}

	*pResult = 0;
}


void CGeometryHomework8Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	const char* token[4];
	CEdit* pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
	CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_EDIT3);
	CEdit* pEdit4 = (CEdit*)GetDlgItem(IDC_EDIT4);

	CString edit1;
	pEdit1->GetWindowText(edit1);
	string sEdit1 = CStringA(edit1);
	token[1] = sEdit1.c_str();

	CString edit2;
	pEdit2->GetWindowText(edit2);
	string sEdit2 = CStringA(edit2);
	token[2] = sEdit2.c_str();

	CString edit3;
	pEdit3->GetWindowText(edit3);
	string sEdit3 = CStringA(edit3);
	token[3] = sEdit3.c_str();

	ostringstream sout;

	CTabCtrl* pTab = (CTabCtrl*)GetDlgItem(IDC_TAB1);
	switch (pTab->GetCurFocus())
	{
		case 0: // square
		{
			Square s(token);
			sout << &s;
			pEdit4->SetWindowText(CString(sout.str().c_str()));
			break;
		}

		case 1: // rect
		{
			comsc::Rectangle rec(token);
			sout << &rec;
			pEdit4->SetWindowText(CString(sout.str().c_str()));
			break;
		}

		case 2: // circle
		{
			Circle cir(token);
			sout << &cir;
			pEdit4->SetWindowText(CString(sout.str().c_str()));
			break;
		}

		case 3: // cube
		{
			Cube cub(token);
			sout << &cub;
			pEdit4->SetWindowText(CString(sout.str().c_str()));
			break;
		}

		case 4: // prism
		{
			Prism pri(token);
			sout << &pri;
			pEdit4->SetWindowText(CString(sout.str().c_str()));
			break;
		}

		case 5: // cylinder
		{
			Cylinder cyl(token);
			sout << &cyl;
			pEdit4->SetWindowText(CString(sout.str().c_str()));
			break;
		}
	}

	// CDialogEx::OnOK();
}


void CGeometryHomework8Dlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGeometryHomework8Dlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGeometryHomework8Dlg::OnStnClickedStatic5()
{
	// TODO: Add your control notification handler code here
}
