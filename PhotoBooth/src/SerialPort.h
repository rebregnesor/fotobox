#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QSerialPort>


class SerialPort : public QSerialPort
{
    Q_OBJECT
public:
    SerialPort();
private:
    QString serial_data;

signals:
    void start();
    void coin_inserted(double);

public slots:
    void read_serial();
};

#endif // SERIALPORT_H
