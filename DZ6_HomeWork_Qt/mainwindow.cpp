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

void MainWindow::on_downButton_clicked() {
  ui->textEdit->append("Down");

  //ui->textEdit->geometry().translate(0, 10); так работать не будет
  QRect rect = ui->textEdit->geometry();
  rect.translate(0,ui->speedValue->value());
  ui->textEdit->setGeometry(rect);
}

void MainWindow::on_rightButton_clicked() {
  ui->textEdit->append("Right");

  QRect rect = ui->textEdit->geometry();
  rect.translate(ui->speedValue->value(), 0);
  ui->textEdit->setGeometry(rect);
}

void MainWindow::on_leftButton_clicked() {
  ui->textEdit->append("Left");

  QRect rect = ui->textEdit->geometry();
  rect.translate(-ui->speedValue->value(), 0);
  ui->textEdit->setGeometry(rect);
}

void MainWindow::on_upButton_clicked() {
  ui->textEdit->append("Up");

  QRect rect = ui->textEdit->geometry();
  rect.translate(0, -ui->speedValue->value());
  ui->textEdit->setGeometry(rect);
}
