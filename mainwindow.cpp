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
#include <missiondetaildialog.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("ToDoList");
    //setWindowFlags(Qt::FramelessWindowHint);
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
    missionArray=json.value("missions").toArray();
    for(int i=0;i<missionArray.size();i++){
        QJsonObject lsJson=missionArray.at(i).toObject();
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
    missionArray.push_back(newJson);
    json.insert("missions",missionArray);
    WuTools::outputFile(missionPath,QJsonDocument(json).toJson());
    loadMission();
}


void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    MissionDetailDialog *mdd=new MissionDetailDialog(this);
    QStringList strList;
    strList<<missionArray.at(index.row()).toObject().value("name").toString();
    strList<<missionArray.at(index.row()).toObject().value("detail").toString();
    mdd->loadMission(strList);
    if(mdd->exec()){
    completeMissionAt(index.row());
    }
}

void MainWindow::removeMissionAt(int pos){f
    missionArray.removeAt(pos);
    ui->listWidget->takeItem(pos);
    json.insert("missions",missionArray);
    WuTools::outputFile(missionPath,QJsonDocument(json).toJson());
}

void MainWindow::completeMissionAt(int pos){
    QJsonObject missionInfo=missionArray.at(pos).toObject();
    completeArray.push_back(missionInfo);
    json.insert("complete",completeArray);
    removeMissionAt(pos);
}


