#include "wxgis/catalogui/gxtableview.h"
#include "wxgis/carto/featuredataset.h"

wxGxTableView::wxGxTableView(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size) : wxGISTableView(parent, id, pos, size)
{
	m_sViewName = wxString(_("Table View"));
	SetReadOnly(true);
}

wxGxTableView::~wxGxTableView(void)
{
}

bool wxGxTableView::Activate(wxGxApplication* application, IGxCatalog* Catalog, wxXmlNode* pConf)
{
	wxGxView::Activate(application, Catalog, pConf);
	//Serialize(m_pXmlConf, false);

	//m_pConnectionPointCatalog = dynamic_cast<IConnectionPointContainer*>( m_pCatalog );
	//if(m_pConnectionPointCatalog != NULL)
	//	m_ConnectionPointCatalogCookie = m_pConnectionPointCatalog->Advise(this);

	m_pSelection = m_pCatalog->GetSelection();
	return true;
}

void wxGxTableView::Deactivate(void)
{
	//if(m_ConnectionPointSelectionCookie != -1)
	//	m_pConnectionPointSelection->Unadvise(m_ConnectionPointSelectionCookie);
	//if(m_ConnectionPointCatalogCookie != -1)
	//	m_pConnectionPointCatalog->Unadvise(m_ConnectionPointCatalogCookie);

	//Serialize(m_pXmlConf, true);
	wxGxView::Deactivate();
}

bool wxGxTableView::Applies(IGxSelection* Selection)
{
	if(Selection == NULL)
		return false;

	GxObjectArray* pGxObjectArray = Selection->GetSelectedObjects();
	for(size_t i = 0; i < pGxObjectArray->size(); i++)
	{
		IGxDataset* pGxDataset = dynamic_cast<IGxDataset*>( pGxObjectArray->at(i) );
		if(pGxDataset != NULL)
		{			
			wxGISEnumDatasetType type = pGxDataset->GetType();
			switch(type)
			{
			case enumGISTableDataset:
			case enumGISFeatureDataset:
				return true;
			case enumGISRasterDataset:
				break;
			}

		}
	}
	return false;
}

void wxGxTableView::OnSelectionChanged(IGxSelection* Selection, long nInitiator)
{
	if(nInitiator == GetId())
		return;

	GxObjectArray* pGxObjectArray = m_pSelection->GetSelectedObjects();
	if(pGxObjectArray == NULL || pGxObjectArray->size() == 0)
		return;
	IGxObject* pGxObj = pGxObjectArray->at(pGxObjectArray->size() - 1);	
	if(m_pParentGxObject == pGxObj)
		return;

	IGxDataset* pGxDataset =  dynamic_cast<IGxDataset*>(pGxObj);
	if(pGxDataset == NULL)
		return;

	wxGISDataset* pwxGISDataset = pGxDataset->GetDataset();
	if(pwxGISDataset == NULL)
		return;

	//wxGISEnumDatasetType type = pwxGISDataset->GetType();
	//OGRLayer* pOGRLayer(NULL);

	//switch(type)
	//{
	//case enumGISTableDataset:
	//case enumGISFeatureDataset:
	//	{
	//	wxGISFeatureDataset* pwxGISFeatureDataset = dynamic_cast<wxGISFeatureDataset*>(pwxGISDataset);
	//	if(pwxGISFeatureDataset)
	//		pOGRLayer = pwxGISFeatureDataset->GetLayer();
	//	}
	//	break;
	//default:
	//case enumGISRasterDataset:
	//	break;
	//}

	////the pOGRLayer will live while IGxObject live. IGxObject( from IGxSelection ) store IwxGISDataset, and destroy it then catalog destroyed 
	//pwxGISDataset->Release();

	//if(pOGRLayer == NULL)
	//	return;

	wxGISTable* pTable = new wxGISTable(pwxGISDataset);
	wxGISTableView::SetTable(pTable, true);
	////reset 
	//ResetContents();

	//IGxObjectContainer* pObjContainer =  dynamic_cast<IGxObjectContainer*>(pGxObj);
	//if(pObjContainer == NULL || !pObjContainer->HasChildren())
	//	return;
	//GxObjectArray* pArr = pObjContainer->GetChildren();
	//for(size_t i = 0; i < pArr->size(); i++)
	//{
	//	AddObject(pArr->at(i));
	//}

	//SortItems(MyCompareFunction, m_bSortAsc);
 //   SetColumnImage(m_currentSortCol, m_bSortAsc ? 0 : 1);

	m_pParentGxObject = pGxObj;
	wxWindow::Refresh();
}