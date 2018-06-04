#include "lcdwidgetinspector.h"

#include <gammaray/common/objectbroker.h>
#include <gammaray/common/objectmodel.h>
#include <gammaray/core/probe.h>
#include <gammaray/core/objecttypefilterproxymodel.h>
#include <gammaray/core/propertycontroller.h>

#include <QItemSelectionModel>

LCDWidgetInspector::LCDWidgetInspector(GammaRay::Probe* probe, QObject* parent) :
  QObject(parent),
  m_propertyController(new GammaRay::PropertyController("com.kdab.GammaRay.LCDWidgetInspector", this))
{
  QAbstractProxyModel *model = new GammaRay::ObjectTypeFilterProxyModel<QLCDNumber>(this);
  model->setSourceModel(probe->objectListModel());
  probe->registerModel("com.kdab.GammaRay.LCDWidgetModel", model);

  m_selectionModel = GammaRay::ObjectBroker::selectionModel(model);
  connect(m_selectionModel, SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
          SLOT(selectionChanged(QItemSelection)));
}

void LCDWidgetInspector::selectionChanged(const QItemSelection& selection)
{
  if (selection.isEmpty()) {
    m_propertyController->setObject(0);
  } else {
    const QModelIndex index = selection.first().topLeft();
    m_propertyController->setObject(index.data(GammaRay::ObjectModel::ObjectRole).value<QObject*>());
  }
}
