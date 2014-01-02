#include <QApplication>
#include <QLCDNumber>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QLCDNumber lcd;
    lcd.show();
    return app.exec();
}
