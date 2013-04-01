/******************************************************************************
 * Project:  wxGIS (GIS Catalog)
 * Purpose:  wxGISMap class.
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
#include "wxgis/carto/map.h"

wxGISMap::wxGISMap(void)
{
	m_sMapName = wxString(_("new map"));
}

wxGISMap::~wxGISMap(void)
{
	//std::for_each(m_Layers.begin(), m_Layers.end(), wxDELETE);
	ClearLayers();
}

//The AddLayer method adds a layer to the Map. Use the LayerCount property to get the total number of layers in the map.
//AddLayer automatically attempts to set the Map's SpatialReference property if a coordinate system has not yet been defined for the map.  
//When the SpatialReference property is set, the Map's MapUnits and DistanceUnits properties are additionally set.  
//AddLayer also sets the spatial reference of the layer (ILayer::SpatialReference ). 
//If no layers have a spatial reference, AddLayer checks the extent of the first layer (ILayer::AreaOfInterest) and if it has coordinates 
//that look like geographic coordinates (XMin >= -180 and XMax <= 180 and YMin >= -90 and YMax <= 90), ArcMap assumes the data is in decimal 
//degrees and sets the MapUnits to esriDecimalDegrees and DistanceUnits to esriMiles. 
//If no spatial reference is found and the coordinates do not look like geographic coordinates, ArcMap sets no spatial reference and sets the 
//MapUnits to esriMeters and the DistanceUnits to esriMeters. 
//The full extent is recalculated each time a layer added.

void wxGISMap::AddLayer(wxGISLayer* pLayer)
{
	if(!pLayer)
		return;
	m_Layers.push_back(pLayer);
}

void wxGISMap::ClearLayers(void)
{
	for(size_t i = 0; i < m_Layers.size(); i++)
		delete m_Layers[i];
	m_Layers.clear();
}

OGREnvelope wxGISMap::GetFullExtent(void)
{
	OGREnvelope res;
	for(size_t i = 0; i < m_Layers.size(); i++)
		//check if the spatial ref is same!!!
		res.Merge(*m_Layers[i]->GetEnvelope());
	return res;
}
