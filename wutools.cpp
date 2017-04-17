#include "wutools.h"
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QFileInfo>

WuTools::WuTools()
{

}

QString WuTools::readFile(QString path){
    QFile file(path);
    QString allStr="";
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return "";
    }
    QTextStream in(&file);
    in.setCodec("UTF-8");
    QString line = in.readLine();
    allStr+=line;
    while (!line.isNull()) {
        line = in.readLine();
        allStr+=line;
    }
    return allStr;
}

QJsonObject WuTools::getJsonObject(QString path){
    QString str=WuTools::readFile(path);
    return QJsonDocument::fromJson(str.toUtf8()).object();
}

bool WuTools::outputFile(QString path, QString content){
        QFileInfo fi=QFileInfo(path);
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return false;
        }
        QTextStream out(&file);
        out.setCodec("UTF-8");
        out<<content;
        file.close();
        return true;
}
