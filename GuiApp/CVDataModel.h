#pragma once

#include "CVCommon.h"

/////////////////////////
// 抽象インターフェースクラス
/////////////////////////
class ICVDataModel
{
public:
    enum StructureType
    {
        EListModel,
        ETreeModel,
        ETableModel,
        EGraphModel,
    };

    virtual ~ICVDataModel() {}
    virtual void AddNode(class CVNode *node) = 0;
    virtual void RemoveNode(class CVNode *node) = 0;
    virtual void UpdateNodes(float deltaTime) = 0;
    virtual std::string GetClassName() const = 0;
    virtual StructureType GetModelType() const = 0;
};

// List構造インターフェース
class ICVDataListModel : public ICVDataModel
{
public:
    virtual ~ICVDataListModel() {}
};

// Table構造インターフェース
class ICVDataTableModel : public ICVDataModel
{
public:
    virtual ~ICVDataTableModel() {}
};

// Tree構造インターフェース
class ICVDataTreeModel : public ICVDataModel
{
public:
    virtual ~ICVDataTreeModel() {}
};

// Graph構造インターフェース
class ICVDataGraphModel : public ICVDataModel
{
public:
    virtual ~ICVDataGraphModel() {}
};