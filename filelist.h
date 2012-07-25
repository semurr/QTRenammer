#ifndef FILELIST_H
#define FILELIST_H
#include <QList>
#include <QString>
#include <QFile>

class FileList
{
public:
    QList<QString> List;

    FileList();
    void addFile();
    void removeFile();
    void MoveUp();
    void MoveDown();
};

#endif // FILELIST_H
