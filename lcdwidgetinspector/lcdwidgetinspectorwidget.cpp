#include "lcdwidgetinspectorwidget.h"
#include "ui_lcdwidgetinspectorwidget.h"

#include <gammaray/common/objectbroker.h>

LCDWidgetInspectorWidget::LCDWidgetInspectorWidget(QWidget* parent) : QWidget(parent), ui(new Ui::LCDWidgetInspectorWidget)
{
  ui->setupUi(this);
  QAbstractItemModel* model = GammaRay::ObjectBroker::model("com.kdab.GammaRay.LCDWidgetModel");
  ui->widgetList->setModel(model);
  ui->widgetList->setSelectionModel(GammaRay::ObjectBroker::selectionModel(model));
  ui->propertyWidget->setObjectBaseName("com.kdab.GammaRay.LCDWidgetInspector");
}

LCDWidgetInspectorWidget::~LCDWidgetInspectorWidget()
{
}
