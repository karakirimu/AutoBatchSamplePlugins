#include "clitemplete.h"

CliTemplete::CliTemplete()
{
    PluginInformation pinfo;

    pinfo.name = "CLI Templete";
    pinfo.version = "1.00";
    pinfo.author = "author";
    pinfo.tooltip = "No arguments";

    // If it using QWidget, set it to true. otherwise false.
    pinfo.hassettingwidget = false;

    setInformation(pinfo);
}

CliTemplete::~CliTemplete()
{

}

int CliTemplete::functionMain(int argc, QStringList *args)
{
    Q_UNUSED(argc)
    Q_UNUSED(args)
    functionMessage(tr("OK"), MessageType::Success);

    return 0;
}
