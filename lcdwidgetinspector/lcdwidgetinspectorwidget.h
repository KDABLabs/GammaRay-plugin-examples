#ifndef LCDWIDGETINSPECTORWIDGET_H
#define LCDWIDGETINSPECTORWIDGET_H

#include <gammaray/ui/tooluifactory.h>
#include <QWidget>

namespace Ui { class LCDWidgetInspectorWidget; }

class LCDWidgetInspectorWidget : public QWidget
{
  Q_OBJECT
public:
  explicit LCDWidgetInspectorWidget(QWidget* parent);
  ~LCDWidgetInspectorWidget();
private:
  QScopedPointer<Ui::LCDWidgetInspectorWidget> ui;
};

class LCDWidgetInspectorWidgetFactory : public QObject, public GammaRay::StandardToolUiFactory<LCDWidgetInspectorWidget>
{
  Q_OBJECT
  Q_INTERFACES(GammaRay::ToolUiFactory)
  Q_PLUGIN_METADATA(IID "com.kdab.GammaRay.ToolUiFactory" FILE "lcdwidgetinspector.json")
};

#endif
