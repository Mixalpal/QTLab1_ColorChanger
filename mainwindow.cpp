#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLayout"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel("Text");
    QString stl = "color: rgb(%1,%2,%3); font-size: 40pt; font-weight:bold";
    QString stl2 = stl.arg(0).arg(0).arg(0);
    label->setStyleSheet(stl2);
    label->setAlignment(Qt::AlignCenter);

    sliderR = new QSlider(Qt::Horizontal);
    sliderR->setMinimum(0);
    sliderR->setMaximum(255);
    QObject::connect(sliderR,SIGNAL(sliderMoved(int)),this, SLOT(SliderMoved()));

    sliderG = new QSlider(Qt::Horizontal);
    sliderG->setMinimum(0);
    sliderG->setMaximum(255);
    QObject::connect(sliderG,SIGNAL(sliderMoved(int)),this, SLOT(SliderMoved()));

    sliderB = new QSlider(Qt::Horizontal);
    sliderB->setMinimum(0);
    sliderB->setMaximum(255);
    QObject::connect(sliderB,SIGNAL(sliderMoved(int)),this, SLOT(SliderMoved()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(sliderR);
    layout->addWidget(sliderG);
    layout->addWidget(sliderB);

    QWidget* wdg = new QWidget();
    wdg->setLayout(layout);
    this->setCentralWidget(wdg);
}

void MainWindow::SliderMoved()
{
    QString stl = "color: rgb(%1,%2,%3); font-size: 40pt; font-weight:bold";
    QString stl2 = stl.arg(sliderR->value()).arg(sliderG->value()).arg(sliderB->value());

    label->setStyleSheet(stl2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

