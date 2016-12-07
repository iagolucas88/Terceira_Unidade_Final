
/******************Client data Producer**********************
 * * This program connect to the stated server by TCP/IP. * *
 ************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

//Constructor.
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  socket = new QTcpSocket(this);
}

/*Write the date+current time and
the random value.*/
void MainWindow::putData()
{
  //Max value specified by the max_slider.
  int Max = ui->Max_slider->value();
  //Max value specified by the max_slider.
  int Min = ui->Min_slider->value();

  QDateTime datetime;
  QString str;
  if(socket->state()== QAbstractSocket::ConnectedState){
      datetime = QDateTime::currentDateTime();
      str = "Set: "+
          datetime.toString(Qt::ISODate)+
          " '"+
          QString::number(qrand()%(Max-Min)+Min)+"'\r\n";

      qDebug() << str;
      qDebug() << socket->write(str.toStdString().c_str()) << " bytes written";
      if(socket->waitForBytesWritten(3000)){
        qDebug() << "wrote";
      }
  }
  //Write string str on the text browser.
  ui->textBrowser->append(str);
}

//Destructor.
MainWindow::~MainWindow()
{
  delete socket;
  delete ui;
}

//Connect Button: Connect to the server.
void MainWindow::on_ButtonConnect_clicked()
{
    QString statusC;

    //Connect to the host with specified ip and port.
    socket->connectToHost(ui->servidor->text(),1234);

    if(socket->waitForConnected(3000)){
        //Connect Staus showed on the text browser.
        statusC = "Connected.\n";
        qDebug() << "Connected.";
        ui->textBrowser->append(statusC);
    }

    else{
      qDebug() << "Disconnected.";
    }
}

//Disconnet Button: Disconnect from the server.
void MainWindow::on_ButtonDisconnect_clicked()
{
    //Disconnect Staus showed on the text browser.
    QString statusD;
    statusD = "Disconnected.\n";
    ui->textBrowser->append(statusD);

    socket->close();
}

//Start Button: Run the program.
void MainWindow::on_ButtonStart_clicked()
{
    //Program started showed on the text browser.
    QString statusR;
    statusR = "Started.\n";
    ui->textBrowser->append(statusR);

    //Start the data production.
    temporizador = startTimer((ui->Timing_box->value())*1000);
}

//Stop Button: Stop the program.
void MainWindow::on_ButtonStop_clicked()
{
    //Program stoped showed on the text browser.
    QString statusT;
    statusT = "Stoped.\n";
    ui->textBrowser->append(statusT);

    //Stop the data production.
    killTimer(temporizador);
}

//Timer Event.
void MainWindow::timerEvent(QTimerEvent *e)
{
    putData();
}
