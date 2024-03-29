/******************************************************************************
 * Project:  wxGIS (GIS Catalog)
 * Purpose:  wxGISMenuBar class.
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
#pragma once
#include "wxgis/framework/framework.h"
#include "wxgis/framework/commandbar.h"

class WXDLLIMPEXP_GIS_FRW wxGISMenuBar :
	public wxMenuBar
{
public:
	wxGISMenuBar(long style = 0, IApplication* pApp = NULL, wxXmlNode* pConf = NULL);
	virtual ~wxGISMenuBar(void);
	virtual bool IsMenuBarMenu(wxString sMenuName);
	virtual COMMANDBARARRAY* GetMenuBarArray(void);
	virtual void MoveLeft(int pos);
	virtual void MoveRight(int pos);
	virtual void RemoveMenu(IGISCommandBar* pBar);
	virtual bool AddMenu(IGISCommandBar* pBar);
	virtual void Serialize(wxXmlNode* pConf);

protected:
	COMMANDBARARRAY m_MenubarArray;
};
