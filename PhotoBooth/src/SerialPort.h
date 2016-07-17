#ifndef SERIALPORT_H
#define SERIALPORT_H

/**

  This class allows communication with the arduino via the Serial port

  **/

#include <QSerialPort>


class SerialPort : public QSerialPort
{
    Q_OBJECT
public:
    SerialPort();
private:
    QString serial_data;

signals:
    void start(); //button-was-pressed-signal
    void coin_inserted(double); //coin-was-inserted-signal

public slots:
    void read_serial(); //decodes the serial signal
};

#endif // SERIALPORT_H
