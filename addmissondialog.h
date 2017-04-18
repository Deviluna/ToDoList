#ifndef ADDMISSONDIALOG_H
#define ADDMISSONDIALOG_H

#include <QDialog>

namespace Ui {
class AddMissonDialog;
}

class AddMissonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddMissonDialog(QWidget *parent = 0);
    ~AddMissonDialog();


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddMissonDialog *ui;
    bool addMission();
};

#endif // ADDMISSONDIALOG_H
