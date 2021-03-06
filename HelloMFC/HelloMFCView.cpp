
// HelloMFCView.cpp : implementation of the CHelloMFCView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "HelloMFC.h"
#endif

#include "HelloMFCDoc.h"
#include "HelloMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHelloMFCView

IMPLEMENT_DYNCREATE(CHelloMFCView, CView)

BEGIN_MESSAGE_MAP(CHelloMFCView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHelloMFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CHelloMFCView construction/destruction

CHelloMFCView::CHelloMFCView() noexcept
{
	// TODO: add construction code here

}

CHelloMFCView::~CHelloMFCView()
{
}

BOOL CHelloMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CHelloMFCView drawing

void CHelloMFCView::OnDraw(CDC* /*pDC*/)
{
	CHelloMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CHelloMFCView printing


void CHelloMFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CHelloMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHelloMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHelloMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CHelloMFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CHelloMFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CHelloMFCView diagnostics

#ifdef _DEBUG
void CHelloMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CHelloMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHelloMFCDoc* CHelloMFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHelloMFCDoc)));
	return (CHelloMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CHelloMFCView message handlers
