#ifndef WUTOOLS_H
#define WUTOOLS_H
#include <QString>
#include <QJsonObject>

class WuTools
{
public:
    WuTools();
    static QString readFile(QString path);
    static QJsonObject getJsonObject(QString path);
    static bool outputFile(QString path,QString content);

};

#endif // WUTOOLS_H
