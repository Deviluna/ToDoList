#ifndef MISSIONDETAILDIALOG_H
#define MISSIONDETAILDIALOG_H

#include <QDialog>

namespace Ui {
class MissionDetailDialog;
}

class MissionDetailDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MissionDetailDialog(QWidget *parent = 0);
    ~MissionDetailDialog();
    void loadMission(QStringList strList);
    QString getTextValue();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MissionDetailDialog *ui;
};

#endif // MISSIONDETAILDIALOG_H
