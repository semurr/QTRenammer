#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dir = "/home";
    FileName = "temp";
    FileNumber = 0;
    lastOpenFile = "";
    ui->BSaveDir->setText(lastOpenFile);
    ui->BFileName->setText(FileName);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//When Add file is clicked Look for File Add to list
void MainWindow::on_Add_clicked()
{
    //opens up a dialog box to find a file.
    //sets the file path to path
    QStringList path = QFileDialog::getOpenFileNames(this, tr("Open File"), lastOpenFile, tr("Videos (*.mkv)"));

    if(path.count() >= 1)
    {
        ui->listWidget->addItems(path);
        lastOpenFile = path.at(0);

        if(ui->BSaveDir->text() == "")
        {
            ui->BSaveDir->setText(path.at(0));
        }
    }
}

//Button clicked Change, Change direcotry to save Dir file
void MainWindow::on_ChangeDir_clicked()
{
    //changes the director for the save file
    dir = QFileDialog::getExistingDirectory(this, tr("Save Location"), dir,
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks );
    if(dir != "")
    {
        ui->BSaveDir->setText(dir);
    }
}

//remove the current selected item in the list widget
void MainWindow::on_RemoveFile_clicked()
{
    delete ui->listWidget->currentItem();
    //ui->listWidget->removeItemWidget(Remove)

}

//move item up
void MainWindow::on_Up_clicked()
{
    //check if item is not at the top
    if(ui->listWidget->currentRow() != 0)
    {
        //moving the current selected item up the list
        ui->listWidget->insertItem(ui->listWidget->currentRow()-1, ui->listWidget->takeItem
                                   (ui->listWidget->currentRow()));

        //Move the selected item to follow the item
        ui->listWidget->setCurrentRow(ui->listWidget->currentRow()-2);
    }
}

void MainWindow::on_Down_clicked()
{
    //insert the item and a lower position
    ui->listWidget->insertItem(ui->listWidget->currentRow()+1, ui->listWidget->takeItem
                               (ui->listWidget->currentRow()));

    //moves the selected item to folow
    ui->listWidget->setCurrentRow(ui->listWidget->currentRow()+1);
}

//rename the file and move them to dir location
void MainWindow::on_Convert_clicked()
{
    //check if items in widget
    if(ui->listWidget->count() > 0)
    {
        //if the dir does not have a save location do nothing
        if(ui->BSaveDir->text() != "")
        {
            //for each item in the widget
            for(int i = 0; i < ui->listWidget->count(); i++)
            {
                //set the string to the text of the widget
                QString tempFileName = ui->listWidget->item(i)->text();

                //set the file to tempfile
                QFile tempFile(tempFileName);

                //should grab the last 4 digits in the string So should be the .avi etc
                QString extension = tempFileName.right(4);

                //need to create the the new name of the string
                ui->FNumber->setValue(ui->FNumber->value() + i);
                QString newName = ui->BFileName->text() + " - " + ui->FNumber->text() + extension;
                ui->FNumber->setValue(ui->FNumber->value() - i);

                //rename the file
                //tempFile.rename(ui->BSaveDir->text() + newName);
                tempFile.rename(ui->BSaveDir->text()+ '\\' + newName);

                //move the file to the location of selected in dir

            }
            ui->listWidget->clear();
            ui->Message->setText("Save Complete");
        }
        else
        {
            ui->Message->setText("Please Select a Save location");
        }
    }
    else
    {
        ui->Message->setText("No items side menu");
    }
}

//clear the  list
void MainWindow::on_ButtonClear_clicked()
{
    //grab the widget and clear it.
    ui->listWidget->clear();
    ui->Message->setText("");
}
