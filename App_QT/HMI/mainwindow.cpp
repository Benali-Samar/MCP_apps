#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QAction>
#include <QTimer>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) //contsructer
    //: QMainWindow(parent)
    //, ui(new Ui::MainWindow) //new main window
{
    ui->setupUi(this); //open the window

    //Top

        /// Create a QWidget to hold the top content
        QWidget *topContainer = new QWidget(this);

        // Specify the position and size for the top container
        int topContainerX = 5;
        int topContainerY = 5;
        int topContainerWidth = 790;
        int topContainerHeight = 100;
        topContainer->setGeometry(topContainerX, topContainerY, topContainerWidth, topContainerHeight);

        // Create a QLabel for the gray rectangle at the top
        QLabel *topRectangle = new QLabel(topContainer);
        topRectangle->setAlignment(Qt::AlignCenter);
        topRectangle->setStyleSheet("background-color: lightgray; border-radius: 10px;");

        // Calculate the position to center the rectangle in the top container
        int topWidth = 900;
        int topHeight = 80;
        int topX = (topContainer->width() - topWidth) / 3;
        int topY = (topContainer->height() - topHeight) / 3;
        topRectangle->setGeometry(topX, topY, topWidth, topHeight);

        // Load the logo icon using QPixmap
        QPixmap logoIcon(":/new/icons/thales-logo.png");

        // Create a QLabel for the logo icon
        QLabel *logoLabel = new QLabel(topContainer);
        logoLabel->setPixmap(logoIcon);

        // Set the position and size for the logo label in the top container
        int logoWidth = 400;
        int logoHeight = 50;
        int logoX = 5;
        int logoY = 20;

        logoLabel->setGeometry(logoX, logoY, logoWidth, logoHeight);


        // Create a QLabel for displaying the time
        timeLabel = new QLabel(topContainer);
        timeLabel->setFont(QFont("Helvetica", 23, QFont::Bold));
        timeLabel->setAlignment(Qt::AlignCenter);


        // Position the time label in the center of the top rectangle
        int timeLabelWidth = 300;
        int timeLabelHeight = 50;
        int timeLabelX = (topRectangle->width() - timeLabelWidth) / 2.6;
        int timeLabelY = (topRectangle->height() - timeLabelHeight) / 2;
        timeLabel->setGeometry(timeLabelX, timeLabelY, timeLabelWidth, timeLabelHeight);
        timeLabel->setStyleSheet("color: gray;");
        //timeLabel->setVisible(true);

        //timeLabel->raise();
        // Create a QTimer to update the timeLabel with the current time
        timer = new QTimer(this);
        connect(timer,  SIGNAL(timeout()), this, SLOT(timeCheck()));

        timer->start(1000);


        // Load the bluetooth using QPixmap
        QPixmap bluetoothicon(":/new/icons/bluetooth.png");
        bluetoothicon = bluetoothicon.scaled( 40, 40, Qt::KeepAspectRatio);

        // Create a QLabel for the logo icon
        QLabel *bluetooth = new QLabel(topContainer);
        bluetooth->setPixmap(bluetoothicon);

        // Set the position and size for the bluetooth label in the top container
        int bluetoothWidth = bluetoothicon.width();
        int bleutoothHeight = bluetoothicon.height();
        int bluetoothX = 590;
        int bluetoothY = 30;

        bluetooth->setGeometry(bluetoothX, bluetoothY, bluetoothWidth, bleutoothHeight);



        // Load the ear icon using QPixmap
        QPixmap earicon(":/new/icons/ear.png");
        earicon = earicon.scaled( 40, 40, Qt::KeepAspectRatio);

        // Create a QLabel for the logo icon
        QLabel *ear = new QLabel(topContainer);
        ear->setPixmap(earicon);

        // Set the position and size for the ear label in the top container
        int earWidth = earicon.width();
        int earHeight = earicon.height();
        int earX = 630;
        int earY = 30;

        ear->setGeometry(earX, earY, earWidth, earHeight);


        // Load the flag icon using QPixmap
        QPixmap flagicon(":/new/icons/flag.png");
        flagicon = flagicon.scaled( 80, 80, Qt::KeepAspectRatio);

        // Create a QLabel for the logo icon
        QLabel *flag = new QLabel(topContainer);
        flag->setPixmap(flagicon);

        // Set the position and size for the ear label in the top container
        int flagWidth = flagicon.width();
        int flagHeight = flagicon.height();
        int flagX = 700;
        int flagY = 30;

        flag->setGeometry(flagX, flagY, flagWidth, flagHeight);



    //Center

        //Message

        // Create a QLabel for the message
        QLabel *label = new QLabel("<b> Bienvenue chez Parking </b>", this);
        label->setFont(QFont("Helvetica", 30, QFont::Bold));
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("color: grey;");

        // Position the label just below the time label
        int labelWidth = 650;
        int labelHeight = 180;
        label->setGeometry((this->width() - labelWidth) / 2, timeLabel->y() + timeLabelHeight, labelWidth, labelHeight);




    //Buttom

        // Create a QWidget to hold the bottom content
           QWidget *bottomContainer = new QWidget(this);
           bottomContainer->setGeometry(0, label->y() + labelHeight, this->width(), this->height() - (label->y() + labelHeight));

           // Create a QLabel for the gray rectangle at the bottom
           QLabel *bottomRectangle = new QLabel(bottomContainer);
           bottomRectangle->setAlignment(Qt::AlignCenter);
           bottomRectangle->setStyleSheet("background-color: lightgray; border-radius: 10px;");

           // Calculate the position to center the rectangle in the bottomContainer
           int bottomWidth = 600;
           int bottomHeight = 300;
           int bottomX = (bottomContainer->width() - bottomWidth) / 2;
           int bottomY = (bottomContainer->height() - bottomHeight) / 2;
           bottomRectangle->setGeometry(bottomX, bottomY, bottomWidth, bottomHeight);



           // Create a QLabel with an icon
           QLabel *label2 = new QLabel("", bottomRectangle);
           QPixmap icon(":/new/icons/payment.png");
           icon =icon.scaled(100, 200, Qt::KeepAspectRatio);
           label2->setPixmap(icon);

           // Specify the position for the payment icon
           int paymentIconX = 70;
           int paymentIconY = (bottomRectangle->height() - icon.height()) / 3;
           label2->setGeometry(paymentIconX, paymentIconY, icon.width(), icon.height());


           // Create another label inside the bottom rectangle
           QLabel *bottomLabel = new QLabel("<b>Présentez</b> ", bottomRectangle);
           bottomLabel->setFont(QFont("Helvetica", 26));
           bottomLabel->setAlignment(Qt::AlignCenter);
           bottomLabel->setStyleSheet("color: gray;");


           // Specify the position for the "Présentez" label
           int bottomLabelX = label2->x() + label2->width() + 10;
           int bottomLabelY = paymentIconY;
           bottomLabel->setGeometry(bottomLabelX, bottomLabelY, 200, 80);


           // Create another label inside the bottom rectangle
           QLabel *bottomLabel2 = new QLabel("votre carte bancaire ", bottomRectangle);
           bottomLabel2->setFont(QFont("Helvetica", 26));
           bottomLabel2->setAlignment(Qt::AlignCenter | Qt::AlignRight);
           bottomLabel2->setStyleSheet("color: gray;");


           // Specify the position for the "Votre carte Bancaire" label
           int bottomLabel2X = bottomLabelX;
           int bottomLabel2Y = bottomLabelY + bottomLabel->height();
           bottomLabel2->setGeometry(bottomLabel2X, bottomLabel2Y, 340, 50);



           // Create a horizontal layout to hold the icons

           QLabel *icon1 = new QLabel("", bottomRectangle);
           QPixmap pixmap2(":/new/icons/pay.png");
           pixmap2 = pixmap2.scaled(400, 400, Qt::KeepAspectRatio);
           icon1->setPixmap(pixmap2);

           QHBoxLayout *iconLayout = new QHBoxLayout(bottomRectangle);
           iconLayout->setAlignment(Qt::AlignBottom | Qt::AlignCenter);

           iconLayout->setContentsMargins(0,0,0,0);



           iconLayout->addWidget(icon1);

           bottomRectangle->setLayout(iconLayout);



}


// Define the timeCheck() slot here
void MainWindow::timeCheck() {
    // This is where you update your timeLabel with the current time
    timeLabel->setText(QTime::currentTime().toString("hh:mm"));
}

MainWindow::~MainWindow()
{
    delete ui; //delete the object
}


