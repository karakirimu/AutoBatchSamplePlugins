#ifndef CLITEMPLATE_H
#define CLITEMPLATE_H

#include "clitemplate_global.h"
#include "extraplugininterface.h"

class CLITEMPLATE_EXPORT CliTemplate
    : public ExtraPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "abr.ExtraPluginInterface.CliTemplate"
                      FILE "clitemplate.json")
    Q_INTERFACES(ExtraPluginInterface)
public:
    CliTemplate();
    ~CliTemplate() override;

    int functionMain(int argc, QStringList *args) override;
private:
};

#endif // CLITEMPLATE_H
