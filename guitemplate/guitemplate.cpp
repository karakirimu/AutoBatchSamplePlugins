#include "guitemplate.h"

GuiTemplate::GuiTemplate()
{
    PluginInformation pinfo;

    pinfo.name = "GUI Templete";
    pinfo.version = "1.00";
    pinfo.author = "author";
    pinfo.tooltip = "No arguments";

    // If it using QWidget, set it to true. otherwise false.
    pinfo.hassettingwidget = true;
    widget = new GuiTemplateWidget();
    pinfo.settingwidget = widget;

    setInformation(pinfo);
}

GuiTemplate::~GuiTemplate()
{
    delete widget;
}

int GuiTemplate::functionMain(int argc, QStringList *args)
{
    Q_UNUSED(argc)

    for(QString& arg : *args){
        functionMessage(arg, MessageType::Update);
    }

    functionMessage(tr("OK"), MessageType::Success);

    return 0;
}
