#ifndef TCPSERVERWINDOW_H
#define TCPSERVERWINDOW_H

#include <QMainWindow>
#include <QTcpServer>

QT_BEGIN_NAMESPACE
namespace Ui { class TcpServerWindow; }
QT_END_NAMESPACE

class TcpServerWindow : public QMainWindow
{
    Q_OBJECT

public:
    TcpServerWindow(QWidget *parent = nullptr);
    ~TcpServerWindow();

private slots:
    void on_listenButton_clicked();
    void acceptClientConnect();
    void acceptClientData( QTcpSocket *tcpSocket);
private:
    Ui::TcpServerWindow *ui;
    QTcpServer *tcpServer;
};
#endif // TCPSERVERWINDOW_H
