#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QLabel"
#include "QSlider"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
void SliderMoved();

private:
    Ui::MainWindow *ui;
    QLabel* label;
    QSlider* sliderR;
    QSlider* sliderG;
    QSlider* sliderB;
};
#endif // MAINWINDOW_H
