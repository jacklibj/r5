///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __wxGISCustomizeDlg__
#define __wxGISCustomizeDlg__

#include <wx/intl.h>

#include <wx/gdicmn.h>
#include <wx/aui/auibook.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/splitter.h>
#include <wx/checklst.h>
#include <wx/listctrl.h>
#include <wx/panel.h>
#include <wx/listbox.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class wxGISCustomizeDlg
///////////////////////////////////////////////////////////////////////////////
class wxGISCustomizeDlg : public wxDialog 
{
	private:
	
	protected:
		wxAuiNotebook* m_auinotebook;
		wxStdDialogButtonSizer* m_sdbSizer;
		wxButton* m_sdbSizerOK;
		wxButton* m_sdbSizerCancel;
	
	public:
		
		wxGISCustomizeDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Castomize"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 300,400 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~wxGISCustomizeDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class wxGISToolBarPanel
///////////////////////////////////////////////////////////////////////////////
class wxGISToolBarPanel : public wxPanel 
{
	private:
	
	protected:
		wxSplitterWindow* m_splitter1;
		wxCheckListBox* m_toolbarlist;
		wxListCtrl* m_buttonslist;
		wxButton* m_createbutton;
		wxButton* m_deletebutton;
		wxButton* m_addbutton;
		wxButton* m_rembutton;
	
	public:
		
		wxGISToolBarPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL );
		~wxGISToolBarPanel();
		
		void m_splitter1OnIdle( wxIdleEvent& )
		{
			m_splitter1->SetSashPosition( 0 );
			m_splitter1->Disconnect( wxEVT_IDLE, wxIdleEventHandler( wxGISToolBarPanel::m_splitter1OnIdle ), NULL, this );
		}
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class wxGISCommandPanel
///////////////////////////////////////////////////////////////////////////////
class wxGISCommandPanel : public wxPanel 
{
	private:
	
	protected:
		wxSplitterWindow* m_splitter2;
		wxListBox* m_listBox1;
		wxListCtrl* m_listCtrl3;
	
	public:
		
		wxGISCommandPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL );
		~wxGISCommandPanel();
		
		void m_splitter2OnIdle( wxIdleEvent& )
		{
			m_splitter2->SetSashPosition( 0 );
			m_splitter2->Disconnect( wxEVT_IDLE, wxIdleEventHandler( wxGISCommandPanel::m_splitter2OnIdle ), NULL, this );
		}
	
};

#endif //__wxGISCustomizeDlg__
