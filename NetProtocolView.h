// NetProtocolView.h : CNetProtocolView クラスのインターフェイス
//

#pragma once

#include "afxwin.h"

#define  DISPLAY_MARGIN  5

class  CNetProtocolDoc;
class  CNetProtocolApp;

class CNetProtocolView : public CScrollView
{
protected: // シリアル化からのみ作成します。
    .gCNetProtocolView();
    .gDECLARE_DYNCREATE(CNetProtocolView)

public:
    .gCNetProtocolDoc* GetDocument() const;
    .gCNetProtocolApp* pApp;

// オーバーライド
public:
    .gvirtual  BOOL    PreCreateWindow(CREATESTRUCT& cs);

protected:
    .gvirtual  void    OnInitialUpdate(); // 構築後に初めて呼び出されます。
    .gvirtual  BOOL    OnPreparePrinting(CPrintInfo* pInfo);
    .gvirtual  void    OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
    .gvirtual  void    OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

public:
    .gvirtual ~CNetProtocolView();

#ifdef _DEBUG
    .gvirtual  void    AssertValid() const;
    .gvirtual  void    Dump(CDumpContext& dc) const;
#endif


// 生成された、メッセージ割り当て関数
protected:
    .gint       m_msx;
    .gint       m_msy;
    .gint       m_mex;
    .gint       m_mey;

    .gint       m_mpress;
    .gint       m_dragsx;
    .gint       m_dragsy;
    .gint       m_dragex;
    .gint       m_dragey;

    .gafx_msg  int    OnCreate(LPCREATESTRUCT lpcs);
    .gafx_msg  void   OnDestroy(void);
    .gafx_msg  void   OnDraw(CDC* pDC);
    .gDECLARE_MESSAGE_MAP()

public:
    .gCFont     m_ScreenFont;
    .gint       m_FontSizeX;
    .gint       m_FontSizeY;

    .gint       m_ScrollSizeX;
    .gint       m_ScrollSizeY;
    .gint       m_DocLastPos;

    .gint       m_copysy;
    .gint       m_copyey;

    .gvoid      resetScrollSize(void);
    .gvoid      setScrollPosition(CDC* pDC, CBufferRing* pBR);
    .gvoid      clearViewDoc(void);
    .gCString   getCopyData(void);
    .gBOOL      OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll);

    .gafx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    .gafx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    .gafx_msg void OnMouseMove(UINT nFlags, CPoint point);
};


#ifndef _DEBUG  // NetProtocolView.cpp のデバッグ バージョン
inline CNetProtocolDoc* CNetProtocolView::GetDocument() const
   { return reinterpret_cast<CNetProtocolDoc*>(m_pDocument); }
#endif

