#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  //Constructor.
  explicit MainWindow(QWidget *parent = 0);

  //Destructor.
  ~MainWindow();

public slots:
    /*Write the date+current time and
    the random value.*/
    void putData();
private slots:
  //Connect Button: Connect to the server.
  void on_ButtonConnect_clicked();

  //Disconnet Button: Disconnect from the server.
  void on_ButtonDisconnect_clicked();

  //Start Button: Run the program.
  void on_ButtonStart_clicked();

  //Stop Button: Stop the program.
  void on_ButtonStop_clicked();

  //Timer Event.
  void timerEvent(QTimerEvent *e);


private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  int temporizador;
};

#endif // MAINWINDOW_H
