#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonObject>
#include <QJsonArray>
#include <QModelIndex>

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

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void ShowContextMenu(const QPoint&);

private:
    Ui::MainWindow *ui;

    QString missionPath;

    QJsonObject json;

    QJsonArray missionArray;
    QJsonArray completeArray;

    QModelIndex nowIndex;

    void removeMissionAt(int pos);
    void completeMissionAt(int pos);
    void editMissionAt(int pos);
    void setListWidgetMenu();
    void loadMission();
    void getMissonPath();
    void openMissonDialog();

};

#endif // MAINWINDOW_H
