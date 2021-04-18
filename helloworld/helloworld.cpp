#include "helloworld.h"

HelloWorld::HelloWorld()
{
    PluginInformation pinfo;

    pinfo.name = "Hello World";
    pinfo.version = "1.00";
    pinfo.author = "karakirimu";
    pinfo.tooltip = "Say Hello. No arguments.";

    // If it using QWidget, set it to true. otherwise false.
    pinfo.hassettingwidget = false;

    setInformation(pinfo);
}

HelloWorld::~HelloWorld()
{

}

int HelloWorld::functionMain(int argc, QStringList *args)
{
    Q_UNUSED(argc)
    functionMessage(tr("Hello world : Update"), MessageType::Update);

    if(args->count() == 0){
        functionMessage(tr("Hello world : Success"), MessageType::Success);
        return 0;
    }

    functionMessage(tr("Hello world : Error"), MessageType::Error);
    return -1;
}
