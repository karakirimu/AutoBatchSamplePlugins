#include "removedirectory.h"

RemoveDirectory::RemoveDirectory()
{
    PluginInformation pinfo;
    pinfo.name = "RemoveDirectory";
    pinfo.version = "1.00";
    pinfo.author = "karakirimu";
    pinfo.tooltip = "argument 1 : The folder path you want to remove\n"
                    "argument 2 : Whether to delete files in folder (-rf)";
    pinfo.hassettingwidget = true;

    //Create new widget
    swidget = new RemoveDirectoryWidget();
    pinfo.settingwidget = swidget;

    setInformation(pinfo);
}

RemoveDirectory::~RemoveDirectory()
{
    delete swidget;
}

int RemoveDirectory::functionMain(int argc, QStringList *args)
{
    if(argc < 1){
        functionMessage(tr("The argument is missing."), MessageType::Error);
        return -1;
    }

    bool dirbool;

    QFileInfo info(args->at(0));

    if(!(info.exists() && info.isDir())){
        functionMessage(tr("Input folder does not exist."), MessageType::Error);
        return -1;
    }

    QDir dir(info.absoluteFilePath());

    if(argc == 2 && args->at(1) == "-rf"){
        QDirIterator dit(dir.path(), QStringList() << "*", QDir::Files | QDir::NoSymLinks);

        while (dit.hasNext()){
            QFile::remove(dit.next());
        }
    }

    functionMessage("Input : " + info.absoluteFilePath(), MessageType::Update);

    QDir dir2;

    dirbool = dir2.rmdir(info.absoluteFilePath());

    return dirbool ? 0 : -1;
}
