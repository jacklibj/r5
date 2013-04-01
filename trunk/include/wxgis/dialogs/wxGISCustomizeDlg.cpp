///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxGISCustomizeDlg.h"

///////////////////////////////////////////////////////////////////////////

wxGISCustomizeDlg::wxGISCustomizeDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 300,400 ), wxDefaultSize );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	m_auinotebook = new wxAuiNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_DEFAULT_STYLE|wxSIMPLE_BORDER );
	
	bSizerMain->Add( m_auinotebook, 1, wxEXPAND | wxALL, 5 );
	
	m_sdbSizer = new wxStdDialogButtonSizer();
	m_sdbSizerOK = new wxButton( this, wxID_OK );
	m_sdbSizer->AddButton( m_sdbSizerOK );
	m_sdbSizerCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer->AddButton( m_sdbSizerCancel );
	m_sdbSizer->Realize();
	bSizerMain->Add( m_sdbSizer, 0, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizerMain );
	this->Layout();
}

wxGISCustomizeDlg::~wxGISCustomizeDlg()
{
}

wxGISToolBarPanel::wxGISToolBarPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer;
	bSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_splitter1 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter1->Connect( wxEVT_IDLE, wxIdleEventHandler( wxGISToolBarPanel::m_splitter1OnIdle ), NULL, this );
	
	bSizer->Add( m_splitter1, 1, wxEXPAND, 5 );
	
	wxArrayString m_toolbarlistChoices;
	m_toolbarlist = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_toolbarlistChoices, 0 );
	bSizer->Add( m_toolbarlist, 0, wxALL, 5 );
	
	m_buttonslist = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_NO_HEADER|wxLC_REPORT|wxLC_SINGLE_SEL );
	bSizer->Add( m_buttonslist, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_createbutton = new wxButton( this, wxID_ANY, _("Create toolbar/menu"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_createbutton, 0, wxALL|wxEXPAND, 5 );
	
	m_deletebutton = new wxButton( this, wxID_ANY, _("Delete toolbar/menu"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_deletebutton, 0, wxALL|wxEXPAND, 5 );
	
	m_addbutton = new wxButton( this, wxID_ANY, _("Add button"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_addbutton, 0, wxALL|wxEXPAND, 5 );
	
	m_rembutton = new wxButton( this, wxID_ANY, _("Remove button"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_rembutton, 0, wxALL|wxEXPAND, 5 );
	
	bSizer->Add( bSizer3, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer );
	this->Layout();
}

wxGISToolBarPanel::~wxGISToolBarPanel()
{
}

wxGISCommandPanel::wxGISCommandPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_splitter2 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter2->Connect( wxEVT_IDLE, wxIdleEventHandler( wxGISCommandPanel::m_splitter2OnIdle ), NULL, this );
	
	bSizer5->Add( m_splitter2, 1, wxEXPAND, 5 );
	
	m_listBox1 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer5->Add( m_listBox1, 0, wxALL, 5 );
	
	m_listCtrl3 = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_EDIT_LABELS|wxLC_NO_HEADER|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_SORT_ASCENDING );
	bSizer5->Add( m_listCtrl3, 0, wxALL, 5 );
	
	this->SetSizer( bSizer5 );
	this->Layout();
}

wxGISCommandPanel::~wxGISCommandPanel()
{
}
