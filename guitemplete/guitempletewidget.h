#ifndef GUITEMPLETEWIDGET_H
#define GUITEMPLETEWIDGET_H

#include <QWidget>
#include <pluginwidget.h>

namespace Ui {
class GuiTempleteWidget;
}

class GuiTempleteWidget : public PluginWidget
{
    Q_OBJECT

public:
    explicit GuiTempleteWidget(QWidget *parent = nullptr);
    ~GuiTempleteWidget() override;

public slots:
    // This function receives the current setting
    // information from the main editor.
    void receiveList(QStringList args) override;

private slots:
    void countClicked();

private:    
    Ui::GuiTempleteWidget *ui;
};

#endif // GUITEMPLETEWIDGET_H
