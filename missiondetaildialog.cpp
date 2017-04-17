#include "missiondetaildialog.h"
#include "ui_missiondetaildialog.h"

MissionDetailDialog::MissionDetailDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MissionDetailDialog)
{
    ui->setupUi(this);
}

MissionDetailDialog::~MissionDetailDialog()
{
    delete ui;
}

void MissionDetailDialog::on_pushButton_clicked()
{

    QDialog::accept();

}

void MissionDetailDialog::loadMission(QStringList strList){
    ui->label->setText(strList[0]);
    ui->textBrowser->setText(strList[1]);
}
