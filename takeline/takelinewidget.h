#ifndef TAKELINEWIDGET_H
#define TAKELINEWIDGET_H

#include <QHash>
#include <QWidget>
#include <pluginwidget.h>

namespace Ui {
class TakeLineWidget;
}

class TakeLineWidget : public PluginWidget
{
    Q_OBJECT

public:
    explicit TakeLineWidget(QWidget *parent = nullptr);
    ~TakeLineWidget() override;

public slots:
    void receiveList(QStringList args) override;

private slots:
    void on_plainTextEdit_textChanged();

    void on_removelineEdit_textChanged(const QString &arg1);

    void on_returnLineEdit_textChanged(const QString &arg1);

private:
    void updateArguments();

    Ui::TakeLineWidget *ui;

    enum TakeLineList{
        SourceOrString,
        RemoveLineNumber,
        LocalVariant
    };

    QHash<TakeLineList,QString> settingargs;
};

#endif // TAKELINEWIDGET_H
