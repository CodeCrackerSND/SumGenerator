// SumGenerator.h : main header file for the SUMGENERATOR application
//

#if !defined(AFX_SUMGENERATOR_H__F6EB47EC_ACA7_4455_8910_6C580586EEB2__INCLUDED_)
#define AFX_SUMGENERATOR_H__F6EB47EC_ACA7_4455_8910_6C580586EEB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSumGeneratorApp:
// See SumGenerator.cpp for the implementation of this class
//

class CSumGeneratorApp : public CWinApp
{
public:
	CSumGeneratorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSumGeneratorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSumGeneratorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUMGENERATOR_H__F6EB47EC_ACA7_4455_8910_6C580586EEB2__INCLUDED_)
