#ifndef GUITEMPLETE_H
#define GUITEMPLETE_H

#include "guitemplete_global.h"
#include "extraplugininterface.h"
#include "guitempletewidget.h"

class GUITEMPLETE_EXPORT GuiTemplete
    : public ExtraPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "abr.ExtraPluginInterface.GuiTemplete"
                      FILE "guitemplete.json")
    Q_INTERFACES(ExtraPluginInterface)
public:
    GuiTemplete();
    ~GuiTemplete() override;

    int functionMain(int argc, QStringList *args) override;
private:

    GuiTempleteWidget *widget;
};

#endif // GUITEMPLETE_H
