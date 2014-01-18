#include <QApplication>
#include <QGLWidget>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QGLWidget w;
    w.show();
    return app.exec();
}
