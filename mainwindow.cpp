#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // расставляем связи
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updatePrice(int)));
    connect(ui->buttonCalculate, SIGNAL(clicked()), this, SLOT(calculate()));

//    QDoubleValidator abc;
//    abc.setBottom(std::numeric_limits<double>::min());
//    ui->inputLength->setValidator(&abc);
//    ui->inputWidth->setValidator( new QDoubleValidator(0));

    // инициализируем price
    updatePrice(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatePrice(int index){
    switch (index) {
    case 0: {
        ui->outputPrice->setText("700 ₽");
        price = 700;
        break;
    }
    case 1: {
        ui->outputPrice->setText("13 850 ₽");
        price = 13850;
        break;
    }
    case 2: {
        ui->outputPrice->setText("2 700 ₽");
        price = 2700;
        break;
    }
    case 3: {
        ui->outputPrice->setText("115 ₽");
        price = 115;
        break;
    }
    }
}

void MainWindow::setLength(const QString &str){
   length = str.toDouble();
   // length = ui->inputLength->text().toDouble();
}

void MainWindow::setWidth(const QString &str){
    width = str.toDouble();
}

void MainWindow::calculateArea(){
    area = length * width;
}

void MainWindow::calculateTotal(){
    total = area * price;
}

void MainWindow::calculate(){

    setLength(ui->inputLength->text());
    setWidth(ui->inputWidth->text());

    calculateArea();
    calculateTotal();

    ui->outputResult->setText(QString::number(total));
}


