#ifndef CLITEMPLETE_H
#define CLITEMPLETE_H

#include "clitemplete_global.h"
#include "extraplugininterface.h"

class CLITEMPLETE_EXPORT CliTemplete
    : public ExtraPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "abr.ExtraPluginInterface.CliTemplete"
                      FILE "clitemplete.json")
    Q_INTERFACES(ExtraPluginInterface)
public:
    CliTemplete();
    ~CliTemplete() override;

    int functionMain(int argc, QStringList *args) override;
private:
};

#endif // CLITEMPLETE_H
