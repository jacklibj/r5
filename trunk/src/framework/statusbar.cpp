/******************************************************************************
 * Project:  wxGIS (GIS Catalog)
 * Purpose:  wxGISStatusBar class.
 * Author:   Bishop (aka Barishnikov Dmitriy), polimax@mail.ru
 ******************************************************************************
*   Copyright (C) 2009  Bishop
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/
#include "wxgis/framework/statusbar.h"
#include "../../art/globe_imglst14.xpm"

BEGIN_EVENT_TABLE(wxGISStatusBar, wxStatusBar)
	EVT_SIZE(wxGISStatusBar::OnSize)
	EVT_TIMER( TIMER_ID, wxGISStatusBar::OnTimer )
	EVT_RIGHT_DOWN(wxGISStatusBar::OnRightDown)
END_EVENT_TABLE()

wxGISStatusBar::wxGISStatusBar(wxWindow *parent, wxWindowID id, long style, const wxString& name, WXDWORD panesstyle) : wxStatusBar(parent, id, style, name), IStatusBar(panesstyle), m_timer(this, TIMER_ID), m_pAni(NULL)
{
	m_pApp = dynamic_cast<IApplication*>(parent);

	struct _statuspane
	{
		int size;
		long style;
	};

	std::vector<_statuspane> panes;
	int counter(0);
	if(panesstyle & enumGISStatusMain)
	{
		_statuspane data = {-1, wxSB_FLAT};
		panes.push_back(data);
		m_MsgPos = counter;
		counter++;
	}
	if(panesstyle & enumGISStatusProgress)
	{
		_statuspane data = {100, wxSB_FLAT};
		panes.push_back(data);
		_statuspane data1 = {-1, wxSB_FLAT};
		panes.push_back(data1);
		m_ProgressPos = counter;
		counter++;
	}
	if(panesstyle & enumGISStatusAnimation)
	{
		_statuspane data = {23, wxSB_NORMAL};
		panes.push_back(data);
		//bitmap
		m_pAni = new wxGISAnimation(this, wxID_ANY, wxBitmap(globe_imglst14_xpm),14);
		m_pAni->Hide();
		m_AniPos = counter;
		counter++;
	}
	if(panesstyle & enumGISStatusPosition)
	{
		_statuspane data = {200, wxSB_NORMAL};
		panes.push_back(data);
		counter++;
	}
	if(panesstyle & enumGISStatusPagePosition)
	{
		_statuspane data = {100, wxSB_NORMAL};
		panes.push_back(data);
		counter++;
	}
	if(panesstyle & enumGISStatusSize)
	{
		_statuspane data = {80, wxSB_NORMAL};
		panes.push_back(data);
		counter++;
	}
	if(panesstyle & enumGISStatusCapsLock)
	{
		_statuspane data = {40, wxSB_NORMAL};
		panes.push_back(data);
		counter++;
	}
	if(panesstyle & enumGISStatusNumLock)
	{
		_statuspane data = {40, wxSB_NORMAL};
		panes.push_back(data);
		counter++;
	}
	if(panesstyle & enumGISStatusScrollLock)
	{
		_statuspane data = {40, wxSB_NORMAL};
		panes.push_back(data);
		counter++;
	}
	if(panesstyle & enumGISStatusClock)
	{
		_statuspane data = {38, wxSB_NORMAL};
		panes.push_back(data);
		m_ClockPos = counter;
		counter++;
	}
	_statuspane data = {1, wxSB_FLAT};
	panes.push_back(data);
	_statuspane data1 = {15, wxSB_FLAT};
	panes.push_back(data1);

	int *STATUSBAR_Sizes = new int[panes.size()];
	int *STATUSBAR_Styles = new int[panes.size()];
	for(size_t i = 0; i < panes.size(); i++)
	{
		STATUSBAR_Sizes[i] = panes[i].size;
		STATUSBAR_Styles[i] = panes[i].style;
	}
	SetFieldsCount(panes.size(), STATUSBAR_Sizes);
	SetStatusStyles(panes.size(), STATUSBAR_Styles);

	delete [] STATUSBAR_Sizes;
	delete [] STATUSBAR_Styles;

	//m_pProgressBar	= new wxGauge(this, ID_WND_PROGRESSBAR, 100);
	//set text & start timer
	if(panesstyle & enumGISStatusClock)
	{	
		SetMessage(wxDateTime::Now().Format(_("%H:%M")), m_ClockPos);	
		m_timer.Start(30000);    // 1 minute interval
	}
}

wxGISStatusBar::~wxGISStatusBar(void)
{
	wxDELETE(m_pAni);
}


void wxGISStatusBar::OnSize(wxSizeEvent &event)
{
	wxRect	r;
	if( m_pAni && GetFieldRect(m_AniPos, r) )
	{
		r.Deflate(2);
		m_pAni->SetSize(r);
	}

	//if( m_pProgressBar && GetFieldRect(STATUSBAR_PROGRESS, r) )
	//{
	//	m_pProgressBar->SetSize(r);
	//}
	event.Skip();
}

void wxGISStatusBar::SetMessage(const wxString& text, int i)
{
	SetStatusText(text, i);
}

wxString wxGISStatusBar::GetMessage(int i)
{
	return GetStatusText(i);
}

void wxGISStatusBar::OnTimer( wxTimerEvent& event )
{
	SetMessage(wxDateTime::Now().Format(_("%H:%M")), m_ClockPos);	
}


void wxGISStatusBar::OnRightDown(wxMouseEvent& event)
{
	m_pApp->ShowToolBarMenu();
	event.Skip();
}