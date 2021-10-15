#ifndef BUFFEREDCOPY_H
#define BUFFEREDCOPY_H

#include "bufferedcopy_global.h"
#include "extraplugininterface.h"
#include "settingwidget.h"
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QCryptographicHash>

class BUFFEREDCOPYSHARED_EXPORT BufferedCopy
        : public ExtraPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "abr.ExtraPluginInterface.BufferedCopy" FILE "bufferedcopy.json")
    Q_INTERFACES(ExtraPluginInterface)

public:
    BufferedCopy();
    ~BufferedCopy() override;

    int functionMain(int argc, QStringList *args) override;

private:
    bool copyData(QString source, QString dest, long cachesize);
    bool checkHash(QString source, QString dest);

    QByteArray sha1Hash(QString file);

    SettingWidget* swidget;
};

#endif // BUFFEREDCOPY_H
