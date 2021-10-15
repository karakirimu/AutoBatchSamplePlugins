#ifndef FILETEXTREPLACE_H
#define FILETEXTREPLACE_H

#include "filetextreplace_global.h"
#include "extraplugininterface.h"
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QRegularExpression>
#include <filetextreplacewidget.h>

class FILETEXTREPLACESHARED_EXPORT FileTextReplace
        : public ExtraPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "abr.ExtraPluginInterface.FileTextReplace"
                      FILE "filetextreplace.json")
    Q_INTERFACES(ExtraPluginInterface)

public:
    FileTextReplace();
    ~FileTextReplace() override;

    int functionMain(int argc, QStringList *args) override;

private:
    bool writeToText(QString filename, QString text);

    FileTextReplaceWidget *ftwidget;
};

#endif // FILETEXTREPLACE_H
