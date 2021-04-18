#ifndef MAKEDIRECTORY_H
#define MAKEDIRECTORY_H

#include "makedirectory_global.h"
#include "../plugininterface/extraplugininterface.h"
#include <QFile>
#include <QDir>
#include <QPoint>
#include <QFileInfo>

class MAKEDIRECTORYSHARED_EXPORT MakeDirectory
        : public ExtraPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "abr.ExtraPluginInterface.MakeDirectory"
                      FILE "makedirectory.json")
    Q_INTERFACES(ExtraPluginInterface)

public:
    MakeDirectory();
    ~MakeDirectory() override;

    int functionMain(int argc, QStringList *args) override;

};

#endif // MAKEDIRECTORY_H
