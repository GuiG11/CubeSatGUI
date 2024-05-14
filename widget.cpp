#include "widget.h"
#include "qcustomplot.h"

#include <QLabel>
#include <QMovie>
#include <QPushButton>
#include <QMenu>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QString>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QGraphicsOpacityEffect>
#include <QDateTime>
#include <QLCDNumber>

Widget::Widget(QWidget *parent)
    : QWidget(parent), currentIndex(0)
{
    this->setStyleSheet("background-color: #1e1b18;");
    setWindowTitle("TelemXplorer");
    resize(1600,900);

    QColor Pine("#00414A");
    QColor Dark("#1e1b18");

    QLabel *logo = new QLabel(this);
    QPixmap logoPixmap(":/telemxlogo.png");
    int width = 250; // Desired width
    int height = 100; // Desired height
    logo->setPixmap(logoPixmap.scaled(width, height, Qt::KeepAspectRatio));
    logo->setGeometry(0, this->height()-height, width, height); // Adjust position and size as needed
    // Create opacity effect
    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(this);
    // Set opacity level (0.0 fully transparent, 1.0 fully opaque)
    opacityEffect->setOpacity(1); // Adjust opacity level as needed
    // Apply opacity effect to the logo label
    logo->setGraphicsEffect(opacityEffect);

    /* LABEL
    QLabel *label = new QLabel("This is label", this);
    label->setText("HELLO");
    label->move(100,100);
    label->setFont(QFont("Times",15));
    label->setStyleSheet("color: red");
    label->setGeometry(100,100,300,300);
    */

    /* IMAGE
    QLabel *label = new QLabel(this);
    label->setGeometry(20,20,400,400);
    label->setPixmap(QPixmap(":/images/IMG_1396.PNG"));
    */

    /* GIF
    QLabel *label = new QLabel(this);
    label->setGeometry(20,20,400,400);
    QMovie *movie = new QMovie(this);
    label->setMovie(movie);
    movie->start();
    */

    /* BUTTON
    QPushButton *button = new QPushButton(this);
    button->setText("START");
    button->setGeometry(350,400,100,100);
    button->setFont(QFont("Times",15));
    button->setIcon(QIcon(":/images/IMG_1396.PNG"));
    button->setIconSize(QSize(36,36));

    //add popup menu
    QMenu *menu = new QMenu();
    menu->setFont(QFont("Sanseriff",14));
    menu->setStyleSheet("background-color:yellow");
    menu->addAction("Copy");
    menu->addAction("Cut");
    menu->addAction("Paste");
    button->setMenu(menu);
    */

    /* LINEEDIT
    QLineEdit *lineEdit = new QLineEdit(this);
    lineEdit->setFont(QFont("Times",15));
    lineEdit->setStyleSheet("color: gray");
    lineEdit->setGeometry(20,20,250,50);
    //lineEdit->setEnabled(false);
    lineEdit->setEchoMode(QLineEdit::EchoMode::Password);
    */

    /* LAYOUT
    QPushButton *btn1 = new QPushButton(this);
    btn1->setText("click 1");

    QPushButton *btn2 = new QPushButton(this);
    btn1->setText("click 2");

    QPushButton *btn3 = new QPushButton(this);
    btn1->setText("click 3");

    QPushButton *btn4 = new QPushButton(this);
    btn1->setText("click 4");

    QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->addWidget(btn1);
    hbox->addWidget(btn2);
    hbox->addWidget(btn3);
    hbox->addWidget(btn4);
    */

    /* SIGNALS
    */

    // LABELS CONFIG

    // Create QVBoxLayout for the entire widget
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Create QGridLayout for the columns
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(20); // Reduced spacing for better fit
    gridLayout->setContentsMargins(50, 50, 50, 10);

    // Maximum width for labels
    int maxWidth = 200;

    // GPS Labels
    QLabel *gpsTitle = new QLabel("GPS", this);
    gpsTitle->setAlignment(Qt::AlignCenter);
    gpsTitle->setFont(QFont("Arial", 14, QFont::Bold));
    gridLayout->addWidget(gpsTitle, 0, 0, 1, 4); // Adjusted column span to 4

    label1 = new QLabel("Latitude: No Data", this);
    label1->setFixedWidth(maxWidth);
    gridLayout->addWidget(label1, 1, 0, Qt::AlignRight);

    label2 = new QLabel("Longitude: No Data", this);
    label2->setFixedWidth(maxWidth);
    gridLayout->addWidget(label2, 2, 0, Qt::AlignRight);

    label3 = new QLabel("Altitude: No Data", this);
    label3->setFixedWidth(maxWidth);
    gridLayout->addWidget(label3, 3, 0, Qt::AlignRight);

    // Accelerometer Labels
    QLabel *accelerometerTitle = new QLabel("Accelerometer", this);
    accelerometerTitle->setAlignment(Qt::AlignCenter);
    accelerometerTitle->setFont(QFont("Arial", 14, QFont::Bold));
    gridLayout->addWidget(accelerometerTitle, 0, 4, 1, 4); // Adjusted column span to 4

    label4 = new QLabel("AccelerationX: No Data", this);
    label4->setFixedWidth(maxWidth);
    gridLayout->addWidget(label4, 1, 4, Qt::AlignRight);

    label5 = new QLabel("AccelerationY: No Data", this);
    label5->setFixedWidth(maxWidth);
    gridLayout->addWidget(label5, 2, 4, Qt::AlignRight);

    label6 = new QLabel("AccelerationZ: No Data", this);
    label6->setFixedWidth(maxWidth);
    gridLayout->addWidget(label6, 3, 4, Qt::AlignRight);

    // Gyroscope Labels
    QLabel *gyroscopeTitle = new QLabel("Gyroscope", this);
    gyroscopeTitle->setAlignment(Qt::AlignCenter);
    gyroscopeTitle->setFont(QFont("Arial", 14, QFont::Bold));
    gridLayout->addWidget(gyroscopeTitle, 0, 8, 1, 4); // Adjusted column span to 4

    label7 = new QLabel("GyroX: No Data", this);
    label7->setFixedWidth(maxWidth);
    gridLayout->addWidget(label7, 1, 8, Qt::AlignRight);

    label8 = new QLabel("GyroY: No Data", this);
    label8->setFixedWidth(maxWidth);
    gridLayout->addWidget(label8, 2, 8, Qt::AlignRight);

    label9 = new QLabel("GyroZ: No Data", this);
    label9->setFixedWidth(maxWidth);
    gridLayout->addWidget(label9, 3, 8, Qt::AlignRight);

    label10 = new QLabel("Temperature1: No Data", this);
    label10->setFixedWidth(maxWidth);
    gridLayout->addWidget(label10, 4, 8, Qt::AlignRight);

    // BME Labels
    QLabel *bmeTitle = new QLabel("BME", this);
    bmeTitle->setAlignment(Qt::AlignCenter);
    bmeTitle->setFont(QFont("Arial", 14, QFont::Bold));
    gridLayout->addWidget(bmeTitle, 0, 12, 1, 4); // Adjusted column span to 4

    label11 = new QLabel("Temperature2: No Data", this);
    label11->setFixedWidth(maxWidth);
    gridLayout->addWidget(label11, 1, 12, Qt::AlignRight);

    label12 = new QLabel("Pressure: No Data", this);
    label12->setFixedWidth(maxWidth);
    gridLayout->addWidget(label12, 2, 12, Qt::AlignRight);

    label13 = new QLabel("Humidity: No Data", this);
    label13->setFixedWidth(maxWidth);
    gridLayout->addWidget(label13, 3, 12, Qt::AlignRight);

    label14 = new QLabel("Gas resistance: No Data", this);
    label14->setFixedWidth(maxWidth);
    gridLayout->addWidget(label14, 4, 12, Qt::AlignRight);

    // Add grid layout to main layout
    mainLayout->addLayout(gridLayout);

    // Set the color of the line
    QPen pen;
    pen.setColor(QColor(Qt::green)); // Change the color to any color you prefer
    pen.setWidth(2); // Set the width of the line

    // Create altitude plot
    altitudePlot = new QCustomPlot(this);
    altitudePlot->addGraph();
    altitudePlot->xAxis->setLabel("Time (s)");
    altitudePlot->yAxis->setLabel("Altitude (m)");
    // Set color of the plot
    altitudePlot->setBackground(QBrush(QColor(Dark))); // Change the color to any color you prefer
    altitudePlot->xAxis->setTickLabelColor(QColor(Qt::white)); // Set X-axis label color
    altitudePlot->yAxis->setTickLabelColor(QColor(Qt::white)); // Set Y-axis label color
    altitudePlot->xAxis->setBasePen(QPen(QColor(Qt::white))); // Set X-axis line color
    altitudePlot->yAxis->setBasePen(QPen(QColor(Qt::white))); // Set Y-axis line color
    altitudePlot->xAxis->setLabelColor(QColor(Qt::white)); // Set the color to #00414A
    altitudePlot->yAxis->setLabelColor(QColor(Qt::white)); // Set the color to #00414A
    altitudePlot->graph(0)->setPen(pen);
    // Set fixed height for altitude plot
    altitudePlot->setFixedHeight(400); // Adjust height as needed
    // Set fixed width for altitude plot
    altitudePlot->setFixedWidth(400); // Adjust height as needed
    // Allow altitude plot to expand vertically
    altitudePlot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    mainLayout->addWidget(altitudePlot);

    // Create altitude plot
    temperaturePlot = new QCustomPlot(this);
    temperaturePlot->addGraph();
    temperaturePlot->xAxis->setLabel("Time (s)");
    temperaturePlot->yAxis->setLabel("Temperature (ºC)");
    // Set color of the plot
    temperaturePlot->setBackground(QBrush(QColor(Dark))); // Change the color to any color you prefer
    temperaturePlot->xAxis->setTickLabelColor(QColor(Qt::white)); // Set X-axis label color
    temperaturePlot->yAxis->setTickLabelColor(QColor(Qt::white)); // Set Y-axis label color
    temperaturePlot->xAxis->setBasePen(QPen(QColor(Qt::white))); // Set X-axis line color
    temperaturePlot->yAxis->setBasePen(QPen(QColor(Qt::white))); // Set Y-axis line color
    temperaturePlot->xAxis->setLabelColor(QColor(Qt::white)); // Set the color to #00414A
    temperaturePlot->yAxis->setLabelColor(QColor(Qt::white)); // Set the color to #00414A
    temperaturePlot->graph(0)->setPen(pen);
    // Set fixed height for altitude plot
    temperaturePlot->setFixedHeight(400); // Adjust height as needed
    // Set fixed width for altitude plot
    temperaturePlot->setFixedWidth(400); // Adjust height as needed
    // Allow altitude plot to expand vertically
    temperaturePlot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);


    // Create a QHBoxLayout for the plots
    QHBoxLayout *plotLayout = new QHBoxLayout;
    // Add altitude plot to the plot layout
    plotLayout->addWidget(altitudePlot);
    // Add some spacing between the plots
    plotLayout->addSpacing(20);
    // Add temperature plot to the plot layout
    plotLayout->addWidget(temperaturePlot);

    // Add the plot layout to the main layout
    mainLayout->addLayout(plotLayout);

    // Create a spacer to take up remaining space in the layout
    QSpacerItem *spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    mainLayout->addSpacerItem(spacer);

    // Add altitude plot to layout
    //mainLayout->addWidget(altitudePlot);

    // Create QHBoxLayout for the button
    QHBoxLayout *buttonLayout = new QHBoxLayout;

    // Create the button
    QPushButton *btnStart = new QPushButton(this);
    btnStart->setText("START");
    btnStart->setFixedWidth(150);
    btnStart->setFixedHeight(75);
    btnStart->setFont(QFont("Times", 24));
    btnStart->setStyleSheet("background-color: green; color: white;");

    // Add stretching space before and after the button to center it horizontally
    buttonLayout->addStretch();
    buttonLayout->addWidget(btnStart);
    buttonLayout->addStretch();

    // Create a QLabel for displaying the elapsed time
    elapsedTimeLCD->setDigitCount(5); // Set the number of digits to accommodate the time format (MM:SS)
    elapsedTimeLCD->setSegmentStyle(QLCDNumber::Flat); // Set the segment style of the LCD
    elapsedTimeLCD->setFixedWidth(150);
    elapsedTimeLCD->setFixedHeight(75);

    buttonLayout->addWidget(elapsedTimeLCD);

    // Add the button layout to the main layout
    mainLayout->addLayout(buttonLayout);

    // Set layout for the widget
    setLayout(mainLayout);

    // Connect the button signal to the appropriate slot
    connect(btnStart, SIGNAL(clicked()), this, SLOT(strt()));

    // Declaration of variables
    startTime = QDateTime::currentDateTime();
    elapsedTimeInSeconds = 0;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateLabels()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateElapsedTime()));
    timer->stop();

}

