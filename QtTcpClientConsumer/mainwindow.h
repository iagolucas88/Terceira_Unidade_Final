#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  //Constructor
  explicit MainWindow(QWidget *parent = 0);
  //Destructor.
  ~MainWindow();

private slots:
  //Set connect button.
  void on_connect_button_clicked();

  //Set disconnect button.
  void on_disconnect_button_clicked();

  //Set update button.
  void on_update_button_clicked();

  //Set start button.
  void on_start_button_clicked();

  //Set stop button.
  void on_stop_button_clicked();

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
