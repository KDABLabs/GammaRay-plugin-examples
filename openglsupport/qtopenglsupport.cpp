#include "qtopenglsupport.h"

#include <gammaray/core/metaobject.h>
#include <gammaray/core/metaobjectrepository.h>
#include <gammaray/core/util.h>
#include <gammaray/core/varianthandler.h>

#include <QOpenGLContext>
#include <QSurfaceFormat>

Q_DECLARE_METATYPE(QSurfaceFormat)
Q_DECLARE_METATYPE(QGLContext*)
Q_DECLARE_METATYPE(const QGLContext*)

static QString qtGLContextToString(QGLContext* context)
{
  return GammaRay::VariantHandler::displayString(QVariant::fromValue(context->contextHandle()->format()));
}

QtOpenGLSupport::QtOpenGLSupport(GammaRay::ProbeInterface* probe, QObject* parent) :
  QObject(parent)
{
  Q_UNUSED(probe);

  GammaRay::MetaObject *mo = 0;
  MO_ADD_METAOBJECT1(QGLWidget, QWidget);
  MO_ADD_PROPERTY_RO(QGLWidget, context);
  MO_ADD_PROPERTY_RO(QGLWidget, isSharing);
  MO_ADD_PROPERTY_RO(QGLWidget, isValid);
  MO_ADD_PROPERTY_RO(QGLWidget, overlayContext);

  GammaRay::VariantHandler::registerStringConverter<QGLContext*>(qtGLContextToString);
  GammaRay::VariantHandler::registerStringConverter<const QGLContext*>(GammaRay::Util::addressToString);
}
