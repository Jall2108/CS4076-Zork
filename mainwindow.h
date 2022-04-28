#include "ZorkUL.h"
#ifndef MAINWINDOW_H
#define MAINWINDOW_H1
#include <QMainWindow>
using std::string;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_label_linkActivated(const QString &link);





    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;

    ZorkUL *zork;

};
#endif // MAINWINDOW_H
