#ifndef TAKELINE_H
#define TAKELINE_H

#include "takeline_global.h"
#include "takelinewidget.h"
#include "extraplugininterface.h"

#include <QFile>
#include <QTextStream>

class TAKELINESHARED_EXPORT TakeLine
        : public ExtraPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "abr.ExtraPluginInterface.TakeLine"
                      FILE "takeline.json")
    Q_INTERFACES(ExtraPluginInterface)

public:
    TakeLine();
    ~TakeLine() override;

    int functionMain(int argc, QStringList *args) override;

private:
    enum {FILEORSTRING, LINENUM, VAR};
    TakeLineWidget *tlwidget;
};

#endif // TAKELINE_H
