#ifndef HELLOWORLD_H
#define HELLOWORLD_H

#include "helloworld_global.h"
#include "extraplugininterface.h"

class HELLOWORLD_EXPORT HelloWorld : public ExtraPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "abr.ExtraPluginInterface.HelloWorld"
                      FILE "helloworld.json")
    Q_INTERFACES(ExtraPluginInterface)

public:
    HelloWorld();
    ~HelloWorld();

    int functionMain(int argc, QStringList *args);

private:
};

#endif // HELLOWORLD_H
