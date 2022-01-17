// IconImageList.cpp: implementation of the CIconImageList class.
//
// created by Unwinder
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
//////////////////////////////////////////////////////////////////////
#include "IconImageList.h"
//////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CIconImageList::CIconImageList()
{
	m_hModule = NULL;
}
//////////////////////////////////////////////////////////////////////
CIconImageList::~CIconImageList()
{
}
//////////////////////////////////////////////////////////////////////
BOOL CIconImageList::Create()
{
	DeleteImageList();

	return CImageList::Create(16, 16, ILC_COLOR32 | ILC_MASK, 1, 1);
}
//////////////////////////////////////////////////////////////////////
int CIconImageList::Add(UINT nID)
{
	HICON hIcon = (HICON)LoadImage(m_hModule ?  m_hModule : AfxGetResourceHandle(), MAKEINTRESOURCE(nID), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);

	if (hIcon)
	{
		int iResult = CImageList::Add(hIcon);

		DestroyIcon(hIcon);

		return iResult;
	}
	else 
		return -1;
}
//////////////////////////////////////////////////////////////////////
void CIconImageList::SetResourceHandle(HINSTANCE hModule)
{
	m_hModule = hModule;
}
//////////////////////////////////////////////////////////////////////