Widget::~Widget()
{



}

void Widget::strt()
{
    // Record the start time
    startTime = QDateTime::currentDateTime();

    // Open the file for reading
    QFile file(":/data.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file";
        return;
    }

    // Clear the existing values lists
    values1.clear();
    values2.clear();
    values3.clear();
    values4.clear();
    values5.clear();
    values6.clear();
    values7.clear();
    values8.clear();
    values9.clear();
    values10.clear();
    values11.clear();
    values12.clear();
    values13.clear();
    values14.clear();

    // Read values from the file
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(","); // Split the line by comma
        if (parts.size() >= 14) {
            bool ok1, ok2, ok3, ok4, ok5, ok6, ok7, ok8, ok9, ok10, ok11, ok12, ok13, ok14;
             // Convert to double
            double value1 = parts[0].toDouble(&ok1);
            double value2 = parts[1].toDouble(&ok2);
            double value3 = parts[2].toDouble(&ok3);
            double value4 = parts[3].toDouble(&ok4);
            double value5 = parts[4].toDouble(&ok5);
            double value6 = parts[5].toDouble(&ok6);
            double value7 = parts[6].toDouble(&ok7);
            double value8 = parts[7].toDouble(&ok8);
            double value9 = parts[8].toDouble(&ok9);
            double value10 = parts[9].toDouble(&ok10);
            double value11 = parts[10].toDouble(&ok11);
            double value12 = parts[11].toDouble(&ok12);
            double value13 = parts[12].toDouble(&ok13);
            double value14 = parts[13].toDouble(&ok14);

            if (ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 && ok11 && ok12 && ok13 && ok14) {
                // Store values
                values1.append(value1);
                values2.append(value2);
                values3.append(value3);
                values4.append(value4);
                values5.append(value5);
                values6.append(value6);
                values7.append(value7);
                values8.append(value8);
                values9.append(value9);
                values10.append(value10);
                values11.append(value11);
                values12.append(value12);
                values13.append(value13);
                values14.append(value14);
            }
        }
    }
    file.close();

    // Start or stop the timer based on its current state
    if (timer->isActive()) {
        // If the timer is active, stop it
        timer->stop();
    } else {
        // If the timer is not active, start it
        timer->start(1000); // Update labels every 1000ms
    }
}

