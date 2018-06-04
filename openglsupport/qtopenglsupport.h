
#ifndef QTOPENGLSUPPORT_H
#define QTOPENGLSUPPORT_H

#include <gammaray/core/toolfactory.h>

#include <QGLWidget>

class QtOpenGLSupport : public QObject
{
  Q_OBJECT
public:
  explicit QtOpenGLSupport(GammaRay::Probe *probe, QObject *parent = 0);
};

class QtOpenGLSupportFactory : public QObject, public GammaRay::StandardToolFactory<QGLWidget, QtOpenGLSupport>
{
  Q_OBJECT
  Q_INTERFACES(GammaRay::ToolFactory)
  Q_PLUGIN_METADATA(IID "com.kdab.GammaRay.ToolFactory" FILE "qtopenglsupport.json")

public:
  explicit QtOpenGLSupportFactory(QObject *parent = 0) : QObject(parent)
  {
  }
};

#endif
