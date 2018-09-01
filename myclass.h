#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QString>

class MyClass:public QObject
{
    Q_OBJECT

public:
    MyClass(QString name);
public slots:
    void doWork();
signals:
    void send(int);
private:
    QString name;
};

#endif // MYCLASS_H
