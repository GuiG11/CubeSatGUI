#ifndef WIDGET_H
#define WIDGET_H

#include "qcustomplot.h"

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QStringList>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QDateTime>
#include <QLCDNumber>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QLabel *label6;
    QLabel *label7;
    QLabel *label8;
    QLabel *label9;
    QLabel *label10;
    QLabel *label11;
    QLabel *label12;
    QLabel *label13;
    QLabel *label14;

    QList<double> values1;
    QList<double> values2;
    QList<double> values3;
    QList<double> values4;
    QList<double> values5;
    QList<double> values6;
    QList<double> values7;
    QList<double> values8;
    QList<double> values9;
    QList<double> values10;
    QList<double> values11;
    QList<double> values12;
    QList<double> values13;
    QList<double> values14;

    QPushButton *btnStart;
    QTimer *timer;

    QCustomPlot *altitudePlot;
    QCustomPlot *temperaturePlot;
    QCustomPlot *gyroscopePlot;

    QDateTime startTime;
    int elapsedTimeInSeconds;
    //QLabel *elapsedTimeLabel = new QLabel("Time Elapsed: 0 seconds", this);
    QLCDNumber *elapsedTimeLCD = new QLCDNumber(this);

    int currentIndex; // Index to iterate through values

public slots:
    void strt();
    void updateLabels();
    void updateElapsedTime();

};
#endif // WIDGET_H
