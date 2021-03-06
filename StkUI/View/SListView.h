// SListView.h : interface of the CSListView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SLISTVIEW_H__579B4821_52B1_4009_BB3B_590A4D06C998__INCLUDED_)
#define AFX_SLISTVIEW_H__579B4821_52B1_4009_BB3B_590A4D06C998__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class	CStaticDoc;
class	CListExportDlg;
/***
	股票列表视图
*/
class CSListView : public CFormView
{
protected: // create from serialization only
	CSListView();
	DECLARE_DYNCREATE(CSListView)

public:
	//{{AFX_DATA(CSListView)
	enum { IDD = IDD_SLIST_FORM };
	//}}AFX_DATA

	CGuiWorkTab	m_wndWorkTab;

// Attributes
public:
	inline virtual CStaticDoc* GetDocument()   { return (CStaticDoc *)m_pDocument; }
	void			SetFont( LPLOGFONT pLogFont );

// Operations
public:
	void			GetSelectedStocks( CSPStringArray & astr );
	void			ExportList( CListExportDlg * pDlg );
	
	void			RemoveSortSign( );
	void			SetSortSign( );
	void			SetSortVariant( UINT nVariant );
	virtual	void	SetCurrentStatus( int nType, LPCTSTR lpszDomain, DWORD dwDate );
	void			StoreColumnOrderArray( );
	
	virtual	void	ResetColumns( );
	BOOL			SetAverageItem( CGridCtrl &grid, CStockContainer &container, BOOL bRedraw );
	void			OnDblclkItem( int nStockIndex );

	// 行情刷新
	void			StockInfoChanged( LONG id, CStockInfo & info );
	void			SendRequestQuote( BOOL bForced );

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSListView)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	// Grid
	CGridCtrl	m_Grid;

	// attributes
	int		m_nColSort;
	BOOL	m_bSortAscend;

	BOOL	m_bShouldUpdate;
	BOOL	m_bFirstUpdate;

	// operation

// Generated message map functions
protected:
	//{{AFX_MSG(CSListView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSlistExportlist();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnFilePrint();
	afx_msg void OnUpdateFilePrint(CCmdUI* pCmdUI);
	afx_msg void OnSelchangeWorktab(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	afx_msg LRESULT OnGetViewTitle( WPARAM wParam, LPARAM lParam );
	afx_msg LRESULT OnGetViewCmdid( WPARAM wParam, LPARAM lParam );
	afx_msg LRESULT OnColorChange( WPARAM wParam, LPARAM lParam );
	afx_msg LRESULT OnStkReceiverData( WPARAM wParam, LPARAM lParam );
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLISTVIEW_H__579B4821_52B1_4009_BB3B_590A4D06C998__INCLUDED_)
