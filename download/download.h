#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include "download_global.h"
#include "downloadwidget.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "extraplugininterface.h"

#ifdef OPENSSL_DEFINED
#include <openssl/aes.h>
#endif

class DOWNLOAD_EXPORT Download : public ExtraPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "abr.ExtraPluginInterface.Download"
                      FILE "download.json")
    Q_INTERFACES(ExtraPluginInterface)

public:
    Download();
    ~Download() override;

    // 'functionMain' is called from plugin execution process.
    int functionMain(int argc, QStringList *args) override;

private:
    bool downloadFromFile(QString file, QString outputfolder);
    bool downloadFromUrl(QString url, QString outputfolder);

    DownloadWidget *widget;
    QNetworkAccessManager networkManager;
};

#endif // DOWNLOAD_H
