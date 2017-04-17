#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonObject>
#include <QJsonArray>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addMisson(QStringList misson);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void openMissonDialog();
    QString missionPath;
    void loadMission();
    void getMissonPath();
    QJsonObject json;
    QJsonArray jsonArray;
};

#endif // MAINWINDOW_H
