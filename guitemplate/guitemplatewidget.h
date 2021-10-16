#ifndef GUITEMPLATEWIDGET_H
#define GUITEMPLATEWIDGET_H

#include <QWidget>
#include <pluginwidget.h>

namespace Ui {
class GuiTemplateWidget;
}

class GuiTemplateWidget : public PluginWidget
{
    Q_OBJECT

public:
    explicit GuiTemplateWidget(QWidget *parent = nullptr);
    ~GuiTemplateWidget() override;

public slots:
    // This function receives the current setting
    // information from the main editor.
    void receiveList(QStringList args) override;

private slots:
    void countClicked();

private:    
    Ui::GuiTemplateWidget *ui;
};

#endif // GUITEMPLATEWIDGET_H
