#ifndef SLEEPWIDGET_H
#define SLEEPWIDGET_H

#include "../plugininterface/pluginwidget.h"

namespace Ui {
class SleepWidget;
}

class SleepWidget : public PluginWidget
{
    Q_OBJECT

public:
    explicit SleepWidget(QWidget *parent = nullptr);
    ~SleepWidget() override;

public slots:
    void receiveList(QStringList args) override;

private slots:
    void on_timerLineEdit_textChanged(const QString &arg1);

private:
    Ui::SleepWidget *ui;
};

#endif // SLEEPWIDGET_H
