#include "sleep.h"

Sleep::Sleep()
{
    PluginInformation pinfo;
    pinfo.name = "Sleep";
    pinfo.version = "1.00";
    pinfo.author = "karakirimu";
    pinfo.tooltip = "";
    pinfo.hassettingwidget = true;

    //Create new widget
    swidget = new SleepWidget();
    pinfo.settingwidget = swidget;

    setInformation(pinfo);
}

Sleep::~Sleep()
{
    delete swidget;
}

int Sleep::functionMain(int argc, QStringList *args)
{
    if(argc < 1){
        functionMessage(tr("The argument is missing."), MessageType::Error);
        return -1;
    }

    int time = (args->at(0)).toInt();

    QEventLoop loop;
    QTimer::singleShot( time, &loop, SLOT(quit()));
    loop.exec();

    return 0;
}
