#include "SerialPort.h"
#include <QSerialPortInfo>
#include <QDebug>
using namespace std;

SerialPort::SerialPort()
{

    bool arduino_is_available = false;
    QString arduino_uno_port_name;

    /*qDebug() << "Number of ports: " << QSerialPortInfo::availablePorts().length() << "\n";
        foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
            qDebug() << "Description: " << serialPortInfo.description() << "\n";
            qDebug() << "Has vendor id?: " << serialPortInfo.hasVendorIdentifier() << "\n";
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier() << "\n";
            qDebug() << "Has product id?: " << serialPortInfo.hasProductIdentifier() << "\n";
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier() << "\n";
        }
*/

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
            //  check if the serialport has both a product identifier and a vendor identifier
            if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
                //  check if the product ID and the vendor ID match those of the arduino uno
                if((serialPortInfo.productIdentifier() == 67)
                        && (serialPortInfo.vendorIdentifier() == 10755)){
                    arduino_is_available = true; //    arduino uno is available on this port
                    arduino_uno_port_name = serialPortInfo.portName();
                }
            }
        }
    if(arduino_is_available){
            setPortName(arduino_uno_port_name);
            open(QSerialPort::ReadOnly);
            setBaudRate(QSerialPort::Baud9600);
            setDataBits(QSerialPort::Data8);
            setFlowControl(QSerialPort::NoFlowControl);
            setParity(QSerialPort::NoParity);
            setStopBits(QSerialPort::OneStop);
            connect(this, SIGNAL(readyRead()), this, SLOT(read_serial()));
        }else{
            qDebug() << "Couldn't find the correct port for the arduino.\n";
        }
}

void SerialPort::read_serial() {

    QString new_data(readLine().data());
    serial_data.append(new_data);

    if (serial_data.endsWith("\n")) { //check if full line is transmitted
        serial_data.chop(2); //take away line break at the end
        if (serial_data.compare(QString("s"))==0) { //if "s", the button was pressed -->start signal
            emit start();
        } else { //otherwise a coin value is transmitted-->coin signal
            emit coin_inserted(serial_data.toDouble()/100);
        }
        serial_data.clear();
    }
}

