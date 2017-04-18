#include "addmissondialog.h"
#include "ui_addmissondialog.h"
#include <QString>
#include <QStringList>
#include <mainwindow.h>

AddMissonDialog::AddMissonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMissonDialog)
{
    ui->setupUi(this);
}

AddMissonDialog::~AddMissonDialog()
{
    delete ui;
}

void AddMissonDialog::on_pushButton_2_clicked()
{
    close();
}

void AddMissonDialog::on_pushButton_clicked()
{
    addMission();
}

bool AddMissonDialog::addMission(){
    QString missionName=ui->lineEdit->text();
    QString missionDetail=ui->textEdit->toPlainText();
    QStringList mission;
    mission<<missionName<<missionDetail;
    MainWindow *mw=(MainWindow *)parentWidget();
    mw->addMisson(mission);
    close();
    return true;
}


