#include "guitemplete.h"

GuiTemplete::GuiTemplete()
{
    PluginInformation pinfo;

    pinfo.name = "GUI Templete";
    pinfo.version = "1.00";
    pinfo.author = "author";
    pinfo.tooltip = "No arguments";

    // If it using QWidget, set it to true. otherwise false.
    pinfo.hassettingwidget = true;
    widget = new GuiTempleteWidget();
    pinfo.settingwidget = widget;

    setInformation(pinfo);
}

GuiTemplete::~GuiTemplete()
{
    delete widget;
}

int GuiTemplete::functionMain(int argc, QStringList *args)
{
    Q_UNUSED(argc)

    for(QString& arg : *args){
        functionMessage(arg, MessageType::Update);
    }

    functionMessage(tr("OK"), MessageType::Success);

    return 0;
}
