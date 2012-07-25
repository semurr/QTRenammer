#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_Add_clicked();

    void on_ChangeDir_clicked();

    void on_RemoveFile_clicked();

    void on_Up_clicked();

    void on_Down_clicked();

    void on_Convert_clicked();

    void on_ButtonClear_clicked();

private:
    Ui::MainWindow *ui;
    QString dir;
    QString FileName;
    int FileNumber;
    QString lastOpenFile;
};

#endif // MAINWINDOW_H
