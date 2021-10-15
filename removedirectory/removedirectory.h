#ifndef REMOVEDIRECTORY_H
#define REMOVEDIRECTORY_H

#include "removedirectory_global.h"
#include "removedirectorywidget.h"
#include "extraplugininterface.h"
#include <QFile>
#include <QDir>
#include <QPoint>
#include <QFileInfo>
#include <QDirIterator>

class REMOVEDIRECTORYSHARED_EXPORT RemoveDirectory
        : public ExtraPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "abr.ExtraPluginInterface.RemoveDirectory"
                      FILE "removedirectory.json")
    Q_INTERFACES(ExtraPluginInterface)

public:
    RemoveDirectory();
    ~RemoveDirectory() override;

    int functionMain(int argc, QStringList *args) override;

private:
    RemoveDirectoryWidget *swidget;

};

#endif // REMOVEDIRECTORY_H
