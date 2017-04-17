#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <addmissondialog.h>
#include <QDir>
#include <qdebug.h>
#include <wutools.h>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <wutools.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    getMissonPath();
    loadMission();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::getMissonPath(){
    QDir qdir;
    missionPath=qdir.absolutePath()+"/data.wu";
}

void MainWindow::on_pushButton_clicked()
{
    openMissonDialog();
}
void MainWindow::loadMission(){
    ui->listWidget->clear();
    json=WuTools::getJsonObject(missionPath);
    jsonArray=json.value("missions").toArray();
    qDebug()<<jsonArray;
    for(int i=0;i<jsonArray.size();i++){
        QJsonObject lsJson=jsonArray.at(i).toObject();
        ui->listWidget->addItem(lsJson.value("name").toString());
    }
}

void MainWindow::openMissonDialog(){
    AddMissonDialog *amd=new AddMissonDialog(this);
    amd->exec();
}

void MainWindow::addMisson(QStringList mission){
    QJsonObject newJson;
    newJson.insert("name",mission[0]);
    newJson.insert("detail",mission[1]);
    jsonArray.push_back(newJson);
    json.remove("missions");
    json.insert("missions",jsonArray);
    WuTools::outputFile(missionPath,QJsonDocument(json).toJson());
    loadMission();
}

