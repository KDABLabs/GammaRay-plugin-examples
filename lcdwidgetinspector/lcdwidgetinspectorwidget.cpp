#include "lcdwidgetinspectorwidget.h"
#include "ui_lcdwidgetinspectorwidget.h"

#include <gammaray/common/objectbroker.h>
#include <gammaray/ui/propertywidget.h> 

LCDWidgetInspectorWidget::LCDWidgetInspectorWidget(QWidget* parent) : QWidget(parent), ui(new Ui::LCDWidgetInspectorWidget)
{
  ui->setupUi(this);
  ui->widgetList->setModel(GammaRay::ObjectBroker::model("com.kdab.GammaRay.LCDWidgetModel"));
}

LCDWidgetInspectorWidget::~LCDWidgetInspectorWidget()
{
}
