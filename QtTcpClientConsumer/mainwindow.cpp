#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include "dialog.h"


//Constructor
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow){
  ui->setupUi(this);

  //Connect to plot posx.
  connect(ui->widgetPlotter,
          SIGNAL(posx(int)),
          //ui->DateTime_value_label,
          SLOT(display(int)));

  //Connect to plot posy.
  connect(ui->widgetPlotter,
          SIGNAL(posy(int)),
          //ui->Value_num_Label,
          SLOT(display(int)));

}

//Destructor.
MainWindow::~MainWindow()
{
  delete ui;
}

//Set connect button.
void MainWindow::on_connect_button_clicked()
{
   //Write connected status on text browser.
   QString statusC, ip;
   ip = ui->ip_lineEdit->text();
   statusC = "Connected to IP:";
   ui->textBrowser->append(statusC);
   ui->textBrowser->append(ip);
}

//Set disconnect button.
void MainWindow::on_disconnect_button_clicked()
{
    //Write disconnected status on text browser.
    QString statusD;
    statusD = "Disconnected.";
    ui->textBrowser->append(statusD);

}

//Set update button.
void MainWindow::on_update_button_clicked()
{
    //Write updated status on text browser.
    QString statusU;
    statusU = "Updated.";
    ui->textBrowser->append(statusU);
}

//Set start button.
void MainWindow::on_start_button_clicked()
{
    //Write started status on text browser.
    QString statusS;
    statusS = "Started.";
    ui->textBrowser->append(statusS);
}

//Set stop button.
void MainWindow::on_stop_button_clicked()
{
    //Write stoped status on text browser.
    QString statusST;
    statusST = "Stoped.";
    ui->textBrowser->append(statusST);

}
