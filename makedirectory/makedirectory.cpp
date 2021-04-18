#include "makedirectory.h"

MakeDirectory::MakeDirectory()
{
    PluginInformation pinfo;
    pinfo.name = "MakeDirectory";
    pinfo.version = "1.00";
    pinfo.author = "karakirimu";
    pinfo.tooltip = "Create all the directories needed for the folder path.\n"
                    "argument 1 : The folder path you want to create";
    pinfo.hassettingwidget = false;

    setInformation(pinfo);
}

MakeDirectory::~MakeDirectory()
{

}

int MakeDirectory::functionMain(int argc, QStringList *args)
{
    if(argc < 1){
        functionMessage(tr("The argument is missing."), MessageType::Error);
        return -1;
    }

    bool dirbool;
    QDir dir;
    dirbool = dir.mkpath(args->at(0));

    return dirbool ? 0 : -1;
}
