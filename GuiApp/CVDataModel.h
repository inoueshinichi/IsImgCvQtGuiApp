#pragma once

#include "CVDefs.h"

/////////////////////////
// 抽象インターフェースクラス
/////////////////////////
class ICVDataModel
{
public:
    virtual ~ICVDataModel() {}
    virtual void AddNode(class CVObject* node) = 0;
    virtual void RemoveNode(class CVObject* node) = 0;
    virtual void UpdateNode(int nodeId, int compId) = 0;
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