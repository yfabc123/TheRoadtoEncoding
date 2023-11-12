#include "tcpserverwindow.h"
#include "ui_tcpserverwindow.h"
#include <QTcpSocket>
#include <QString>
#include <QHostAddress>
TcpServerWindow::TcpServerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TcpServerWindow)
{
    ui->setupUi(this);
    tcpServer=new QTcpServer(this);
    connect(tcpServer,&QTcpServer::newConnection,this,&TcpServerWindow::acceptClientConnect);
}

TcpServerWindow::~TcpServerWindow()
{
    delete ui;
}


void TcpServerWindow::on_listenButton_clicked()
{
    QString port=ui->portLineEdit->text();
    if(port.isEmpty()){
        return;
    }
    if(!tcpServer->isListening()){
        bool ok=    tcpServer->listen(QHostAddress::Any,port.toUShort());//虽然参数填的是Any 客户端请求还是要填正确ip
        if(!ok){
            qDebug()<<"fail to listen port"<<port <<""<<tcpServer->errorString();
            return;
        }
    }


}

void TcpServerWindow::acceptClientConnect()
{
    qDebug()<<"有人连接服务器";
    QTcpSocket *tcpSocket=tcpServer->nextPendingConnection();

    // connect(tcpSocket,&QTcpSocket::readyRead,this,&TcpServerWindow::acceptClientData);
    connect(tcpSocket, &QTcpSocket::readyRead, this, [=]{acceptClientData(tcpSocket);});

}

void TcpServerWindow::acceptClientData(QTcpSocket *tcpSocket)
{
    QString peerIp=QHostAddress(tcpSocket->peerAddress().toIPv4Address()).toString() ;//得到客户端字符串ip
    QString peerPort=QString::number(tcpSocket->peerPort());
    QByteArray data=  tcpSocket->readAll();
    QString text="ip:"+peerIp+"port:"+peerPort+"内容:"+QString::fromLocal8Bit(data)+'\n';
    ui->textEdit->insertPlainText(text);
}

