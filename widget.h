#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:


    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();


    void clock();

    void on_pushButton_11_clicked();

private:
    Ui::Widget *ui;
    QString newsText;
    QString weatherText;
    QTimer *timer;
    int tempGUI;
    int humidGUI;
    int presGUI;
};

#endif // WIDGET_H
