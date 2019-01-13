
// GeometryHomework8Dlg.h : header file
//

#pragma once


// CGeometryHomework8Dlg dialog
class CGeometryHomework8Dlg : public CDialogEx
{
// Construction
public:
	CGeometryHomework8Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GEOMETRYHOMEWORK8_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnStnClickedStatic5();
};
