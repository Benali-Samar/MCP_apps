#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT // tells qt indirectly we are going to use gui and widgets from headers

public:
    MainWindow(QWidget *parent = nullptr); //constructer
    ~MainWindow(); //distructer

private slots:
    void timeCheck();
private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QLabel *timeLabel;


};
#endif
