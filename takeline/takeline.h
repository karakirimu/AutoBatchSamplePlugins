#ifndef TAKELINEPLUGIN_H
#define TAKELINEPLUGIN_H

#include "takeline_global.h"
#include "takelinewidget.h"
#include "../plugininterface/extraplugininterface.h"

#include <QFile>
#include <QTextStream>

class TAKELINEPLUGINSHARED_EXPORT TakeLinePlugin
        : public ExtraPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "abr.ExtraPluginInterface.TakeLinePlugin"
                      FILE "takelineplugin.json")
    Q_INTERFACES(ExtraPluginInterface)

public:
    TakeLinePlugin();
    ~TakeLinePlugin() override;

    int functionMain(int argc, QStringList *args) override;

private:
    enum {FILEORSTRING, LINENUM, VAR};
    TakeLineWidget *tlwidget;
};

#endif // TAKELINEPLUGIN_H
