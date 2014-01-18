#include "qtopenglsupport.h"

#include <gammaray/core/metaobject.h>
#include <gammaray/core/metaobjectrepository.h>

Q_DECLARE_METATYPE(QGLContext*)
Q_DECLARE_METATYPE(const QGLContext*)

QtOpenGLSupport::QtOpenGLSupport(GammaRay::ProbeInterface* probe, QObject* parent) :
  QObject(parent)
{
  Q_UNUSED(probe);

  GammaRay::MetaObject *mo = 0;
  MO_ADD_METAOBJECT1(QGLWidget, QWidget);
  MO_ADD_PROPERTY_RO(QGLWidget, QGLContext*, context);
  MO_ADD_PROPERTY_RO(QGLWidget, bool, isSharing);
  MO_ADD_PROPERTY_RO(QGLWidget, bool, isValid);
  MO_ADD_PROPERTY_RO(QGLWidget, const QGLContext*, overlayContext);
}