void Widget::updateLabels()
{
    // If there are no values in the list or we've reached the end, stop the timer
    if (values1.isEmpty() || currentIndex >= values1.size()) {
        timer->stop();
        return;
    }

    // Get the current values from the lists
    double value1 = values1.at(currentIndex);
    double value2 = values2.at(currentIndex);
    double value3 = values3.at(currentIndex);
    double value4 = values4.at(currentIndex);
    double value5 = values5.at(currentIndex);
    double value6 = values6.at(currentIndex);
    double value7 = values7.at(currentIndex);
    double value8 = values8.at(currentIndex);
    double value9 = values9.at(currentIndex);
    double value10 = values10.at(currentIndex);
    double value11 = values11.at(currentIndex);
    double value12 = values12.at(currentIndex);
    double value13 = values13.at(currentIndex);
    double value14 = values14.at(currentIndex);


    // Update labels with values
    label1->setText("Latitude:\t" + QString::number(value1));
    label2->setText("Longitude:\t" + QString::number(value2));
    label3->setText("Altitude:\t" + QString::number(value3));
    label4->setText("AccelerationX:\t" + QString::number(value4));
    label5->setText("AccelerationY:\t" + QString::number(value5));
    label6->setText("AccelerationZ:\t" + QString::number(value6));
    label7->setText("GyroX:\t" + QString::number(value7));
    label8->setText("GyroY:\t" + QString::number(value8));
    label9->setText("GyroZ:\t" + QString::number(value9));
    label10->setText("Temperature1:\t" + QString::number(value10));
    label11->setText("Temperature2:\t" + QString::number(value11));
    label12->setText("Pressure:\t" + QString::number(value12));
    label13->setText("Humidity:\t" + QString::number(value13));
    label14->setText("Gas Resistance:\t" + QString::number(value14));

    // Update altitude plot
    altitudePlot->graph(0)->addData(elapsedTimeInSeconds, value3);

    // Rescale the axes to fit the new data
    altitudePlot->rescaleAxes();
    altitudePlot->replot();

    // Update altitude plot
    temperaturePlot->graph(0)->addData(elapsedTimeInSeconds, value11);

    // Rescale the axes to fit the new data
    temperaturePlot->rescaleAxes();
    temperaturePlot->replot();

    // Move to the next index
    currentIndex++;
}

void Widget::updateElapsedTime()
{
    // Calculate the elapsed time in seconds
    elapsedTimeInSeconds = startTime.secsTo(QDateTime::currentDateTime());
    // Update the elapsed time label text
    //elapsedTimeLabel->setText(QString("Time Elapsed: %1 seconds").arg(elapsedTimeInSeconds));

    // Update the elapsed time in MM:SS format
    int minutes = elapsedTimeInSeconds / 60;
    int seconds = elapsedTimeInSeconds % 60;

    // Display the elapsed time in the LCD
    elapsedTimeLCD->display(QString("%1:%2").arg(minutes, 2, 10, QLatin1Char('0')).arg(seconds, 2, 10, QLatin1Char('0')));
}
