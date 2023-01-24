#include "CVDataModelFactory.h"

// インターフェースと隔離したい実測クラス
#include "CVDataListModel.h"

ICVDataModel *CVDataModelFactory::CreateDataModel(CVEngine *engine, const std::string &name)
{
    if (name == "List Model")
    {
        return new CVDataListModel(engine);
    }
    else
    {
        return nullptr;
    }
}

void CVDataModelFactory::DeleteDataModel(ICVDataModel *dataModel)
{
    if (dataModel)
    {
        delete dataModel;
        dataModel = nullptr;
    }
}