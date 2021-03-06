//
// Copyright (C) 2013, Alojz Kovacik, http://kovacik.github.com
//
// This file is part of Geometry Debugger.
//
// Geometry Debugger is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Geometry Debugger is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Geometry Debugger. If not, see <http://www.gnu.org/licenses/>.
//


#pragma once

#include "SceneObject.h"

class SceneObjectMesh : public ImplementSmartObject
    <
        SceneObjectMesh, 
        ClassFlags<CF_ALIGNED_MEMORY>,
        InheritImplementation<SceneObject>, 
        ISceneObjectMesh
    >
{

    HashTable<MeshStreamType, SmartPtr<IMeshStream>> m_Streams;
	PrimitiveTopologyType m_PrimitiveTopologyType;

public:
    SceneObjectMesh(void);
    ~SceneObjectMesh(void);

	HRESULT Initialize(__in_z const wchar_t *nodeName);

    HRESULT GetMeshStream(__in MeshStreamType streamType, __deref_out_opt IMeshStream **ppStream);
    HRESULT SetMeshStream(__in MeshStreamType streamType, __in IMeshStream *pStream);
    HRESULT RemoveMeshStream(__in MeshStreamType streamType);
	PrimitiveTopologyType GetPrimitiveTopologyType();
	void SetPrimitiveTopologyType(PrimitiveTopologyType topologyType);
};

