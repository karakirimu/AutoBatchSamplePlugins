#ifndef SLEEP_H
#define SLEEP_H

#include "sleep_global.h"
#include "sleepwidget.h"
#include "../plugininterface/extraplugininterface.h"
#include <QEventLoop>
#include <QTimer>

class SLEEPSHARED_EXPORT Sleep
        : public ExtraPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "abr.ExtraPluginInterface.Sleep"
                      FILE "sleep.json")
    Q_INTERFACES(ExtraPluginInterface)

public:
    Sleep();
    ~Sleep() override;

     int functionMain(int argc, QStringList *args) override;

private:
     SleepWidget* swidget;
};

#endif // SLEEP_H
