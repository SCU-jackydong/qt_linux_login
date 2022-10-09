#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<QtNetwork>
#include<QHostInfo>
#include<QTcpSocket>
#include<QTcpServer>

using namespace std;
MainWindow::MainWindow(QWidget *parent)

    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{


   QString account = ui->lineEdit->text();
   QString password=ui->lineEdit_2->text();
    cout<<account.toStdString()<<endl;





   QByteArray dataArray ;
   QString name1 = "account="+account+"&"+"password="+password;
   dataArray.append(name1);
    QUrl url("http://10.0.0.222:8080/login");
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");

   QNetworkAccessManager* manager = new QNetworkAccessManager(this);

 QNetworkReply *reply = manager->post(request,dataArray);


}
