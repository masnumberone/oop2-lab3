#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updatePrice(int);
    void calculate();

private:
    Ui::MainWindow *ui;
    int price;                              // цена выбранной ткани
    double length;                             // длина ткани
    double width;                              // ширина ткани
    double area;                               // площадь ткани
    double total;                              // итого к оплате

    void setLength(const QString&);         // установить значение length
    void setWidth(const QString&);          // установить значение width
    void calculateArea();                   // вычислить значение area
    void calculateTotal();                  // вычислить значение total



};
#endif // MAINWINDOW_H
