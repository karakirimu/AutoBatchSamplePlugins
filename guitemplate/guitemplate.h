#ifndef GUITEMPLATE_H
#define GUITEMPLATE_H

#include "guitemplate_global.h"
#include "extraplugininterface.h"
#include "guitemplatewidget.h"

class GUITEMPLATE_EXPORT GuiTemplate
    : public ExtraPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "abr.ExtraPluginInterface.GuiTemplate"
                      FILE "guitemplate.json")
    Q_INTERFACES(ExtraPluginInterface)
public:
    GuiTemplate();
    ~GuiTemplate() override;

    int functionMain(int argc, QStringList *args) override;
private:

    GuiTemplateWidget *widget;
};

#endif // GUITEMPLATE_H
