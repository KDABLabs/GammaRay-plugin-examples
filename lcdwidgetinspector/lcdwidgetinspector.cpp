#include "lcdwidgetinspector.h"

#include <gammaray/core/probeinterface.h>
#include <gammaray/core/objecttypefilterproxymodel.h>

LCDWidgetInspector::LCDWidgetInspector(GammaRay::ProbeInterface* probe, QObject* parent) : QObject(parent)
{
  QAbstractProxyModel *model = new GammaRay::ObjectTypeFilterProxyModel<QLCDNumber>(this);
  model->setSourceModel(probe->objectListModel());
  probe->registerModel("com.kdab.GammaRay.LCDWidgetModel", model);
}
