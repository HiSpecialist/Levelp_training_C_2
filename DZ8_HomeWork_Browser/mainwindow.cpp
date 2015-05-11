#include <QDebug> // Вывод отладочных сообщений в консоль
#include <QMessageBox> // Вывод окон с сообщениями пользователю
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}


 // При нажатии на кнопку Go переходим на адрес
void MainWindow::on_goButton_clicked() {

  // если пользователь забыл указать протокол добавим в начало http
  if (!ui->urlEdit->text().startsWith("http://") && !ui->urlEdit->text().startsWith("https://")
      && !ui->urlEdit->text().startsWith("ftp://"))
  { ui->urlEdit->setText("http://" + ui ->urlEdit->text()); }

  // переходим на адрес
  ui->webView->setUrl(ui->urlEdit->text());


}

// Добавление адреса сайта в закладки
// при нажатии на кнопку избранное добавляем новую кнопку в панель истории
void MainWindow::on_toolButton_clicked() {
  toolbutton *button = new toolbutton(this);
  button->setText(ui->urlEdit->text());
  ui->historyTools->addWidget(button);
}

// Переход по кнопке из избранного
void MainWindow::on_historyTools_clicked() {

    toolbutton *button = (toolbutton *)QObject::sender();
    if(button == NULL){
            return;
    }

  QString url = button->text();
  ui->urlEdit->setText(url);
}

// Когда меняется URL в webView => меняем и URL в строке адреса
void MainWindow::on_webView_urlChanged(const QUrl& url) {
  ui->urlEdit->setText(url.toString());
}




